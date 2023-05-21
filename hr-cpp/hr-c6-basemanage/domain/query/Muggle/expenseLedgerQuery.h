/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/19 23:24:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#pragma once
#ifndef _EL_M_QUERY_
#define _EL_M_QUERY_
#include "../../GlobalInclude.h"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExpenseLedgerPageMQuery : public PageQuery
{
	DTO_INIT(ExpenseLedgerPageMQuery, PageQuery);

	DTO_FIELD(String, expenseCategory);//费用类别，命名不规范，亲人两行泪
	DTO_FIELD_INFO(expenseCategory) {
		info->description = ZH_WORDS_GETTER("expenseledger_mug.field.expenseCategory");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_M_EL_QUERY_
