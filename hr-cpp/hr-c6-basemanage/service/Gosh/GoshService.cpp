#include "stdafx.h"
#include "GoshService.h"
#include "dao/Gosh/GoshDAO.h"
#include "domain/dto/Gosh/ContractDTO.h"
#include "Macros.h"
#include "SnowFlake.h"

ContractPageDTO_gs::Wrapper GoshService::listContract(const ContractQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ContractPageDTO_gs::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	GoshDAO dao;
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
		auto dto = ContractDTO_gs::createShared();
		dto->personid = sub.getPersonid();
		dto->id = sub.getId();
		dto->name = sub.getName();
		dto->type = sub.getType();
		dto->variety = sub.getVariety();
		dto->date = sub.getDate();
		dto->condition = sub.getCondition();
		dto->department_c = sub.getDepartment_c();
		dto->date_end = sub.getDate_end();
		dto->person_department = sub.getPerson_department();
		dto->person_condition = sub.getPerson_condition();
		dto->date_arrive = sub.getDate_arrive();
		dto->date_over = sub.getDate_over();
		dto->rest = sub.getRest();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, personid, Personid, id, Id, name, Name, type, Type,variety,Variety,date,Date, condition, Condition, department_c, Department_c, date_end, Date_end, person_department, Person_department, person_condition, Person_condition, date_arrive, Date_arrive, date_over, Date_over, rest, Rest);
		pages->addData(dto);
	}
	return pages;
}

ContractPageDTO_gs::Wrapper GoshService::listPerson(const ContractQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ContractPageDTO_gs::createShared();
	// 分页查询数据
	GoshDAO dao;
	list<ContractDO> result = dao.selectByName(query->name);
	// 将DO转换成DTO
	for (ContractDO sub : result)
	{
		auto dto = ContractDTO_gs::createShared();
		dto->personid = sub.getPersonid();
		dto->id = sub.getId();
		dto->name = sub.getName();
		dto->type = sub.getType();
		dto->variety = sub.getVariety();
		dto->date = sub.getDate();
		dto->condition = sub.getCondition();
		dto->department_c = sub.getDepartment_c();
		dto->date_end = sub.getDate_end();
		dto->person_department = sub.getPerson_department();
		dto->person_condition = sub.getPerson_condition();
		dto->date_arrive = sub.getDate_arrive();
		dto->date_over = sub.getDate_over();
		dto->rest = sub.getRest();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, personid, Personid, id, Id, name, Name, type, Type, variety, Variety, date, Date, condition, Condition, department_c, Department_c, date_end, Date_end, person_department, Person_department, person_condition, Person_condition, date_arrive, Date_arrive, date_over, Date_over, rest, Rest);
		pages->addData(dto);
	}
	return pages;
}

uint64_t GoshService::saveData(const ContractDTO_gs_insert::Wrapper& dto)
{
	// 组装DO数据
	SnowFlake sf(1, 6);
	uint64_t add_id = sf.nextId();
	ContractDO data;
	data.setPersonid(dto->personid.getValue(""));
	//data.setId(dto->id.getValue(std::to_string(add_id)));
	data.setId(std::to_string(add_id));
	data.setType(dto->type.getValue(""));
	data.setVariety(dto->variety.getValue(""));
	data.setDate(dto->date.getValue(""));
	data.setCondition(dto->condition.getValue(""));
	data.setDepartment_m(dto->department_m.getValue(""));
	data.setDate_end(dto->date_end.getValue(""));
	data.setTip(dto->tip.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Personid, personid,Type,type, Variety,variety, Date,date, Condition,condition , Department_m,department_m, Date_end,date_end, Tip,tip)
	// 执行数据添加
	GoshDAO dao;
	return dao.insert(data);
}

bool GoshService::removeData(const ContractDTO_gs_delete::Wrapper& dto)
{
	GoshDAO dao;
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		dao.deleteById(*it);
	}
	return true;
}	