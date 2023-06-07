
#include "stdafx.h"
#include "ArchivesService.h"
#include "../../dao/archives/ArchivesDAO.h"
#include "domain/do/archives/ArchivesDO.h"
#include "SnowFlake.h"

ArchivesPageDTO::Wrapper ArchivesService::getAll(const ArchivesQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ArchivesPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ArchivesDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<t_pimarchivesDO> result = dao.selectAll(query);
	// ��DOת����DTO
	for (t_pimarchivesDO sub : result)
	{
		auto dto = ArchivesDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, pimArchivesId, PimArchivesId, dabh, Dabh, orgName, OrgName,
			dabgd, Dabgd, archivesCenterName, ArchivesCenterName, dazt, Dazt, ygbh, Ygbh,
			pimPersonName, PimPersonName, ygzt, Ygzt, ormOrgName, OrmOrgName, zt, Zt,
			education, Education, dateOfBirth, DateOfBirth, joinPartyDate, JoinPartyDate, startWorkDatae, StartWorkDatae)
			pages->addData(dto);
	}
	return pages;
}

ArchivesPageDTO::Wrapper ArchivesService::listAll(const ArchivesQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ArchivesPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ArchivesDAO dao;
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
		auto dto = ArchivesDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, pimArchivesId, PimArchivesId, dabh, Dabh, orgName, OrgName, 
			dabgd, Dabgd, archivesCenterName, ArchivesCenterName, dazt, Dazt, ygbh, Ygbh,
			pimPersonName, PimPersonName, ygzt, Ygzt, ormOrgName, OrmOrgName, zt, Zt, 
			education, Education, dateOfBirth, DateOfBirth, joinPartyDate, JoinPartyDate, startWorkDatae, StartWorkDatae)
			pages->addData(dto);
	}
	return pages;
}

uint64_t ArchivesService::saveData(const ArchivesDTO::Wrapper& dto)
{
	// ��װDO����
	t_pimarchivesDO data;
	// id�Զ����ɲ���Ҫת��
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PimArchivesId, pimArchivesId, Dabh, dabh, OrgName, orgName,
		Dabgd, dabgd, ArchivesCenterName, archivesCenterName, Dazt, dazt, Ygbh, ygbh, 
		PimPersonName, pimPersonName, Ygzt, ygzt, OrmOrgName, ormOrgName, Zt, zt,
		Education, education, DateOfBirth, dateOfBirth, JoinPartyDate, joinPartyDate, StartWorkDatae, startWorkDatae, 
		PimPersonId, pimPersonId, OrMorGId3, orMorGId3, ArchivesCenterId, archivesCenterId)
	//����id
	SnowFlake sf(1, 5);
	// ����id��t_pimarchives������ֵ
	uint64_t id = sf.nextId();
	// У��id�Ƿ����ɳɹ�
	if (id == 0) {
		cerr << "id ����ʧ��" << endl;
		return 0;
	}
	cout << to_string(id) << endl;
	// ִ���������
	ArchivesDAO dao;
	return dao.insert(data, id);
}

bool ArchivesService::removeData(const string& id)
{
	ArchivesDAO dao;
	return dao.deleteById(id) == 1;
}
#include "stdafx.h"
#include "ArchivesService.h"
#include "domain/do/archives/ArchivesinfoDO.h"
#include <dao/archives/ArchivesDAO.h>

/**
 * ��ѯָ����������
 */

ArchivesPageDTO::Wrapper ArchivesService::getAll(const ArchivesQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ArchivesPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ArchivesDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<archivesinfoDO> result = dao.selectAll(query);
	// ��DOת����DTO
	for (archivesinfoDO sub : result)
	{
		auto dto = ArchivesDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, pimarchivesid, PIMARCHIVESID, dabh, DABH, orgname, ORGNAME, sfxjd, SFXJD, archivescentername, ARCHIVESCENTERNAME, dabgd, DABGD, pimpersonname, PIMPERSONNAME, ygbh, YGBH, ormorgname, ORMORGNAME, education, EDUCATION, dateofbirth, DATEOFBIRTH, joinpartydate, JOINPARTYDATE, startworkdatae, STARTWORKDATAE, dazt, DAZT, bz, BZ, fj, FJ)
			pages->addData(dto);

	}
	return pages;
}

/**
 * ����ָ������
 */

bool ArchivesService::updateDate(const ArchivesDTO::Wrapper& dto)
{
    // ��װDO����
	archivesinfoDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PIMARCHIVESID, pimarchivesid, DABH, dabh, ORGNAME, orgname,
		SFXJD, sfxjd, ARCHIVESCENTERNAME, archivescentername, DABGD, dabgd,
		PIMPERSONNAME, pimpersonname, YGBH, ygbh, ORMORGNAME, ormorgname,
		EDUCATION, education, DATEOFBIRTH, dateofbirth, JOINPARTYDATE, joinpartydate,
		STARTWORKDATAE, startworkdatae, DAZT, dazt, BZ, bz, FJ, fj)
		// ִ�������޸�
		ArchivesDAO dao;
	return dao.update(data) == 1;
}
