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
	DTO_FIELD(String, PIMEXPACCOUNTNAME);
	DTO_FIELD_INFO(PIMEXPACCOUNTNAME) {
		info->description = ZH_WORDS_GETTER("expense.field.expense_name");
	}

	// 费用标识
	DTO_FIELD(String, PIMEXPACCOUNTID);
	DTO_FIELD_INFO(PIMEXPACCOUNTID) {
		info->description = ZH_WORDS_GETTER("expense.field.expense_id");
	}

	// 费用金额
	DTO_FIELD(Float64, FYJE);
	DTO_FIELD_INFO(FYJE) {
		info->description = ZH_WORDS_GETTER("expense.field.expense_num");
	}
	// 发放人数
	DTO_FIELD(UInt32, FFRS);
	DTO_FIELD_INFO(FFRS) {
		info->description = ZH_WORDS_GETTER("expense.field.people_num");
	}
	
	// 发放时间
	DTO_FIELD(String, FFSJ);
	DTO_FIELD_INFO(FFSJ) {
		info->description = ZH_WORDS_GETTER("expense.field.get_time");
	}
	// 费用标准
	DTO_FIELD(String, FFYBZ);
	DTO_FIELD_INFO(FFYBZ) {
		info->description = ZH_WORDS_GETTER("expense.field.expense_std");
	}
};
#endif