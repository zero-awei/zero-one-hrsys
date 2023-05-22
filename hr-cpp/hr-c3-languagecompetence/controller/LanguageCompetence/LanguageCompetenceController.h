#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
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
#include "domain/vo/Language/LanguageVO.h"
#include "domain/query/LanguagePage/LanguagePageQuery.h"
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
	// 定义分页查询接口描述
	ENDPOINT_INFO(queryLanguage) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("language.get.summarys");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
	}
	//定义分页查询接口处理
	//API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/user/query-langugae", queryLanguage, LanguagePageQuery, execQueryLanguage(query, authObject->getPayload()));
	ENDPOINT(API_M_GET, "/user/query-langugae", queryLanguage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		//解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, LanguagePageQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryLanguage(userQuery, authObject->getPayload()));
	}
	// 定义查询接口描述
	ENDPOINT_INFO(queryOneLanguage) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("language.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义其他表单参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
	}
	//定义查询接口处理
	ENDPOINT(API_M_GET, "/user/query-one-langugae", queryOneLanguage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		//解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, LanguageQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryOneLanguage(userQuery, authObject->getPayload()));
	}
	//定义新增接口描述
	ENDPOINT_INFO(addLanguage) {
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("language.post.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//定义新增接口处理
	ENDPOINT(API_M_POST, "/user/add-language", addLanguage, API_HANDLER_AUTH_PARAME, BODY_DTO(LanguageDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddLanguage(dto, authObject->getPayload()));
	}
	//定义删除接口描述
	ENDPOINT_INFO(deleteLanguage) {
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("language.delete.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//定义删除接口处理
	ENDPOINT(API_M_DEL, "/user/delete-language", deleteLanguage, API_HANDLER_AUTH_PARAME, BODY_DTO(LanguageDTO::Wrapper, dto)) {
		//响应结果
		API_HANDLER_RESP_VO(execDeleteLanguage(dto, authObject->getPayload()));
	}
	//定义修改接口描述
	ENDPOINT_INFO(updateLanguage) {
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("language.put.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//定义修改接口处理
	ENDPOINT(API_M_PUT, "/user/update-language", updateLanguage, API_HANDLER_AUTH_PARAME, BODY_DTO(LanguageDTO::Wrapper, dto)) {
		//响应结果
		API_HANDLER_RESP_VO(execUpdateLanguage(dto, authObject->getPayload()));
	}
	//定义一个单文件上传接口描述
	ENDPOINT_INFO(uploadFile)
	{
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("language.post.file");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义其他表单参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "url", ZH_WORDS_GETTER("user.file.url"), "", true);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, false);
	};
	//定义一个单文件上传接口处理
	ENDPOINT(API_M_POST, "/user/upload-language", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* 创建multipart容器 */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* 创建multipart读取器 */
		multipart::Reader multipartReader(multipartContainer.get());
		/* 配置读取器读取表单字段 */
		multipartReader.setPartReader("languagetype", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("languagelevel", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		/* 配置读取器读取文件到文件 */
		multipartReader.setPartReader("file", multipart::createFilePartReader("public/static/file/test.png"));
		/* 读取请求体中的数据 */
		request->transferBody(&multipartReader);
		/* 打印part数量 */
		OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
		/* 获取表单数据 */
		auto type = multipartContainer->getNamedPart("languagetype");
		auto level = multipartContainer->getNamedPart("languagelevel");
		/* 断言表单数据是否正确 */
		OATPP_ASSERT_HTTP(type, Status::CODE_400, "LanguageType is null");
		OATPP_ASSERT_HTTP(level, Status::CODE_400, "LanguageLevel is null");
		/* 打印应表单数据 */
		OATPP_LOGD("Multipart", "LanguageType='%s'", type->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "LanguageLevel='%s'", level->getPayload()->getInMemoryData()->c_str());
		/* 获取文件部分 */
		auto filePart = multipartContainer->getNamedPart("file");
		/* 断言文件是否获取到 */
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
		/* 打印文件名称 */
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
		/* 响应OK */
		return createResponse(Status::CODE_200, "OK");
	}
private: // 定义接口执行函数
	//定义分页查询接口执行函数
	StringJsonVO::Wrapper execQueryLanguage(const LanguagePageQuery::Wrapper& query, const PayloadDTO& payload);
	//定义查询接口接口执行函数
	StringJsonVO::Wrapper execQueryOneLanguage(const LanguageQuery::Wrapper& query, const PayloadDTO& payload);
	//定义新增接口执行函数
	//Uint64JsonVO::Wrapper execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	//定义删除接口执行函数
	//Uint64JsonVO::Wrapper execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	//定义修改接口执行函数
	//Uint64JsonVO::Wrapper execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_LANGUAGECOMPETENCECONTROLLER_H_