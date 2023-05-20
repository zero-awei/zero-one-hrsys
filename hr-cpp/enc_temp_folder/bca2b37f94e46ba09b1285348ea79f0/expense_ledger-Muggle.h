#pragma once
#ifndef _EL_M_CONTROLLER
#define _EL_M_CONTROLLER

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Muggle/expenseLedgerQuery.h"
#include "domain/dto/Muggle/expenseLedgerDTO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

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
		API_HANDLER_QUERY_PARAM(query, mExpenseLedgerPageQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryExpenseLedger());
	}
	// 新增费别
	ENDPOINT_INFO(addExpenseLedger) {
		info->summary = ZH_WORDS_GETTER("expenseledger_mug.post.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/add", addExpenseLedger, BODY_DTO(mExpenseLedgerDTO::Wrapper, dto)) {
		API_HANDLER_RESP_VO(execAddExpenseLedger());
	}
	
	// 删除费别
	ENDPOINT_INFO(deleteExpenseLedger) {
		info->summary = ZH_WORDS_GETTER("expenseledger_mug.delete.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	ENDPOINT(API_M_DEL, "/delete-by-expense-category", deleteExpenseLedger, BODY_DTO(mExpenseLedgerDTO::Wrapper, dto)) {
		API_HANDLER_RESP_VO(execDeleteExpenseLedger());
	}
private:
	StringJsonVO::Wrapper execQueryExpenseLedger();

	StringJsonVO::Wrapper execAddExpenseLedger();

	StringJsonVO::Wrapper execDeleteExpenseLedger();
};
#endif // !_EL_M_CONTROLLER
