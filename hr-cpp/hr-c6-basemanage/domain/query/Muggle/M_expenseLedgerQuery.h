#pragma once
#ifndef _M_EL_QUERY_
#define _M_EL_QUERY_
#include "../../GlobalInclude.h"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class mExpenseLedgerPageQuery : public PageQuery
{
	DTO_INIT(mExpenseLedgerPageQuery, PageQuery);

	DTO_FIELD(String, expenseCategory);//费用类别，命名不规范，亲人两行泪
	DTO_FIELD_INFO(expenseCategory) {
		info->description = ZH_WORDS_GETTER("expenseledger_mug.field.expenseCategory");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_M_EL_QUERY_
