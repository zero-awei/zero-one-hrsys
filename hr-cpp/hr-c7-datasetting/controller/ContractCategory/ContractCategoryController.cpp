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
	return Uint64JsonVO::createShared(result);
}

Uint64JsonVO::Wrapper ContractCategoryController::execModifyContractCategory(const ContractCategoryDTO::Wrapper& dto)
{
	ContractCategoryService service;
	uint64_t result = service.modifyContractCategory(dto);
	return Uint64JsonVO::createShared(result);
}

Uint64JsonVO::Wrapper ContractCategoryController::execRemoveContractCategory(uint64_t id)
{
	ContractCategoryService service;
	bool result = service.removeContractCategory(id);
	return Uint64JsonVO::createShared(result ? 1 : 0);
}
