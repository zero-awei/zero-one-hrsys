#include "stdafx.h"
#include "ArchivesService.h"
#include "../../dao/archives/ArchivesDAO.h"

ArchivesPageDTO::Wrapper ArchivesService::listAll(const ArchivesQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ArchivesPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ArchivesDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据DABH,ORMORGID3,DABGD,ARCHIVESCENTERID,EDUCATION,DATEOFBIRTH,JOINPARTYDATE,STARTWORKDATAE,DAZT
	pages->total = count;
	pages->calcPages();
	list<ArchivesDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ArchivesDO sub : result)
	{
		auto dto = ArchivesDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, dabh, Dabh, ormorgid3, Ormorgid3, dabgd, Dabgd, archivescentername, Archivescentername, education, Education, dateofbirth, Dateofbirth, joinpartydate, Joinpartydate, startworkdatae, Startworkdatae, dazt, Dazt);
		pages->addData(dto);

	}
	return pages;
}
