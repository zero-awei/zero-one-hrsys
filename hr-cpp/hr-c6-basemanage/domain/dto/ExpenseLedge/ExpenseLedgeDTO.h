#ifndef EXPENSEYDTO_H
#define EXPENSEYDTO_H
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 费别DTO
 */
class ExpenseLedgeDTO : public oatpp::DTO
{
	DTO_INIT(ExpenseLedgeDTO, DTO);

	// 费用类别
	DTO_FIELD(String, expense_name);
	DTO_FIELD_INFO(expense_name) {
		info->description = ZH_WORDS_GETTER("expense.field.expense_name");
	}
	// 费用金额
	DTO_FIELD(UInt32, expense_num);
	DTO_FIELD_INFO(expense_num) {
		info->description = ZH_WORDS_GETTER("expense.field.expense_num");
	}
	// 发放人数
	DTO_FIELD(UInt32, people_num);
	DTO_FIELD_INFO(people_num) {
		info->description = ZH_WORDS_GETTER("expense.field.people_num");
	}
	
	// 发放时间
	DTO_FIELD(String, get_time);
	DTO_FIELD_INFO(get_time) {
		info->description = ZH_WORDS_GETTER("expense.field.get_time");
	}
	// 费用标准
	DTO_FIELD(UInt32, expense_std);
	DTO_FIELD_INFO(expense_std) {
		info->description = ZH_WORDS_GETTER("expense.field.expense_std");
	}
};
#endif