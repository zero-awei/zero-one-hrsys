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
#ifndef _EXPENSELEDGER_QUERY_
#define _EXPENSELEDGER_QUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class ExpenseLedgerPageQuery : public PageQuery
{
	DTO_INIT(ExpenseLedgerPageQuery, PageQuery);

	// 费用台账名称
	DTO_FIELD(String, PIMEXPACCOUNTNAME);
	DTO_FIELD_INFO(PIMEXPACCOUNTNAME) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.PIMEXPACCOUNTNAME");
	}
	// 费用台账标识
	DTO_FIELD(String, PIMEXPACCOUNTID);
	DTO_FIELD_INFO(PIMEXPACCOUNTID) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.PIMEXPACCOUNTID");
	}
	// 更新人
	DTO_FIELD(String, UPDATEMAN);
	DTO_FIELD_INFO(UPDATEMAN) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.UPDATEMAN");
	}
	// 建立时间
	DTO_FIELD(String, CREATEDATE);
	DTO_FIELD_INFO(CREATEDATE) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.CREATEDATE");
	}
	// 建立人
	DTO_FIELD(String, CREATEMAN);
	DTO_FIELD_INFO(CREATEMAN) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.CREATEMAN");
	}
	// 更新时间
	DTO_FIELD(String, UPDATEDATE);
	DTO_FIELD_INFO(UPDATEDATE) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.UPDATEDATE");
	}
	// 费用类别
	DTO_FIELD(String, FYLB);
	DTO_FIELD_INFO(FYLB) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FYLB");
	}
	// 费用金额
	DTO_FIELD(String, FYJE);
	DTO_FIELD_INFO(FYJE) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FYJE");
	}
	// 发放人数
	DTO_FIELD(String, FFRS);
	DTO_FIELD_INFO(FFRS) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FFRS");
	}
	// 发放时间
	DTO_FIELD(String, FFSJ);
	DTO_FIELD_INFO(FFSJ) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FFSJ");
	}
	// 费用标准
	DTO_FIELD(String, FFYBZ);
	DTO_FIELD_INFO(FFYBZ) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.FFYBZ");
	}
	// 备注
	DTO_FIELD(String, BZ);
	DTO_FIELD_INFO(BZ) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.BZ");
	}
};

class ExpenseLedgerDelQuery : public oatpp::DTO
{
	DTO_INIT(ExpenseLedgerDelQuery, DTO);
	DTO_FIELD(List<String>, Ids);
	DTO_FIELD_INFO(Ids) {
		info->description = ZH_WORDS_GETTER("expenseledger.field.IDS");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif
