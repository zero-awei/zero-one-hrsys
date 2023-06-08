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
		if (int(string(query->row_show)[0]) == 49) {
			dto->personid = sub.getPersonid();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, personid, Personid);
		} 
		if (int(string(query->row_show)[1]) == 49) {
			dto->id = sub.getId();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id);
		}
		if (int(string(query->row_show)[2]) == 49) {
			dto->name = sub.getName();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name);
		}
		if (int(string(query->row_show)[3]) == 49) {
			dto->type = sub.getType();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, type, Type);
		}
		if (int(string(query->row_show)[4]) == 49) {
			dto->variety = sub.getVariety();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, variety, Variety);
		}
		if (int(string(query->row_show)[5]) == 49) {
			dto->date = sub.getDate();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, date, Date);
		}
		if (int(string(query->row_show)[6]) == 49) {
			dto->condition = sub.getCondition();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, condition, Condition);
		}
		if (int(string(query->row_show)[7]) == 49) {
			dto->department_c = sub.getDepartment_c();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, department_c, Department_c);
		}
		if (int(string(query->row_show)[8]) == 49) {
			dto->date_end = sub.getDate_end();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, date_end, Date_end);
		}
		if (int(string(query->row_show)[9]) == 49) {
			dto->person_department = sub.getPerson_department();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, person_department, Person_department);
		}
		if (int(string(query->row_show)[10]) == 49) {
			dto->person_condition = sub.getPerson_condition();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, person_condition, Person_condition);
		}
		if (int(string(query->row_show)[11]) == 49) {
			dto->date_arrive = sub.getDate_arrive();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, date_arrive, Date_arrive);
		}
		if (int(string(query->row_show)[12]) == 49) {
			dto->date_over = sub.getDate_over();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, date_over, Date_over);
		}
		if (int(string(query->row_show)[13]) == 49) {
			dto->rest = sub.getRest();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, rest, Rest);
		}
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
		if (int(string(query->row_show)[0]) == 49) {
			dto->personid = sub.getPersonid();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, personid, Personid);
		}
		if (int(string(query->row_show)[1]) == 49) {
			dto->id = sub.getId();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id);
		}
		if (int(string(query->row_show)[2]) == 49) {
			dto->name = sub.getName();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name);
		}
		if (int(string(query->row_show)[3]) == 49) {
			dto->type = sub.getType();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, type, Type);
		}
		if (int(string(query->row_show)[4]) == 49) {
			dto->variety = sub.getVariety();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, variety, Variety);
		}
		if (int(string(query->row_show)[5]) == 49) {
			dto->date = sub.getDate();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, date, Date);
		}
		if (int(string(query->row_show)[6]) == 49) {
			dto->condition = sub.getCondition();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, condition, Condition);
		}
		if (int(string(query->row_show)[7]) == 49) {
			dto->department_c = sub.getDepartment_c();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, department_c, Department_c);
		}
		if (int(string(query->row_show)[8]) == 49) {
			dto->date_end = sub.getDate_end();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, date_end, Date_end);
		}
		if (int(string(query->row_show)[9]) == 49) {
			dto->person_department = sub.getPerson_department();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, person_department, Person_department);
		}
		if (int(string(query->row_show)[10]) == 49) {
			dto->person_condition = sub.getPerson_condition();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, person_condition, Person_condition);
		}
		if (int(string(query->row_show)[11]) == 49) {
			dto->date_arrive = sub.getDate_arrive();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, date_arrive, Date_arrive);
		}
		if (int(string(query->row_show)[12]) == 49) {
			dto->date_over = sub.getDate_over();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, date_over, Date_over);
		}
		if (int(string(query->row_show)[13]) == 49) {
			dto->rest = sub.getRest();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, rest, Rest);
		}
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