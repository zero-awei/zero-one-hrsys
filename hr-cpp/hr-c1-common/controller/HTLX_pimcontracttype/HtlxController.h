#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/19 21:18:10

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
#ifndef _HTLX_CONTROLLER_
#define _HTLX_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/vo/HTLX_pimcontracttype/HtlxVO.h"
#include "domain/dto/HTLX_pimcontracttype/HtlxDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)
/*
合同类别下拉列表控制器
*/
class HtlxController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(HtlxController);
public: // 定义接口
	ENDPOINT_INFO(queryHtlx) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("htlx.pull-list.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(HtlxJsonVO);
	}
	ENDPOINT(API_M_GET, "/htlx/pull-list", queryHtlx) {
		// 响应结果
		API_HANDLER_RESP_VO(execQueryHtlx());
	}
	
private: // 定义接口执行函数
	HtlxJsonVO::Wrapper execQueryHtlx();
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_HTLX_CONTROLLER_