#pragma once
#ifndef _CONTRACT_DTO_
#define _CONTRACT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class ContractDTO_gs : public oatpp::DTO
{
	DTO_INIT(ContractDTO_gs, DTO);
	//员工编号
	DTO_FIELD(String, personid);
	DTO_FIELD_INFO(personid) {
		info->description = ZH_WORDS_GETTER("contract.field.personid");
	}
	// 合同编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("contract.field.id");
	}
	// 员工姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("contract.field.name");
	}
	// 合同类别
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("contract.field.type");
	}
	// 合同类型
	DTO_FIELD(String, variety);
	DTO_FIELD_INFO(variety) {
		info->description = ZH_WORDS_GETTER("contract.field.variety");
	}
	// 起始日期
	DTO_FIELD(String, date);
	DTO_FIELD_INFO(date) {
		info->description = ZH_WORDS_GETTER("contract.field.date");
	}
	// 合同状态
	DTO_FIELD(String, condition);
	DTO_FIELD_INFO(condition) {
		info->description = ZH_WORDS_GETTER("contract.field.condition");
	}
	// 合同签订单位
	DTO_FIELD(String, department_c);
	DTO_FIELD_INFO(department_c) {
		info->description = ZH_WORDS_GETTER("contract.field.department_c");
	}
	// 试用到期时间
	DTO_FIELD(String, date_end);
	DTO_FIELD_INFO(date_end) {
		info->description = ZH_WORDS_GETTER("contract.field.date_end");
	}
	//员工所属单位
	DTO_FIELD(String, person_department);
	DTO_FIELD_INFO(person_department) {
		info->description = ZH_WORDS_GETTER("contract.field.person_department");
	}
	//员工状态
	DTO_FIELD(String, person_condition);
	DTO_FIELD_INFO(person_condition) {
		info->description = ZH_WORDS_GETTER("contract.field.person_condition");
	}
	//到本单位时间
	DTO_FIELD(String, date_arrive);
	DTO_FIELD_INFO(date_arrive) {
		info->description = ZH_WORDS_GETTER("contract.field.date_arrive");
	}
	//结束日期
	DTO_FIELD(String, date_over);
	DTO_FIELD_INFO(date_over) {
		info->description = ZH_WORDS_GETTER("contract.field.date_over");
	}
	//合同剩余天数
	DTO_FIELD(String, rest);
	DTO_FIELD_INFO(rest) {
		info->description = ZH_WORDS_GETTER("contract.field.rest");
	}
};

class  ContractDTO_gs_insert : public oatpp::DTO
{
	DTO_INIT(ContractDTO_gs_insert, DTO);
	//1、员工编号
	DTO_FIELD(String, personid);
	DTO_FIELD_INFO(personid) {
		info->description = ZH_WORDS_GETTER("contract.field.personid");
	}
	// 2、合同编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("contract.field.id");
	}
	// 3、合同类别
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("contract.field.type");
	}
	// 4、合同类型
	DTO_FIELD(String, variety);
	DTO_FIELD_INFO(variety) {
		info->description = ZH_WORDS_GETTER("contract.field.variety");
	}
	// 5、起始日期
	DTO_FIELD(String, date);
	DTO_FIELD_INFO(date) {
		info->description = ZH_WORDS_GETTER("contract.field.date");
	}
	// 6、合同状态
	DTO_FIELD(String, condition);
	DTO_FIELD_INFO(condition) {
		info->description = ZH_WORDS_GETTER("contract.field.condition");
	}
	//7、合同管理单位
	DTO_FIELD(String, department_m);
	DTO_FIELD_INFO(department_m) {
		info->description = ZH_WORDS_GETTER("contract.field.department_m");
	}
	// 8、试用到期时间
	DTO_FIELD(String, date_end);
	DTO_FIELD_INFO(date_end) {
		info->description = ZH_WORDS_GETTER("contract.field.date_end");
	}
	//9、备注
	DTO_FIELD(String, tip);
	DTO_FIELD_INFO(tip) {
		info->description = ZH_WORDS_GETTER("contract.field.tip");
	}
};

class ContractDTO_gs_delete : public oatpp::DTO
{
	DTO_INIT(ContractDTO_gs_delete, DTO);
	// 待删除编号
	DTO_FIELD(List<String>, deleteById) = {};
	DTO_FIELD_INFO(deleteById) {
		info->description = ZH_WORDS_GETTER("contract.field.id");
	}
};

/**
 * 示例分页传输对象
 */
class ContractPageDTO_gs : public PageDTO<ContractDTO_gs::Wrapper>
{
	DTO_INIT(ContractPageDTO_gs, PageDTO<ContractDTO_gs::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
