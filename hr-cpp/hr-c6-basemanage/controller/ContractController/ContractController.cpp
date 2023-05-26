#include "stdafx.h"
#include "ContractController.h"


ContractJsonVO_::Wrapper ContractController::execQueryContract(const ContractQuery_::Wrapper& query)
{
	// 创建响应对象
	auto vo = ContractJsonVO_::createShared();

	auto data = ContractDTO_::createShared();
	// 非空校验
	if (!query->PIMCONTRACTID)
	{
		vo->init(data, RS_PARAMS_INVALID);
		return vo;
	}

	// 响应结果
	vo->success(data);
	return vo;
}

Uint64JsonVO::Wrapper ContractController::execUpdateContract(const ContractDTO_::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 非空校验
	if (!dto->PIMCONTRACTID || !dto->CREATEMAN || !dto->CREATEDATE || !dto->UPDATEDATE || !dto->PIMCONTRACTNAME)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 响应结果
	jvo->success(1);
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



	// 校验
	if (query->sequence != "ASC" && query->sequence != "DESC")
	{
		vo->init("error(please contact akie)", RS_PARAMS_INVALID);
		return vo;
	}

	vo->success("url/download");
	return vo;
}
