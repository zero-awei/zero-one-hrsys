#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 16:37:51

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
#ifndef _POSTQUERY_CONTROLLER_
#define _POSTQUERY_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/postSet/PostDetailQuery.h"
#include "domain/dto/postSet/PostDetailDTO.h"
#include "domain/vo/postSet/PostDetailVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 岗位设置 - 查询指定岗位详情控制器
 * 返回值 : PostDetailPageJsonVO - 返回一个分页岗位查询列表
 * 负责人 : rice
 */
class PostQueryController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PostQueryController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryByQuerySort) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("orgmanage.controller.postQuery");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PostDetailPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("queryPostName").description = u8"查询岗位";
		info->queryParams["queryPostName"].addExample("default", String(u8"人事管理岗"));
		info->queryParams["queryPostName"].required = true;
		info->queryParams.add<String>("sortTypeAndMethod").description = u8"排序类别以及升序或降序";
		info->queryParams["sortTypeAndMethod"].addExample("default", String(u8"xh,ASC"));
		info->queryParams["sortTypeAndMethod"].required = true;
		API_DEF_ADD_AUTH();
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, PATH_TO_JOBSET("/query-by-query-sort"), queryByQuerySort, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(postDetailQuery, PostDetailQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryByQuerySort(postDetailQuery));
	}
	
private:
	// 查询指定岗位详情
	PostDetailPageJsonVO::Wrapper execQueryByQuerySort(const PostDetailQuery::Wrapper& postDetailQuery);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _POSTQUERY_CONTROLLER_