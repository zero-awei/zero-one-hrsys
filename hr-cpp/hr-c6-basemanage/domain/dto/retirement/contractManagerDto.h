#pragma once
#pragma once
#ifndef _CONTRACTMAGAGERDTO_H_
#define _CONTRACTMAGAGERDTO_H_

#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)
class contractmanagerDTO : public oatpp::DTO
{
	//初始化
	DTO_INIT(contractmanagerDTO, DTO);
	// 员工id1
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.number");
	}
	DTO_FIELD(String, name);
	// 查询的第二个参数，员工姓名2
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.name");
	}
	DTO_FIELD(String,Employee_unit);
	// 员工所属单位3
	DTO_FIELD_INFO(Employee_unit) {
		info->description = "yuan gong dan wei ";
	}
	DTO_FIELD(String, employee_state);
	// 员工状态4
	DTO_FIELD_INFO(employee_state) {
		info->description = "employee state ";
	}
	DTO_FIELD(String, Time_unit);
	// 到本单位时间5
	DTO_FIELD_INFO(Time_unit) {
		info->description = "ben dan wei shi jian";
	}
	DTO_FIELD(String, contract_id);
	// 合同编号6
	DTO_FIELD_INFO(contract_id) {
		info->description = "ben dan wei shi jian";
	}
	DTO_FIELD(String, Contract_unit);
	// 合同单位7
	DTO_FIELD_INFO(Contract_unit) {
		info->description = " he tong dan wei";
	}
	DTO_FIELD(String, Class_contract);
	// 合同类别8
	DTO_FIELD_INFO(Class_contract) {
		info->description = "he tong lei bie ";
	}
	DTO_FIELD(String, contract_type);
	// 合同类型9
	DTO_FIELD_INFO(contract_type) {
		info->description = "he tong lei xing";
	}
	DTO_FIELD(String, start_date);
	// 起始日期10
	DTO_FIELD_INFO(start_date) {
		info->description = "zu zhi";
	}
	DTO_FIELD(String, stop_date);
	// 结束日期11
	DTO_FIELD_INFO(stop_date) {
		info->description = "bu men";
	}
	DTO_FIELD(String, Operation_column);
	// 操作列12
	DTO_FIELD_INFO(Operation_column) {
		info->description = "zhi ji";
	}
};

/**
 * 示例分页传输对象
 */
class contractmanagerPageDTO : public PageDTO<contractmanagerDTO::Wrapper>
{
	DTO_INIT(contractmanagerPageDTO, PageDTO<contractmanagerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTMAGAGERDTO_H_
