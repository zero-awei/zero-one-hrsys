#include "stdafx.h"
#include "ContractCategoryService.h"
#include "../../dao/contractcategory/ContractCategoryDAO.h"

#include "../../../lib-common/include/SnowFlake.h"

ContractCategoryPageDTO::Wrapper ContractCategoryService::listAll(const ContractCategoryQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ContractCategoryPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ContractCategoryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ContractCategoryDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ContractCategoryDO sub : result)
	{
		auto dto = ContractCategoryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name)
			pages->addData(dto);
	}
	return pages;
}

uint64_t ContractCategoryService::addContractCategory(const ContractCategoryDTO::Wrapper& dto)
{
	// 组装DO数据
	ContractCategoryDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name)

		// 使用雪花算法生成全局唯一ID
		SnowFlake sf(1, 1);
	data.setId(std::to_string(sf.nextId()));

	// 执行数据添加
	ContractCategoryDAO dao;
	return dao.insert(data);
}

bool ContractCategoryService::modifyContractCategory(const ContractCategoryDTO::Wrapper& dto)
{
	// 组装DO数据
	ContractCategoryDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name)
		// 执行数据修改
		ContractCategoryDAO dao;
	return dao.update(data) == 1;
}

bool ContractCategoryService::removeContractCategory(uint64_t id)
{
	ContractCategoryDAO dao;
	return dao.deleteById(std::to_string(id)) == 1;
}
