/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/19 23:43:37

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
#ifndef _EL_M_CONTROLLER_
#define _EL_M_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/ExpenseLedger/ExpenseLedgerQuery.h"
#include "domain/dto/ExpenseLedger/ExpenseLedgerDTO.h"
#include "domain/vo/ExpenseLedge/ExpenseLedgerVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ExpenseLedgerMController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(ExpenseLedgerMController);
public:
	// 查询费别
	ENDPOINT_INFO(queryExpenseLedger) {
		info->summary = ZH_WORDS_GETTER("expenseledger_mug.get.summary");
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("pimexpaccountname").description = ZH_WORDS_GETTER("expenseledger.field.PIMEXPACCOUNTNAME");
		info->queryParams["pimexpaccountname"].required = false;
		info->queryParams.add<String>("pimexpaccountid").description = ZH_WORDS_GETTER("expenseledger.field.PIMEXPACCOUNTID");
		info->queryParams["pimexpaccountid"].required = false;
		info->queryParams.add<String>("updateman").description = ZH_WORDS_GETTER("expenseledger.field.UPDATEMAN");
		info->queryParams["updateman"].required = false;
		info->queryParams.add<String>("createdate").description = ZH_WORDS_GETTER("expenseledger.field.CREATEDATE");
		info->queryParams["createdate"].required = false;
		info->queryParams.add<String>("createman").description = ZH_WORDS_GETTER("expenseledger.field.CREATEMAN");
		info->queryParams["createman"].required = false;
		info->queryParams.add<String>("updatedate").description = ZH_WORDS_GETTER("expenseledger.field.UPDATEDATE");
		info->queryParams["updatedate"].required = false;
		info->queryParams.add<String>("fylb").description = ZH_WORDS_GETTER("expenseledger.field.FYLB");
		info->queryParams["fylb"].required = false;
		info->queryParams.add<String>("fyje").description = ZH_WORDS_GETTER("expenseledger.field.FYJE");
		info->queryParams["fyje"].required = false;
		info->queryParams.add<String>("ffrs").description = ZH_WORDS_GETTER("expenseledger.field.FFRS");
		info->queryParams["ffrs"].required = false;
		info->queryParams.add<String>("ffsj").description = ZH_WORDS_GETTER("expenseledger.field.FFSJ");
		info->queryParams["ffsj"].required = false;
		info->queryParams.add<String>("ffybz").description = ZH_WORDS_GETTER("expenseledger.field.FFYBZ");
		info->queryParams["ffybz"].required = false;
		info->queryParams.add<String>("bz").description = ZH_WORDS_GETTER("expenseledger.field.BZ");
		info->queryParams["bz"].required = false;
		info->queryParams.add<String>("ormorgid").description = ZH_WORDS_GETTER("expenseledger.field.ORMORGID");
		info->queryParams["ormorgid"].required = false;
		API_DEF_ADD_RSP_JSON_WRAPPER(JsonVO<ExpenseLedgerPageDTO::Wrapper>);
	}
	ENDPOINT(API_M_GET, "/contract-management/query-by-expense-category", queryExpenseLedger,QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, ExpenseLedgerPageQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryExpenseLedger(query));
	}

	// 新增费别
	ENDPOINT_INFO(addExpenseLedger) {
		info->summary = ZH_WORDS_GETTER("expenseledger_mug.post.summary");
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_POST, "/contract-management/add-expense-category", addExpenseLedger, API_HANDLER_AUTH_PARAME, BODY_DTO(ExpenseLedgerDTO::Wrapper, dto)) {
		API_HANDLER_RESP_VO(execAddExpenseLedger(dto,authObject->getPayload()));
	}
	
	// 删除费别
	ENDPOINT_INFO(deleteExpenseLedger) {
		info->summary = ZH_WORDS_GETTER("expenseledger_mug.delete.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_DEL, "/contract-management/delete-by-expense-category", deleteExpenseLedger, BODY_DTO(ExpenseLedgerDelQuery::Wrapper, query)) {
		API_HANDLER_RESP_VO(execDeleteExpenseLedger(query));
	}
private:
	ExpenseLedgerPageJsonVO::Wrapper execQueryExpenseLedger(const ExpenseLedgerPageQuery::Wrapper& query);

	StringJsonVO::Wrapper execAddExpenseLedger(const ExpenseLedgerDTO::Wrapper& dto, const PayloadDTO& payload);

	Uint64JsonVO::Wrapper execDeleteExpenseLedger(const ExpenseLedgerDelQuery::Wrapper& query);
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_EL_M_CONTROLLER_
