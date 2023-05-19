#pragma once
#ifndef _AuditstatusCONTROLLER_H_
#define _AuditstatusCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/auditstatusQuery/AuditstatusQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/auditstatusVO/AuditstatusVO.h"
//#include "domain/vo/user/MenuVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class AuditstatusController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(AuditstatusController);
public:
	// 定义查询所有用户信息接口端点描述
	ENDPOINT_INFO(queryAuditstatus) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("auditstatus query");
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AuditstatusJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}

	// 定义查询所有用户信息接口端点处理
	ENDPOINT(API_M_GET, "/auditstatusQuery", queryAuditstatus, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, AuditstatusQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryAuditstatus(userQuery, authObject->getPayload()));
	}
	
private:
	// 查询所有
	StringJsonVO::Wrapper execQueryAuditstatus(const AuditstatusQuery::Wrapper& auditstatusQuery);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _AuditstatusCONTROLLER_H_