#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/15 15:25:13

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
#ifndef _MHCONSTROLLER_H_
#define _MHCONSTROLLER_H_

#include "ApiHelper.h"
#include "domain/query/PageQuery.h"
#include "domain/vo/BaseJsonVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

// 1 继承控制器
class LaborDispatchConstroller : public oatpp::web::server::api::ApiController
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(LaborDispatchConstroller);
public: 
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryCorlist) {
		// 定义接口标题
		info->summary = "query corporation lists";

		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("PIMLABOURCAMPANYNAME").description = "劳务公司";
		info->queryParams["PIMLABOURCAMPANYNAME"].addExample("default", String("moumouyouxiangongsi"));
		info->queryParams["PIMLABOURCAMPANYNAME"].required = false;
	}
	// 4 定义接口端点
	ENDPOINT(API_M_GET, "/query", queryCorlist, QUERIES(QueryParams, qcl)) {
		//解析查询参数
		API_HANDLER_QUERY_PARAM(query, PageQuery, qcl);
		//响应结果
		API_HANDLER_RESP_VO(executeQueryAll(query));
	}
private: 
	// 5 定义接口执行函数
	StringJsonVO::Wrapper executeQueryAll(const PageQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_MHCONSTROLLER_H_