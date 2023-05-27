#include "stdafx.h"
#include "ContractController.h"
#include "service/akieService/ContractInfoService.h"
#include "FastDfsClient.h"
ContractJsonVO_::Wrapper ContractController::execQueryContract(const ContractQuery_::Wrapper& query)
{
	// 创建响应对象
	auto vo = ContractJsonVO_::createShared();

	auto data = ContractDTO_::createShared();
	// 非空校验
	if (!query->id)
	{
		vo->init(data, RS_PARAMS_INVALID);
		return vo;
	}
	ContractInfoService service;

	auto dto = service.listContract(query);

	// 响应结果
	vo->success(dto);
	return vo;
}

Uint64JsonVO::Wrapper ContractController::execUpdateContract(const ContractDTO_::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 非空校验
	if (!dto->id || !dto->name || !dto->type || !dto->variety || !dto->date || !dto->condition || !dto->department_m || !dto->department_c || !dto->date_end)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	ContractInfoService service;

	// 执行数据修改
	if (service.updateContract(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
		//cout << 1 << endl;
	}


	return jvo;
}

StringJsonVO::Wrapper ContractController::execUploadContract(const String& fileBody, const String& suffix)
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

	// 测试上传到FastDFS文件服务器
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
	ss << "8.130.87.15:8888/" << fieldName;
	// 创建响应数据
	auto vo = StringJsonVO::createShared();
	vo->success(String(ss.str().c_str()));
	return vo;
}











StringJsonVO::Wrapper ContractController::execDownloadContract(const ContractDownloadQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();

	// TODO: 调用service获取导出文件下载链接



	// 校验
	if (query->sequence != "ASC" && query->sequence != "DESC")
	{
		vo->init("error(please contact akie)", RS_PARAMS_INVALID);
		return vo;
	}

	vo->success("url/download");
	return vo;
}
