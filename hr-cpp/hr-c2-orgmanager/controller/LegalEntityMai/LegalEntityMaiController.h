#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/16 14:48:37

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
#ifndef _LEGALENTITYMAICONTROLLER_H_
#define _LEGALENTITYMAICONTROLLER_H_

#include "domain/query/LegalEntityMai/LegalEntityMaiQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/LegalEntityMai/LegalEntityMaiDTO.h"
#include "domain/vo/LegalEntityMai/LegalEntityMaiVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)
namespace multipart = oatpp::web::mime::multipart;

/* 法人主体维护，控制器*/
class LegalEntityMaiController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(LegalEntityMaiController);
public: // 定义接口
	// 定义查询法人主体信息接口描述
	ENDPOINT_INFO(queryLEM) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.query.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(LegalEntityMaiPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		info->queryParams.add<String>("ORMSIGNORGID").description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
		info->queryParams["ORMSIGNORGID"].addExample("default", String("11F28C41-1D50-4503-B925-D86D1F70A1D2"));
		info->queryParams.add<String>("UPDATEMAN").description = ZH_WORDS_GETTER("LegalEntityMai.field.updateman");
		info->queryParams["UPDATEMAN"].addExample("default", String("guest"));
		info->queryParams.add<String>("CREATEMAN").description = ZH_WORDS_GETTER("LegalEntityMai.field.createman");
		info->queryParams["CREATEMAN"].addExample("default", String("1944DE89-8E28-4D10-812C-CAEEAAE8A927"));
		info->queryParams.add<String>("CREATEDATE").description = ZH_WORDS_GETTER("LegalEntityMai.field.createdate");
		info->queryParams["CREATEDATE"].addExample("default", String("2019-09-10 20:45:00"));
		info->queryParams.add<String>("ORMSIGNORGNAME").description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
		info->queryParams["ORMSIGNORGNAME"].addExample("default", String(ZH_WORDS_GETTER("LegalEntityMai.sample.name")));
		info->queryParams.add<String>("UPDATEDATE").description = ZH_WORDS_GETTER("LegalEntityMai.field.updatedate");
		info->queryParams["UPDATEDATE"].addExample("default", String("2020-05-29 10:49:53"));
		info->queryParams.add<String>("ORGCODE").description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
		info->queryParams["ORGCODE"].addExample("default", String("104"));
	}
	// 定义查询法人主体信息接口处理
	ENDPOINT(API_M_GET, "/QueryLEM", queryLEM, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(legalEntityMaiQuery, LegalEntityMaiQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryLEM(legalEntityMaiQuery));
	}

	// 定义更新法人主体信息接口描述
	ENDPOINT_INFO(updateLEM) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义更新法人主体信息接口处理
	ENDPOINT(API_M_PUT, "/UpdateLEM", updateLEM, BODY_DTO(LegalEntityMaiDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execUpdateLEM(dto));
	}

	// 定义新增法人主体接口描述
	ENDPOINT_INFO(addLEM) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/AddLEM", addLEM, BODY_DTO(LegalEntityMaiDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddLEM(dto));
	}

	// 定义删除法人主体接口描述
	ENDPOINT_INFO(removeLEM) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_DEL, "/RemoveLEM", removeLEM, BODY_DTO(LegalEntityMaiDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveLEM(dto));
	}
private: // 定义接口执行函数
	// 分页查询数据
	LegalEntityMaiPageJsonVO::Wrapper execQueryLEM(const LegalEntityMaiQuery::Wrapper& legalEntityMaiQuery);
	// 更新数据
	Uint64JsonVO::Wrapper execUpdateLEM(const LegalEntityMaiDTO::Wrapper& dto);
	// 新增数据
	Uint64JsonVO::Wrapper execAddLEM(const LegalEntityMaiDTO::Wrapper& dto);
	// 删除数据
	Uint64JsonVO::Wrapper execRemoveLEM(const LegalEntityMaiDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_LEGALENTITYMAICONTROLLER_H_