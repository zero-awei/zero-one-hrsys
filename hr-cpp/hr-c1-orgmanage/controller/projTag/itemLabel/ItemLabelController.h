#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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


#ifndef _ITEMLABELCONTROLLER_H_
#define _ITEMLABELCONTROLLER_H_
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/itemlabel/ItemlabelQuery.h"
#include "domain/vo/itemLabel/ItemLabelVO.h"
#include "Macros.h"
#include "CharsetConvertHepler.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 查询指定项目标签
 * 负责人：缘尘
 */
class ItemLabelController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ItemLabelController);
public: // 定义接口
	// 3 定义接口描述
	ENDPOINT_INFO(queryItemLabel) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("ormanage.dto.label");
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(ItemLabelPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("itemLabel").description = ZH_WORDS_GETTER("ormanage.dto.itemlabel");
		info->queryParams["itemLabel"].addExample("default", String(CharsetConvertHepler::ansiToUtf8("哈哈哈")));
		info->queryParams["itemLabel"].required = false;
		API_DEF_ADD_AUTH();
	}

	// 4 定义接口端点
	ENDPOINT(API_M_GET, PATH_TO_PROJTAG("/specific-project-tag"), queryItemLabel, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, ItemLabelQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryItemLabel(query));
		
	}
private: // 定义接口执行函数
	// 5 定义接口的执行函数
	ItemLabelPageJsonVO::Wrapper execQueryItemLabel(const ItemLabelQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_ITEMLABELCONTROLLER_H_