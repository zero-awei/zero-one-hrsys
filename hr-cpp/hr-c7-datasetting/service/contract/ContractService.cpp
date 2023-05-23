#include "stdafx.h"
#include "ContractService.h"
#include"../../dao/contractType/ContractTypeDAO.h"

ContractTypePageDTO::Wrapper ContractService::listAll(const ContractTypeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ContractTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ContractDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ContractDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ContractDO sub : result)
	{
		auto dto = ContractTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, department, Department, state, State, unitArrivalTime, UnitArrivalTime, contractId, ContractId, signingUnit, SigningUnit, contract_category, Contract_category, contract_type, Contract_type, startDate, StartDate, endDate, EndDate, contractStatus, ContractStatus, remainingDays, RemainingDays, expiryDate, ExpiryDate);
		pages->addData(dto);

	}
	return pages;
}

uint64_t ContractService::saveData(const ContractTypeDTO::Wrapper& dto)
{
	throw std::logic_error("The method or operation is not implemented.");
}

bool ContractService::updateData(const ContractTypeDTO::Wrapper& dto)
{
	throw std::logic_error("The method or operation is not implemented.");
}

bool ContractService::removeData(uint64_t id)
{
	throw std::logic_error("The method or operation is not implemented.");
}

