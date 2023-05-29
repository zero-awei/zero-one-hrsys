#include "stdafx.h"
#include "ContractCategoryController.h"

ContractCategoryPageJsonVO::Wrapper ContractCategoryController::execQueryContractCategory(const ContractCategoryQuery::Wrapper& query)
{
	// 响应结果
	// 创建响应对象
	auto jvo = ContractCategoryPageJsonVO::createShared();
	// 创建分页对象
	auto pdto = ContractCategoryPageDTO::createShared();
	pdto->addData(ContractCategoryDTO::createShared("1", "zs"));
	pdto->addData(ContractCategoryDTO::createShared("2", "ls"));
	jvo->success(pdto);
	return jvo;
}

Uint64JsonVO::Wrapper ContractCategoryController::execAddContractCategory(const ContractCategoryDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();


	//响应结果
	jvo->success(1);
	return jvo;
}

Uint64JsonVO::Wrapper ContractCategoryController::execModifyContractCategory(const ContractCategoryDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();


	// 响应结果
	jvo->success(1);
	return jvo;
}

Uint64JsonVO::Wrapper ContractCategoryController::execRemoveContractCategory(const ContractCategoryDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();


	// 响应结果
	jvo->success(1);
	return jvo;
}
