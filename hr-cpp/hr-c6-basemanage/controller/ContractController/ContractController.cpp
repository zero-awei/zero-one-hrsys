#include "stdafx.h"
#include "ContractController.h"


ContractJsonVO_::Wrapper ContractController::execQueryContract(const ContractQuery_::Wrapper& query)
{
	// 创建响应对象
	auto vo = ContractJsonVO_::createShared();
	// 响应结果
	//vo->success(1);
	return vo;
}

Uint64JsonVO::Wrapper ContractController::execUpdateContract(const ContractDTO_::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 响应结果
	//jvo->success(1);
	return jvo;
}

StringJsonVO::Wrapper ContractController::execUploadContract(const String& fileBody, const String& suffix)
{
	auto vo = StringJsonVO::createShared();
	//vo->success(String(ss.str().c_str()));
	return vo;
}

StringJsonVO::Wrapper ContractController::execDownloadContract(const ContractDownloadQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();

	// TODO: 调用service获取导出文件下载链接

	vo->success("url/download");
	return vo;
}
