#pragma once
#ifndef _AuditStatusCONTROLLER_H_
#define _AuditStatusCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/auditStatusQuery/AuditStatusQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/pullList/PullListVO.h"
#include <ApiHelper.h>
//#include "domain/vo/user/MenuVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class AuditStatusController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(AuditStatusController);
public:
	// 定义查询所有用户信息接口端点描述
	ENDPOINT_INFO(queryAuditStatus) {
		
		info->summary = ZH_WORDS_GETTER("common.controller.auditStatus");
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListVO);
	}
		
	ENDPOINT(API_M_GET, "/audit-status-pull-list", queryAuditStatus) {
		API_HANDLER_RESP_VO(execQueryAuditStatus());
	}

	
	
private:
	// 定义接口执行函数
	PullListVO::Wrapper execQueryAuditStatus();
	
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _AuditStatusCONTROLLER_H_