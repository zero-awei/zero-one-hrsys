#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/20 22:08:49

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
#ifndef _LEAVEREASONCONTROLLER_H_
#define _LEAVEREASONCONTROLLER_H_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/pullList/PullListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 解聘原因Controller
 * 接收前端请求，查询解聘原因并组装成列表返回
 * 负责人：远翔
 */
class LeaveReasonController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(LeaveReasonController);
public: // 定义接口
	ENDPOINT_INFO(queryLeaveReason) {
		info->summary = ZH_WORDS_GETTER("common.controller.leaveReason");
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListVO);
		API_DEF_ADD_AUTH();
	}

	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/leave-reason"), queryLeaveReason, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryLeaveReason());
	}
private: // 定义接口执行函数
	PullListVO::Wrapper execQueryLeaveReason();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_LEAVEREASONCONTROLLER_H_