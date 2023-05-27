#include "stdafx.h"
#include "ContractInfoService.h"
#include "../../dao/ContractInfo/ContractInfoDAO.h"
#include "domain/dto/ContractDTO/ContractDTO_.h"
#include <stdlib.h>

ContractDTO_::Wrapper ContractInfoService::listContract(const ContractQuery_::Wrapper& query)
{
	// 构建返回对象
	auto res = ContractDTO_::createShared();
	//dao层逻辑运算
	ContractInfoDAO dao;
	list<ContractDO> result = dao.selectById(std::to_string(query->id.getValue(1)));
	// 将DO转换成DTO
	for (ContractDO sub : result)
	{
		auto dto = ContractDTO_::createShared();
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
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, type, Type, variety, Variety, date, Date, condition, Condition, department_m, Department_m, department_c, Department_c, date_end, Date_end, tip, Tip);
		res = dto;
	}
	return res;
}

bool ContractInfoService::updateContract(const ContractDTO_::Wrapper& dto)
{
	//转个do
	ContractDO cdo;
	//cdo.setId(dto->id.getValue(1));
	//cdo.setName(dto->name.getValue("this is a name"));
	//cdo.setType(dto->type.getValue("..."));
	//cdo.setVariety(dto->variety.getValue("..."));
	//cdo.setDate(dto->date.getValue("2023-05-02 19:57:59"));
	//cdo.setCondition(dto->condition.getValue("..."));
	//cdo.setDepartment_m(dto->department_m.getValue("..."));
	//cdo.setDepartment_c(dto->department_c.getValue("..."));
	//cdo.setDate_end(dto->date_end.getValue("2023-05-02 19:57:59"));
	//cdo.setTip(dto->tip.getValue("..."));

	ZO_STAR_DOMAIN_DTO_TO_DO(cdo, dto, Name, name, Type, type, Variety, variety, Date, date, Condition, condition, Department_m, department_m, Department_c, department_c, Date_end, date_end, Tip, tip)
	//dao层逻辑运算
	ContractInfoDAO dao;
	return dao.update(cdo) == 1;
}