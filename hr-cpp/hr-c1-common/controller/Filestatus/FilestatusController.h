#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/17 16:46:06

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
#ifndef _FILESTATUSCONTROLLER_H_
#define _FILESTATUSCONTROLLER_H_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/filestatus/FilestatusQuery.h"
#include "domain/vo/filestatus/FilestatusVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

using namespace oatpp;
class FilestatusController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(FilestatusController);
public: // 定义接口
	ENDPOINT_INFO(queryFileStatusList) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("filestatus.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SamplePageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		/*info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("sample.field.sex");
		info->queryParams["sex"].addExample("default", String("N"));
		info->queryParams["sex"].required = false;*/
	}
	ENDPOINT(API_M_GET, "/list/file-status", queryFileStatus, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		//// 解析查询参数
		//API_HANDLER_QUERY_PARAM(userQuery, UserQuery, queryParams);
		//// 响应结果
		//API_HANDLER_RESP_VO(executeQueryAll(userQuery));
	}
private: // 定义接口执行函数
	
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILESTATUSCONTROLLER_H_