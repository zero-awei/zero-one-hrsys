#pragma once


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class TerminationReminderQuery : public PageQuery
{
	DTO_INIT(TerminationReminderQuery, PageQuery);
	// 员工编号
	DTO_FIELD(String, employee_id);
	DTO_FIELD_INFO(employee_id) {
		info->description = "yuan gong bian hao";//ZH_WORDS_GETTER("sample.field.id");
	}
	// 员工姓名
	DTO_FIELD(String, employee_name);
	DTO_FIELD_INFO(employee_name) {
		info->description = "yuan gong xing ming";
	}
	//员工所属单位
	//DTO_FIELD(String, employee_part);
	//DTO_FIELD_INFO(employee_part) {
	//	info->description = "yuan gong suo shu bu men";
	//}
	// 员工状态
	DTO_FIELD(String, employee_status);
	DTO_FIELD_INFO(employee_status) {
		info->description = "yuan gong zhuang tai";
	}
	// 到本单位时间
	//DTO_FIELD(String, arrived_time);
	//DTO_FIELD_INFO(arrived_time) {
	//	info->description = "dao ben dan wei shi jian";
	//}
	// 合同编号
	DTO_FIELD(String, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = "he tong bian hao";
	}
	// 合同签订单位
	//DTO_FIELD(String, contract_sign_part);
	//DTO_FIELD_INFO(contract_sign_part) {
	//	info->description = "he tong qian ding dan wei";
	//}
	// 合同状态
	DTO_FIELD(String, contract_statu);
	DTO_FIELD_INFO(contract_statu) {
		info->description = "he tong zhuang tai";
	}
	// 合同类别
	DTO_FIELD(String, contract_lb);
	DTO_FIELD_INFO(contract_lb) {
		info->description = "he tong lei bie";
	}
	// 合同类型
	DTO_FIELD(String, contract_lx);
	DTO_FIELD_INFO(contract_lx) {
		info->description = "he tong lei xing";
	}
	// 起始日期
	DTO_FIELD(String, begin_time);
	DTO_FIELD_INFO(begin_time) {
		info->description = "qi shi ri qi";
	}
	// 结束日期
	DTO_FIELD(String, deadline);
	DTO_FIELD_INFO(deadline) {
		info->description = "jie shu ri qi";
	}
};

#include OATPP_CODEGEN_END(DTO)