#include "stdafx.h"
#include "FamilysituationController.h"
#include "FastDfsClient.h"
#include "../../service/familysituation/FamilysituationService.h"

// 分页查询响应
FamilysituationPageJsonVO::Wrapper FamilysituationController::execQueryByFamilysituation(const FamilysituationQuery::Wrapper& query, const PayloadDTO& payload)
{
	FamilysituationService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto vo = FamilysituationPageJsonVO::createShared();
	vo->success(result);
	return vo;
}

// 指定查询响应
FamilysituationJsonVO::Wrapper FamilysituationController::execOneQueryFamilysituation(const FamilysituationQuery::Wrapper& query)
{
	FamilysituationService service;
	// 查询数据
	auto result = service.getOne(query);
	// 响应结果
	auto vo = FamilysituationJsonVO::createShared();
	vo->success(result);
	return vo;
}


// 添加响应
Uint64JsonVO::Wrapper FamilysituationController::execAddFamilysituation(const FamilysituationDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto vo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->id || !dto->personid)
	{
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}
	// 有效值校验
	if (dto->id->empty())
	{
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}
	// 定义一个Service
	FamilysituationService service;
	// 传入权限验证信息
	auto authId = payload.getUsername();
	// 执行数据新增
	auto result = service.saveData(dto, authId);
	if (result == 0) {
		vo->success(UInt64(result));
	}
	else
	{
		vo->fail(UInt64(result));
	}
	return vo;
}

// 修改响应
Uint64JsonVO::Wrapper FamilysituationController::execModifyFamilysituation(const FamilysituationDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto vo = Uint64JsonVO::createShared();
	// 有效值校验
	if (dto->id->empty())
	{
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}
	// 定义一个Service
	FamilysituationService service;
	// 执行数据修改
	auto result = service.updateData(dto, payload.getUsername());
	if (result) {
		vo->success(UInt64(result));
	}
	else
	{
		vo->fail(UInt64(result));
	}
	return vo;
}

// 删除响应
Uint64JsonVO::Wrapper FamilysituationController::execRemoveFamilysituation(const FamilyBatchDeleteDTO::Wrapper& dto)
{
	auto vo = Uint64JsonVO::createShared();
	// 有效值校验 集合不能小于0
	int familySize = dto->batchFamilyId->size();
	if (familySize <= 0)
	{
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}
	// 定义一个Service
	FamilysituationService service;
	// 执行数据删除
	auto result = service.removeData(dto);
	if (result > 0) {
		vo->success(UInt64(result));
	}
	else
	{
		vo->fail(UInt64(result));
	}
	return vo;
}

// 导入响应
StringJsonVO::Wrapper FamilysituationController::executeImportFamilysituation(const String& fileBody, const String& suffix)
{
	// 根据时间戳生成一个临时文件名称
	std::stringstream ss;
	ss << "public/static/file/";
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
	ss << suffix.getValue("");

	// 临时文件名称
	std::string fileName = ss.str();
	// 保存文件到临时目录
	fileBody.saveToFile(fileName.c_str());

//	// 测试上传到FastDFS文件服务器
//#ifdef LINUX
//	//定义客户端对象
//	FastDfsClient client("conf/client.conf", 3);
//#else
//	//定义客户端对象
//	FastDfsClient client("192.168.52.133");
//#endif
//	std::string fieldName = client.uploadFile(fileName);
//	std::cout << "upload fieldname is : " << fieldName << std::endl;
//	ss.str("");
//	ss.clear();
//	ss << "http://192.168.52.133:8888/" << fieldName;

	// excel解析逻辑（暂时不会写）
	
	// 创建响应数据
	auto vo = StringJsonVO::createShared();
	vo->success(String("cool"));
	return vo;
}


// 导出响应
StringJsonVO::Wrapper FamilysituationController::execExportFamilysituation(const FamilysituationQuery::Wrapper &query)
{
	auto jvo = StringJsonVO::createShared();
	// 定义一个Service
	// AssignInfoService service;
	// //// 查询数据
	// auto result = service.exportData(query);
	// if (!result.empty()) {
	// 	jvo->success(result);
	// } else {
	// 	jvo->fail("export fail");
	// }
	return jvo;
}

