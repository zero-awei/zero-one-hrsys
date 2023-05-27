#include "stdafx.h"
#include "ContractTypeService.h"
#include"../../dao/contractType/ContractTypeDAO.h"

ContractTypePageDTO::Wrapper ContractTypeService::listAll(const ContractTypeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ContractTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ContractTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ContractTypeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ContractTypeDO sub : result)
	{
		auto dto = ContractTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name);
		pages->addData(dto);

	}
	return pages;
}

uint64_t ContractTypeService::saveData(const ContractTypeDTO::Wrapper& dto)
{
	throw std::logic_error("The method or operation is not implemented.");
}

bool ContractTypeService::updateData(const ContractTypeDTO::Wrapper& dto)
{
	throw std::logic_error("The method or operation is not implemented.");
}

bool ContractTypeService::removeData(uint64_t id)
{
	throw std::logic_error("The method or operation is not implemented.");
}

