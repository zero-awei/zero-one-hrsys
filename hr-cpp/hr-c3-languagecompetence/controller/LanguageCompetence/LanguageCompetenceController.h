#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/18 23:03:24

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
#ifndef _LANGUAGECOMPETENCECONTROLLER_H_
#define _LANGUAGECOMPETENCECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/Language/LanguageQuery.h"
#include "domain/dto/Language/LanguageDTO.h"
#include "domain/dto/ImportLanguage/ImportLanguageDTO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

class LanguageCompetenceController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(LanguageCompetenceController);
public: // 定义接口
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryLanguage) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("language.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
	}
	//定义查询接口处理
	ENDPOINT(API_M_GET, "/language/query-by-id", queryLanguage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		//解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, LanguageQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryLanguage(userQuery, authObject->getPayload()));
	}
	//定义新增接口描述
	ENDPOINT_INFO(addLanguage) {
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("language.post.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//定义新增接口处理
	ENDPOINT(API_M_POST, "/language/add-by-id", addLanguage, API_HANDLER_AUTH_PARAME, BODY_DTO(LanguageDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddLanguage(dto));
	}
	//定义删除接口描述
	ENDPOINT_INFO(deleteLanguage) {
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("language.delete.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//定义删除接口处理
	ENDPOINT(API_M_DEL, "/language/delete-by-id", deleteLanguage, API_HANDLER_AUTH_PARAME, BODY_DTO(LanguageDTO::Wrapper, dto)) {
		//响应结果
		API_HANDLER_RESP_VO(execDeleteLanguage(dto));
	}
	//定义修改接口描述
	ENDPOINT_INFO(updateLanguage) {
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("language.put.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//定义修改接口处理
	ENDPOINT(API_M_PUT, "/Language/update-by-id", updateLanguage, API_HANDLER_AUTH_PARAME, BODY_DTO(LanguageDTO::Wrapper, dto)) {
		//响应结果
		API_HANDLER_RESP_VO(execUpdateLanguage(dto));
	}
private: // 定义接口执行函数
	//定义查询接口执行函数
	StringJsonVO::Wrapper execQueryLanguage(const LanguageQuery::Wrapper& query, const PayloadDTO& payload);
	//定义新增接口执行函数
	Uint64JsonVO::Wrapper execAddLanguage(const LanguageDTO::Wrapper& dto);
	//定义删除接口执行函数
	Uint64JsonVO::Wrapper execDeleteLanguage(const LanguageDTO::Wrapper& dto);
	//定义修改接口执行函数
	Uint64JsonVO::Wrapper execUpdateLanguage(const LanguageDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_LANGUAGECOMPETENCECONTROLLER_H_