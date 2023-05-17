#pragma once
#ifndef _M_EL_DTO_
#define _M_EL_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class mExpenseLedgerDTO : public oatpp::DTO
{
	DTO_INIT(mExpenseLedgerDTO, DTO);

	DTO_FIELD(String, expenseCategory);//费用类别，命名不规范，亲人两行泪
	DTO_FIELD_INFO(expenseCategory) {
		info->description = ZH_WORDS_GETTER("expenseledger_mug.field.expenseCategory");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_M_EL_DTO_
