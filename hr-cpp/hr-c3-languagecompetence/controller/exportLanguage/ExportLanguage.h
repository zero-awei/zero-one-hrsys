#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/25 0:43:45

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
#ifndef _EXPORTLANGUAGE_H_
#define _EXPORTLANGUAGE_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/dto/downloadLanguage/DownloadLanguageDTO.h"
#include "domain/query/employeeLanguareQuery/EmployeeLanguageExportQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
/**
 * 语言能力控制器 - 导出语言
 * 负责人：君
 */
class ExportLanguageController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ExportLanguageController);
public: // 定义接口
	ENDPOINT_INFO(downloadLanguage) {
		info->summary = ZH_WORDS_GETTER("language.get.downloadurl");
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("0000001"));
		info->queryParams["id"].required = true;
	}
	ENDPOINT(API_M_GET, "/c3-language-info/download-language", downloadLanguage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, EmployeeLanguageExportQuery, qps);
		API_HANDLER_RESP_VO(execDownloadLanguage(query));
	}
private: // 定义接口执行函数
	StringJsonVO::Wrapper execDownloadLanguage(const EmployeeLanguageExportQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EXPORTLANGUAGE_H_