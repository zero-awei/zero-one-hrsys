#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/18 22:51:37

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
#ifndef _ARMYLEVELTYPECONTROLLER_H_
#define _ARMYLEVELTYPECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/vo/pullList/PullListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 军转级别下拉列表控制器
 * 接收前端请求，查询军转级别并组装成列表返回
 * 负责人：Andrew
 */
class ArmyLevelTypeController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ArmyLevelTypeController);
public: // 定义接口
	ENDPOINT_INFO(queryArmyLevelType) {
		info->summary = ZH_WORDS_GETTER("common.controller.armyLevelType");
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListVO);
	}
	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/army-level-type"), queryArmyLevelType, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryArmyLevelType());
	}
private: // 定义接口执行函数
	PullListVO::Wrapper execQueryArmyLevelType();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ARMYLEVELTYPECONTROLLER_H_