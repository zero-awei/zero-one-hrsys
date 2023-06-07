#include "stdafx.h"
#include "ArchivesCenterService.h"
#include "dao/archives/ArchivesDAO.h"
#include "../../../hr-c5-employeeInfo/Macros.h"

/**
 * 分页查询档案室
 */

ArchivesCenterDTO::Wrapper ArchivesCenterService::listAll(const ArchivesCenterQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ArchivesCenterPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ArchivesCenterDAO dao; 
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询档案室
	pages->total = count;
	pages->calcPages();
	list<archivesCenterDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (archivesCenterDO sub : result)
	{
		auto dto = ArchivesCenterDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, serialno, SERIALNO, archivescentername, ARCHIVESCENTERNAME, cabinetno, CABINETNO, layerno, LAYERNO, bnumber, BNUMBER)
			pages->addData(dto);

	}
	return pages;
}

