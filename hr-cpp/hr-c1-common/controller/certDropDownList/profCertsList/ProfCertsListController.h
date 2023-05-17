#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 8:27:04

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
#ifndef _PROFCERTSLIST_CONTROLLER_
#define _PROFCERTSLIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/certs/ProfCertsQuery.h"
#include "domain/dto/certs/ProfCertsDTO.h"
#include "domain/vo/certs/ProfCertsVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 职业资格证书类型下拉列表控制器
 */
class ProfCertsListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ProfCertsListController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryProfCertsList) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("queryProfCertsList");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProfCertsPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/query-Prof-Certs", queryProfCertsList, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {			
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(profCertsQuery, ProfCertsQuery, queryParams);*/
		// 响应结果
		API_HANDLER_RESP_VO(execQueryProfCertsList(profCertsQuery, authObject->getPayload()));
	}
private:
	ProfCertsPageJsonVO::Wrapper execQueryProfCertsList(const ProfCertsQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PROFCERTSLIST_CONTROLLER_