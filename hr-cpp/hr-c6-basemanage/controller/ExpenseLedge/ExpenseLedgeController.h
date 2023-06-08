#pragma once

#ifndef EXPENSEYCONTROLLER_H_
#define EXPENSEYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/ExpenseLedger/ExpenseLedgerDTO.h"
#include "domain/vo/ExpenseLedge/ExpenseLedgerVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * JobTitle控制器：云隐负责
 */
class ExpenseLedgeController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ExpenseLedgeController);
	// 3 定义接口
public:
	// 查询费别
	ENDPOINT_INFO(queryExpense) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("expense.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpenseLedgerJsonVO);
		// 定义其他表单参数描述
		info->queryParams.add<String>("pimexpaccountid").description = ZH_WORDS_GETTER("expense.field.expense_id");
		info->queryParams["pimexpaccountid"].addExample("default", String("12238653280246456320"));
		info->queryParams["pimexpaccountid"].required = true;
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/retirement-management/query-expense", queryExpense, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, ExpenseLedgerDTO, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryExpense(userQuery, authObject->getPayload()));
	}
	
	//导出费别
	ENDPOINT_INFO(getExpense) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("expense.export.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义其他表单参数描述
		info->queryParams.add<String>("pimexpaccountname").description = ZH_WORDS_GETTER("expense.field.expense_name");
		info->queryParams["pimexpaccountname"].addExample("default", String(u8"老干部活动费"));
		info->queryParams["pimexpaccountname"].required = false;
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/retirement-management/export-expense", getExpense, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, ExpenseLedgerDTO, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execGetExpense(userQuery, authObject->getPayload()));
	}

	// 修改费别
	ENDPOINT_INFO(modifyExpense) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("expense.update.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/retirement-management/modify-expense", modifyExpense, BODY_DTO(ExpenseLedgerDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyExpense(dto));
	}
private:
	// 3.3 演示查询数据
	ExpenseLedgerJsonVO::Wrapper execQueryExpense(const ExpenseLedgerDTO::Wrapper& query, const PayloadDTO& payload);
	StringJsonVO::Wrapper execGetExpense(const ExpenseLedgerDTO::Wrapper& query, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execModifyExpense(const ExpenseLedgerDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_