#pragma once
#ifndef _COSTTYPELISTCONTROLLER_H_
#define _COSTTYPELISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/vo/pullList/PullListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class CostTypeListController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(CostTypeListController);
public: // 定义接口
	ENDPOINT_INFO(queryCostType) {
		info->summary = ZH_WORDS_GETTER("common.controller.costType");
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListVO);
	}

	ENDPOINT(API_M_GET, "/pull-list/cost-type", queryCostType) {
		API_HANDLER_RESP_VO(execQueryCostType());
	}
private: // 定义接口执行函数
	PullListVO::Wrapper execQueryCostType();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_COSTTYPELISTCONTROLLER_H_