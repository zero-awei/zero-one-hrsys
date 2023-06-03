#include "stdafx.h"
#include "ContractCategoryController.h"
#include "service/ContractCategory/ContractCategoryService.h"

ContractCategoryPageDTO::Wrapper ContractCategoryController::execQueryContractCategory(const ContractCategoryQuery::Wrapper& query)
{
	ContractCategoryService service;
	return service.listAll(query);
}

Uint64JsonVO::Wrapper ContractCategoryController::execAddContractCategory(const ContractCategoryDTO::Wrapper& dto)
{
	ContractCategoryService service;
	uint64_t result = service.addContractCategory(dto);
	auto jvo = Uint64JsonVO::createShared();
	if (result > 0)
		jvo->success(result);
	else
		jvo->fail(result);
	return jvo;
}

Uint64JsonVO::Wrapper ContractCategoryController::execModifyContractCategory(const ContractCategoryDTO::Wrapper& dto)
{
	ContractCategoryService service;
	uint64_t result = service.modifyContractCategory(dto);
	auto jvo = Uint64JsonVO::createShared();
	if (result > 0)
		jvo->success(result);
	else
		jvo->fail(result);
	return jvo;
}

Uint64JsonVO::Wrapper ContractCategoryController::execRemoveContractCategory(uint64_t id)
{
	ContractCategoryService service;
	bool result = service.removeContractCategory(id);
	auto jvo = Uint64JsonVO::createShared();
	if (result)
		jvo->success(1);
	else
		jvo->fail(-1);
	return jvo;
}
