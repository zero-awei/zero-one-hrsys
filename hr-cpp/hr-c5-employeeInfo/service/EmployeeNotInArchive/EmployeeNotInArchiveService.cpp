#include "stdafx.h"
#include "EmployeeNotInArchiveService.h"
#include "../../dao/ArchivesManagement/t_pimarchivesDAO.h"
#include "domain/do/t_pimarchives/t_pimarchivesDO.h"

EmployeeNotInArchivePageDTO::Wrapper ArchivesService::listAll(const EmployeeNotInArchiveQuery::Wrapper& query){
	// �������ض���
	auto pages = EmployeeNotInArchivePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	t_pimarchivesDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<t_pimarchivesDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (t_pimarchivesDO sub : result)
	{
		auto dto = EmployeeNotInArchiveDto::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, nummber, Dabh, gunits, Orgname, pos, Dabgd, office, Archivescentername, status, Dastate, emloyeenumber, Ygbh, PimPersonName, Pimpersonname, unit, Ormorgname, state, Ygzt, use, Operations)
			pages->addData(dto);

	}
	return pages;
}

bool ArchivesService::updateArchive(const EmployeeNotInArchiveDto::Wrapper& dto)
{
    // ��װDO����
	t_pimarchivesDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Dabh, nummber, Orgname, gunits, Dabgd, pos, Archivescentername, office, Dastate, status, Ygbh, emloyeenumber, Pimpersonname, PimPersonName, Ormorgname, unit, Ygzt, state, Operations, use)

	t_pimarchivesDAO dao;
	return dao.update(data) == 1;
}
