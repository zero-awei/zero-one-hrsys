#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: shiyu(xunzhao)
 @Date: 2022/10/25 10:58:42

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

#include "./domain/do/JobTitle/JobTitleDo.h"  
#include "./domain/vo/JobTitle/JobTitleJsonVO.h"
#include "./domain/query/JobTitle/JobTitleQuery.h"
#include "./domain//vo/BaseJsonVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"
#include "./Macros.h"

using namespace std;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class JobTitleController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(JobTitleController);
public:
	// 职称查询(分页查询)接口描述
	ENDPOINT_INFO(queryJobTitle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("title.query.summary");
		// 定义响应参数格式 -- 分页查询JsonVO
		API_DEF_ADD_RSP_JSON_WRAPPER(JTQueryPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 无其他参数描述---返回职称信息表中所有数据
	}
	// 职称查询(分页查询)接口
	ENDPOINT(API_M_GET, "/jobtitle-query", queryJobTitle, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数 , 将解析的查询参数给queryPage
		API_HANDLER_QUERY_PARAM(queryPage, PageQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryPage(queryPage));
	}

	// 职称查询(分页查询-用于搜索框-需要传递两个参数)接口描述
	ENDPOINT_INFO(queryJobTitleSB) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("title.query.search-box");
		// 定义响应参数格式 -- 分页查询JsonVO
		API_DEF_ADD_RSP_JSON_WRAPPER(JTQueryPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 含有两个参数
		info->queryParams.add<UInt64>("id").description = ZH_WORDS_GETTER("title.field.id");
		info->queryParams["id"].addExample("default", UInt64(1));
		info->queryParams["id"].required = false;
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("title.field.name");
		info->queryParams["name"].addExample("default", String(""));
		info->queryParams["name"].required = false;
	}
	// 职称查询(分页查询)接口
	ENDPOINT(API_M_GET, "/jobtitle-query-searchbox", queryJobTitleSB, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数 , 将解析的查询参数给queryPage
		API_HANDLER_QUERY_PARAM(queryPage, JobTitleQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryPageSB(queryPage));
	}

	// 删除职称
	ENDPOINT_INFO(removeJobTitle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("title.delete.summary");
		// 定义响应参数格式 -- 返回删除成功与否
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// 定义参数,根据id移除植职务
		info->queryParams.add<UInt64>("id").description = ZH_WORDS_GETTER("title.field.id");
		info->queryParams["id"].addExample("default", UInt64(1));
		info->queryParams["id"].required = false;
	}
	// 删除职称接口
	ENDPOINT(API_M_DEL, "/jobtitle-remove", removeJobTitle, BODY_DTO(JobTitleDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveJobTitle(dto));
	}

	// 新增职称接口描述
	ENDPOINT_INFO(addJobTitle) {
		info->summary = ZH_WORDS_GETTER("title.add.summary");
		// 定于响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 新增职称接口
	ENDPOINT(API_M_POST, "/jobtitle-add", addJobTitle, BODY_DTO(JobTitleDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddJobTitle(dto));

	}
private:
	JTQueryPageJsonVO::Wrapper execQueryPage(const PageQuery::Wrapper& query);
	JTQueryPageJsonVO::Wrapper execQueryPageSB(const JobTitleQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execRemoveJobTitle(const JobTitleDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execAddJobTitle(const JobTitleDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController)  // <- end
