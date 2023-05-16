#include "stdafx.h"
#include "ContractController.h"


ContractJsonVO::Wrapper ContractController::execQueryContract(const ContractQuery::Wrapper& query)
{
	// 创建响应对象
	auto vo = ContractJsonVO::createShared();
	// 响应结果
	//vo->success(1);
	return vo;
}

Uint64JsonVO::Wrapper ContractController::execUpdateContract(const ContractDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 响应结果
	//jvo->success(1);
	return jvo;
}

Uint64JsonVO::Wrapper ContractController::execUploadContract(const PathDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();


	return jvo;
}

PathJsonVO::Wrapper ContractController::execDownloadContract(const PathDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = PathJsonVO::createShared();


	return jvo;
}