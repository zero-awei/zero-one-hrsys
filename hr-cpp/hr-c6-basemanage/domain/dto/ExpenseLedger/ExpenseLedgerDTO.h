/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/26 23:20:04

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
#ifndef _EXPENSELEDGER_DTO_
#define _EXPENSELEDGER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 费用台账传输对象
 */
class ExpenseLedgerDTO : public oatpp::DTO
{
	DTO_INIT(ExpenseLedgerDTO, DTO);

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
/**
 * 费用台账分页传输对象
 */
class ExpenseLedgerPageDTO : public PageDTO< ExpenseLedgerDTO::Wrapper>
{
	DTO_INIT(ExpenseLedgerPageDTO, PageDTO< ExpenseLedgerDTO::Wrapper>);
};
#endif