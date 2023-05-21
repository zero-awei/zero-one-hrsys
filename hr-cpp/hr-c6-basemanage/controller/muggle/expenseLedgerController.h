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
#include "domain/query/muggle/ExpenseLedgerQuery.h"
#include "domain/dto/muggle/ExpenseLedgerDTO.h"
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
		//API_DEF_ADD_RSP_JSON_WRAPPER()
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("expenseCategory").description = ZH_WORDS_GETTER("expenseledger_mug.field.expenseCategory");;
		info->queryParams["expenseCategory"].addExample("default", String("PDD"));
		info->queryParams["expenseCategory"].required = false;
	}
	ENDPOINT(API_M_GET, "/query-by-expense-category", queryExpenseLedger,QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, ExpenseLedgerPageMQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryExpenseLedger());
	}

	// 新增费别
	ENDPOINT_INFO(addExpenseLedger) {
		info->summary = ZH_WORDS_GETTER("expenseledger_mug.post.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/add-expense-category", addExpenseLedger, BODY_DTO(ExpenseLedgerMDTO::Wrapper, dto)) {
		API_HANDLER_RESP_VO(execAddExpenseLedger());
	}
	
	// 删除费别
	ENDPOINT_INFO(deleteExpenseLedger) {
		info->summary = ZH_WORDS_GETTER("expenseledger_mug.delete.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_DEL, "/delete-by-expense-category", deleteExpenseLedger, BODY_DTO(ExpenseLedgerMDTO::Wrapper, dto)) {
		API_HANDLER_RESP_VO(execDeleteExpenseLedger());
	}
private:
	StringJsonVO::Wrapper execQueryExpenseLedger();

	StringJsonVO::Wrapper execAddExpenseLedger();

	StringJsonVO::Wrapper execDeleteExpenseLedger();
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_EL_M_CONTROLLER_
