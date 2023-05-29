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
	// 编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("contract.field.id");
	}
	// 姓名
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
	// 合同管理单位
	DTO_FIELD(String, department_m);
	DTO_FIELD_INFO(department_m) {
		info->description = ZH_WORDS_GETTER("contract.field.department_m");
	}
	// 合同签订单位
	DTO_FIELD(String, department_c);
	DTO_FIELD_INFO(department_c) {
		info->description = ZH_WORDS_GETTER("contract.field.department_c");
	}
	// 合同到期时间
	DTO_FIELD(String, date_end);
	DTO_FIELD_INFO(date_end) {
		info->description = ZH_WORDS_GETTER("contract.field.date_end");
	}
	// 备注
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
