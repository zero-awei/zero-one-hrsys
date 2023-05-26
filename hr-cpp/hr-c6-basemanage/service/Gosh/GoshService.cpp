#include "stdafx.h"
#include "GoshService.h"
#include "dao/Gosh/GoshDAO.h"
#include "domain/dto/Gosh/ContractDTO.h"

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
		dto->id = sub.getId();
		dto->name = sub.getName();
		dto->type = sub.getType();
		dto->variety = sub.getVariety();
		dto->date = sub.getDate();
		dto->condition = sub.getCondition();
		dto->department_m = sub.getDepartment_m();
		dto->department_c = sub.getDepartment_c();
		dto->date_end = sub.getDate_end();
		dto->tip = sub.getTip();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, type, Type,variety,Variety,date,Date, condition, Condition, department_m, Department_m, department_c, Department_c, date_end, Date_end, tip,Tip);
		pages->addData(dto);

	}
	return pages;
}


uint64_t GoshService::saveData(const ContractDTO_gs::Wrapper& dto)
{
	// 组装DO数据
	ContractDO data;
	data.setName(dto->name.getValue(""));
	data.setType(dto->type.getValue(""));
	data.setVariety(dto->variety.getValue(""));
	data.setDate(dto->date.getValue(""));
	data.setCondition(dto->condition.getValue(""));
	data.setDepartment_m(dto->department_m.getValue(""));
	data.setDepartment_c(dto->department_c.getValue(""));
	data.setDate_end(dto->date_end.getValue(""));
	data.setTip(dto->tip.getValue(""));
	//data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Type,type, Variety,variety, Date,date, Condition,condition , Department_m,department_m, Department_c,department_c, Date_end,date_end, Tip,tip)
		// 执行数据添加
	GoshDAO dao;
	return dao.insert(data);
}

//bool GoshService::updateData(const ContractDTO_gs::Wrapper& dto)
//{
//	// 组装DO数据
//	GoshDO data;
//	// 	data.setId(dto->id.getValue(0));
//	// 	data.setName(dto->name.getValue(""));
//	// 	data.setSex(dto->sex.getValue(""));
//	// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id)
//		// 执行数据修改
//		GoshDAO dao;
//	return dao.update(data) == 1;
//}

bool GoshService::removeData(uint64_t id)
{
	GoshDAO dao;
	return dao.deleteById(id) == 1;
}