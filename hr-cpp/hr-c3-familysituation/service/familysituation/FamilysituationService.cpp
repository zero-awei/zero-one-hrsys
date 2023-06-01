#include "stdafx.h"
#include "FamilysituationService.h"
#include "SnowFlake.h"
#include "../../dao/Familysituation/FamilysituationDAO.h"

// 分页查询所有数据
FamilysituationPageDTO::Wrapper FamilysituationService::listAll(const FamilysituationQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = FamilysituationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	FamilysituationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<FamilysituationDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (FamilysituationDO sub : result)
	{
		auto dto = FamilysituationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, frelationship, Relationship, doctype, Doctype, \
			identification, Identification, gender, Gender, dob, Dob, age, Age, workplace, Workplace, job, Job, \
			politicalstatus, Politicalstatus, testament, Testament, ice, Ice);
			pages->addData(dto);
	}
	return pages;
}

FamilysituationDTO::Wrapper FamilysituationService::getOne(const FamilysituationQuery::Wrapper& query)
{
	// 构建返回对象
	auto data = FamilysituationDTO::createShared();

	// 查询数据总条数
	FamilysituationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return data;
	}

	// 指定查询数据
	list<FamilysituationDO> result = dao.selectWithOne(query);
	// 将DO转换成DTO
	for (FamilysituationDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(data, sub, name, Name, frelationship, Relationship, doctype, Doctype, \
			identification, Identification, gender, Gender, dob, Dob, age, Age, workplace, Workplace, job, Job, \
			politicalstatus, Politicalstatus, testament, Testament, ice, Ice);
	}
	return data;
}

uint64_t FamilysituationService::saveData(const FamilysituationDTO::Wrapper& dto)
{
	// 雪花算法生成id
	SnowFlake c3(1, 3);
	dto->id = to_string(c3.nextId());
	// 组装DO数据
	FamilysituationDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personid, Id, id, Name, name, Relationship, frelationship, Doctype, doctype, \
		Identification, identification, Gender, gender, Dob, dob, Age, age, Workplace, workplace, Job, job, \
		Politicalstatus, politicalstatus, Testament, testament, Ice, ice);
	// 执行数据添加
	FamilysituationDAO dao;
	return dao.insert(data);
}

bool FamilysituationService::updateData(const FamilysituationDTO::Wrapper& dto)
{
	// 组装DO数据
	FamilysituationDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personid, Id, id, Name, name, Relationship, frelationship, Doctype, doctype, \
		Identification, identification, Gender, gender, Dob, dob, Age, age, Workplace, workplace, Job, job, \
		Politicalstatus, politicalstatus, Testament, testament, Ice, ice);
	// 执行数据修改
	FamilysituationDAO dao;
	return dao.update(data) == 1;
}

bool FamilysituationService::removeData(const FamilysituationDTO::Wrapper& dto)
{
	// 组装DO数据
	FamilysituationDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personid, Id, id);
	FamilysituationDAO dao;
	return dao.deleteById(data) == 1;
}
