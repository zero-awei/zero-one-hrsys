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
#ifndef _SCIENTIFICCONTROLLER_H_
#define _SCIENTIFICCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/scientific/ScientificQuery.h"
#include "domain/vo/scientific/ScientificVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ScientificController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ScientificController);
public: // 定义接口
	//查看指定员工科研成果(指定科研成果详情)
	ENDPOINT_INFO(queryScientific) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("scientific.get.summary");
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(ScientificJsonVO);
		// 添加其他查询参数
		info->queryParams.add<String>("pimresearchfindingsid").description = ZH_WORDS_GETTER("scientific.pimresearchfindingsid");
		info->queryParams["pimresearchfindingsid"].addExample("default", String("167CEAAD-F15E-45E1-B1C4-50DAD227B3BF"));
	}
	ENDPOINT(API_M_GET, "/scientific/select", queryScientific, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, ScientificViewQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryScientific(query));
	}
	//修改指定科研成果(单条修改)
	ENDPOINT_INFO(modifyScientific) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("scientific.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_PUT, "/scientific/modify", modifyScientific, BODY_DTO(ScientificDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyScientific(dto));
	}
	//导出指定员工科研成果(导出本页在前端完成)
	ENDPOINT_INFO(downloadScientific) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("scientific.download.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 添加其他查询参数
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("scientific.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("EA3AE5AA-2318-4C84-AAF7-99CBDE9BA27B"));
	}
	ENDPOINT(API_M_POST, "/scientific/download", downloadScientific, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, ScientificDownloadQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execDownloadScientific(query));
	}
private: // 定义接口执行函数
	ScientificJsonVO::Wrapper execQueryScientific(const ScientificViewQuery::Wrapper& query);
	StringJsonVO::Wrapper execModifyScientific(const ScientificDTO::Wrapper& dto);
	StringJsonVO::Wrapper execDownloadScientific(const ScientificDownloadQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_SCIENTIFICCONTROLLER_H_