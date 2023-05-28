#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/15 21:03:55

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
#ifndef _MILITARYCONTROLLER_H_
#define _MILITARYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/military/MilitaryQuery.h"
#include "domain/vo/military/MilitaryVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MilitaryController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(MilitaryController);
public: // 定义接口
	//查看指定员工军转干部(指定军转干部详情)
	ENDPOINT_INFO(queryMilitary) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("military.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(MilitaryJsonVO);
		// 添加其他查询参数
		info->queryParams.add<String>("PIMARMYCADRESID").description = ZH_WORDS_GETTER("military.PIMARMYCADRESID");
		info->queryParams["PIMARMYCADRESID"].addExample("default", String("0453FC72-E19C-43E0-984C-4406706EB79E"));
	}
	ENDPOINT(API_M_GET, "/military/select", queryMilitary, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, MilitaryDetailQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryMilitary(query));
	}
	//修改指定员工军转干部(单条修改)
	ENDPOINT_INFO(modifyMilitary) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("military.put.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_PUT, "/military/modify", modifyMilitary, API_HANDLER_AUTH_PARAME, BODY_DTO(MilitaryDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyMilitary(dto, authObject->getPayload()));
	}
	//导出指定员工军转干部(导出本页在前端完成)
	ENDPOINT_INFO(downloadMilitary) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("military.download.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 添加其他查询参数
		info->queryParams.add<String>("PIMPERSONID").description = ZH_WORDS_GETTER("military.PIMPERSONID");
		info->queryParams["PIMPERSONID"].addExample("default", String("66958E87-91A4-4DA8-8124-060E93B47EBE"));
	}
	ENDPOINT(API_M_POST, "/military/download", downloadMilitary, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, MilitaryDownloadQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execDownloadMilitary(query));
	}
private: // 定义接口执行函数
	MilitaryJsonVO::Wrapper execQueryMilitary(const MilitaryDetailQuery::Wrapper& query);
	StringJsonVO::Wrapper execModifyMilitary(const MilitaryDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDownloadMilitary(const MilitaryDownloadQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_MILITARYCONTROLLER_H_