#pragma once
#pragma once
#ifndef _AuditstatusCONTROLLER_H_
#define _AuditstatusCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/pullList/PullListVO.h"
#include <ApiHelper.h>
//#include "domain/vo/user/MenuVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class EvaluationTypesController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(EvaluationTypesController);
public:
	// 定义查询所有用户信息接口端点描述
	ENDPOINT_INFO(queryEvaluationTypes) {

		info->summary = ZH_WORDS_GETTER("common.controller.EvaluationTypes");
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListVO);
	}

	ENDPOINT(API_M_GET, "/audit-status-pull-list", queryEvaluationTypes) {
		API_HANDLER_RESP_VO(execQueryEvaluationTypes());
	}



private:
	// 定义接口执行函数
	PullListVO::Wrapper execQueryEvaluationTypes();

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _AuditstatusCONTROLLER_H_