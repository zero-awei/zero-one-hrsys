#pragma once

#ifndef _LOANEDPERPAGE_CONTROLLER_
#define _LOANEDPERPAGE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/query/RosterOfPer/LoanedPerPageQuery.h"
#include "domain/dto/RosterOfPer/LoanedPerPageDTO.h"
#include "domain/vo/RosterOfPer/LoanedPerPageVO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/*
（人员花名册-借调人员-分页查询员工列表（导出本页在前端完成））--luoluo
（人员花名册-借调人员-导出证书（导出本页在前端完成））--未小满
*/
class LoanedPerPageController : public oatpp::web::server::api::ApiController // 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(LoanedPerPageController);
	// 定义接口
public:

	// 定义查询接口描述
	ENDPOINT_INFO(queryLoanedPerPage) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("loanedperpage.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(LoanedPerPageVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("idAndName").description = ZH_WORDS_GETTER("loanedperpage.field.idAndName");
		info->queryParams["idAndName"].addExample("default", String(""));
		info->queryParams["idAndName"].required = false;
		info->queryParams.add<String>("pimPersonName").description = ZH_WORDS_GETTER("loanedperpage.field.pimPersonName");
		info->queryParams["pimPersonName"].addExample("default", String(""));
		info->queryParams["pimPersonName"].required = false;
		info->queryParams.add<String>("ygbh").description = ZH_WORDS_GETTER("loanedperpage.field.ygbh");
		info->queryParams["ygbh"].addExample("default", String(""));
		info->queryParams["ygbh"].required = false;
		info->queryParams.add<String>("zz").description = ZH_WORDS_GETTER("loanedperpage.field.zz1");
		info->queryParams["zz"].addExample("default", String(""));
		info->queryParams["zz"].required = false;
		info->queryParams.add<String>("bm").description = ZH_WORDS_GETTER("loanedperpage.field.bm1");
		info->queryParams["bm"].addExample("default", String(""));
		info->queryParams["bm"].required = false;
		info->queryParams.add<String>("zw").description = ZH_WORDS_GETTER("loanedperpage.field.zw1");
		info->queryParams["zw"].addExample("default", String(""));
		info->queryParams["zw"].required = false;
		info->queryParams.add<String>("gw").description = ZH_WORDS_GETTER("loanedperpage.field.gw1");
		info->queryParams["gw"].addExample("default", String(""));
		info->queryParams["gw"].required = false;
		info->queryParams.add<String>("fp").description = ZH_WORDS_GETTER("loanedperpage.field.fp");
		info->queryParams["fp"].addExample("default", String(""));
		info->queryParams["fp"].required = false;
		info->queryParams.add<String>("lx").description = ZH_WORDS_GETTER("loanedperpage.field.lx");
		info->queryParams["lx"].addExample("default", String(""));
		info->queryParams["lx"].required = false;
		info->queryParams.add<String>("fpzt").description = ZH_WORDS_GETTER("loanedperpage.field.fpzt");
		info->queryParams["fpzt"].addExample("default", String(""));
		info->queryParams["fpzt"].required = false;
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/query-LoanedPerPage", queryLoanedPerPage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, LoanedPerPageQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryLoanedPerPage(userQuery, authObject->getPayload()));
	}
	//导出功能
	ENDPOINT_INFO(queryExportLoanedPer) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("loanedperpage.export.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//定义分页参数
		// 定义分页参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("idAndName").description = ZH_WORDS_GETTER("loanedperpage.field.idAndName");
		info->queryParams["idAndName"].addExample("default", String(""));
		info->queryParams["idAndName"].required = false;
		info->queryParams.add<String>("pimPersonName").description = ZH_WORDS_GETTER("loanedperpage.field.pimPersonName");
		info->queryParams["pimPersonName"].addExample("default", String(""));
		info->queryParams["pimPersonName"].required = false;
		info->queryParams.add<String>("ygbh").description = ZH_WORDS_GETTER("loanedperpage.field.ygbh");
		info->queryParams["ygbh"].addExample("default", String(""));
		info->queryParams["ygbh"].required = false;
		info->queryParams.add<String>("zz").description = ZH_WORDS_GETTER("loanedperpage.field.zz1");
		info->queryParams["zz"].addExample("default", String(""));
		info->queryParams["zz"].required = false;
		info->queryParams.add<String>("bm").description = ZH_WORDS_GETTER("loanedperpage.field.bm1");
		info->queryParams["bm"].addExample("default", String(""));
		info->queryParams["bm"].required = false;
		info->queryParams.add<String>("zw").description = ZH_WORDS_GETTER("loanedperpage.field.zw1");
		info->queryParams["zw"].addExample("default", String(""));
		info->queryParams["zw"].required = false;
		info->queryParams.add<String>("gw").description = ZH_WORDS_GETTER("loanedperpage.field.gw1");
		info->queryParams["gw"].addExample("default", String(""));
		info->queryParams["gw"].required = false;
		info->queryParams.add<String>("fp").description = ZH_WORDS_GETTER("loanedperpage.field.fp");
		info->queryParams["fp"].addExample("default", String(""));
		info->queryParams["fp"].required = false;
		info->queryParams.add<String>("lx").description = ZH_WORDS_GETTER("loanedperpage.field.lx");
		info->queryParams["lx"].addExample("default", String(""));
		info->queryParams["lx"].required = false;
		info->queryParams.add<String>("fpzt").description = ZH_WORDS_GETTER("loanedperpage.field.fpzt");
		info->queryParams["fpzt"].addExample("default", String(""));
		info->queryParams["fpzt"].required = false;
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/get-loanedPer", queryExportLoanedPer, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, LoanedPerPageQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execExportLoanedPer(userQuery, authObject->getPayload()));
	}

private:
	// 演示分页查询数据
	LoanedPerPageVO::Wrapper execQueryLoanedPerPage(const LoanedPerPageQuery::Wrapper& query, const PayloadDTO& payload);
	// 借调人员信息导出
	StringJsonVO::Wrapper execExportLoanedPer(const LoanedPerPageQuery::Wrapper& query, const PayloadDTO& payload);
};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _LOANEDPERPAGE_CONTROLLER_