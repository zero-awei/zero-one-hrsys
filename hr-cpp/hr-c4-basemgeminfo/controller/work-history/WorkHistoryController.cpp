#include "stdafx.h"
#include "WorkHistoryController.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"
#include "service/work-history/WorkHistoryService.h"
#include "WorkHistoryController.h"
#include "domain/dto/work-history/WorkHistoryIntoDTO.h"
#include "uselib/rocketmq/TestRocket.h"
#include "../Router.h"


WorkHistoryFindVO::Wrapper WorkHistoryController::execQueryPageWorkHistory(const WorkHistoryPageQuery::Wrapper& query)
{
	auto vo = WorkHistoryFindVO::createShared();

	auto pdto = WorkHistoryFindPageDTO::createShared();

	WorkHistoryService service;

	pdto = service.listAll(query);

	vo->success(pdto);

	return vo;
	
}

Uint64JsonVO::Wrapper WorkHistoryController::execAddWorkHistory(const AddWorkHistoryDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();

	if (!dto->ormorgsectorname || !dto->ormdutyname || !dto->experience || !dto->pimpersonid || !dto->rzjssj || \
		!dto->rzkssj || !dto->ormorgname || !dto->ormpostname || !dto->cfplx || !dto->pimworkhistoryid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//有效值效验
	if (dto->ormorgsectorname->empty() || dto->ormdutyname->empty() || dto->pimpersonid->empty() || dto->rzjssj->empty() || \
		dto->rzkssj->empty() || dto->ormorgname->empty() || dto->ormpostname->empty() || dto->cfplx->empty() || dto->pimworkhistoryid->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	WorkHistoryService service;
	uint64_t id  = service.saveData(dto, payload);

	if (id > 0)
	{
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}

	return jvo;
}

Uint64JsonVO::Wrapper WorkHistoryController::execDelWorkHistory(const DelWorkHistoryDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	int length = dto->deleteById->size();

	if (length <= 0 || !dto->pimpersonid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		if (!(*it))
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}

	WorkHistoryService service;
	if (service.removeData(dto))
	{
		jvo->success(1);
	}
	else
	{
		jvo->fail(1);
	}
	return jvo;

}



StringJsonVO::Wrapper WorkHistoryController::execIntoWorkHistory(const String& body, const String& pimpersonid, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (!pimpersonid || !body)
	{
		jvo->fail("导入失败,文件为空");
	}
	if (pimpersonid->empty() || body->empty())
	{
		jvo->fail("导入失败,没有数据");
	}

	// 根据时间戳生成一个临时文件名称
	std::stringstream ss;
	ss << "public/static/Excel/";

	// 计算时间戳
	auto now = std::chrono::system_clock::now();
	auto tm_t = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tm_t), "%Y%m%d%H%M%S");
	// 获取毫秒
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	auto ms = tMilli - tSeconds;
	ss << std::setfill('0') << std::setw(3) << ms.count();
	// 拼接后缀名
	ss << ".xlsx";

	// 临时文件名称
	std::string fileName = ss.str();
	// 保存文件到临时目录
	body.saveToFile(fileName.c_str());

	// 上传到FastDFS文件服务器
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	//定义客户端对象
	FastDfsClient client("8.130.87.15");
#endif
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << "http://8.130.87.15:8888/" << fieldName;


	cout << ss.str() << endl;

	TestRocket::getInstance().testRocket(fieldName, pimpersonid, payload);
	
		/*WorkHistoryService service;
		service.saveManyData(fieldName, pimpersonid);*/
	jvo->success("文件导入成功");
	return jvo;
}

StringJsonVO::Wrapper WorkHistoryController::execExportWorkHistory(const WorkHistoryExportQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();
	WorkHistoryService service;

	std::string filaName= service.exportData(query);
	//ExportRocket::getInstance().testRocket(query);
	//std::string fileName = ExportRocket::getInstance().receiveMessage("export");
	if (filaName.empty())
	{
		vo->fail("导出失败");
	}

	vo->success(filaName);

	return vo;
}
//定义查看指定员工工作履历详情函数execQueryWorkHistory
WorkHistoryJsonVO::Wrapper WorkHistoryController::execQueryWorkHistory(const WorkHistoryQuery::Wrapper& query)
{
	// 定义一个Service
	WorkHistoryService service;
	// 查询数据
	auto result = service.listDetail(query);
	// 响应结果
	auto jvo = WorkHistoryJsonVO::createShared();
	if (result->pimworkhistoryid.getValue("").empty()) {
		cout << "No details were found" << endl;
		jvo->fail(result);
	}
	else {
		jvo->success(result);
	}
	return jvo;
}
//定义修改指定员工工作履历函数execModifyWorkHistory
StringJsonVO::Wrapper WorkHistoryController::execModifyWorkHistory(const ModWorkHistoryDTO::Wrapper& dto,const PayloadDTO& payload)
{
	//获取修改人id
	dto->updateman = payload.getUsername();
	//获取当前时间
	time_t timep;
	time(&timep);
	char tmp[256];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	//更改更新时间
	dto->updatedate = tmp;
	
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->pimworkhistoryid)
	{
		jvo->init(String("pimworkhistoryid must be not null"), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	WorkHistoryService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->pimworkhistoryid);
	}
	else
	{
		cout << "The primary key is not found or the data is consistent before and after the modification!" << endl;
		jvo->fail(dto->pimworkhistoryid);
	}
	// 响应结果
	return jvo;
}