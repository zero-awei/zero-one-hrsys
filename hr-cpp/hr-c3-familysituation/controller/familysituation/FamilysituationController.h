#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Marvin
 @Date: 2023/05/18 19:52:51

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
#ifndef _FAMILYSITUATIONCONTROLLER_H_
#define _FAMILYSITUATIONCONTROLLER_H_

// 领域模型
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/familysituation/FamilysituationQuery.h"
#include "domain/dto/familysituation/FamilysituationDTO.h"
#include "domain/dto/familysituation/ImportfamilysituationDTO.h"
#include "domain/vo/familysituation/FamilysituationVO.h"
#include "domain/query/familysituation/FamilysituationQuery.h"

// API助手
#include "ApiHelper.h"
#include "CharsetConvertHepler.h"

// 文件上传
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 家庭情况控制器
 **/
class FamilysituationController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(FamilysituationController);
public: // 定义接口
	// 定义查询描述
 	ENDPOINT_INFO(queryFamilysituation)
 	{
 		//定义标题
 		info->summary = ZH_WORDS_GETTER("familysituation.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
 		// 定义响应参数格式
 		API_DEF_ADD_RSP_JSON_WRAPPER(FamilysituationPageJsonVO);
 		// 定义分页参数描述
 		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("personid").description = ZH_WORDS_GETTER("familysituation.field.personid");
		info->queryParams["personid"].addExample("default", String("0002CC75-F8EB-45B3-A359-0310EC7F6D5B"));
 	}
 	// 定义查询接口处理
 	ENDPOINT(API_M_GET, "/c3-family-info/family-query", queryFamilysituation, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams))
 	{
 		// 解析查询参数
 		API_HANDLER_QUERY_PARAM(familysituationQuery, FamilysituationQuery, queryParams);
 		// 响应结果
 		API_HANDLER_RESP_VO(execQueryByFamilysituation(familysituationQuery, authObject->getPayload()));
 	}
 	// 定义查询指定家庭情况接口描述
 	ENDPOINT_INFO(queryOneFamilysituation)
 	{
 		// 定义接口标题
 		info->summary = ZH_WORDS_GETTER("familysituation.getone.summary");
 		// 定义响应参数格式
 		API_DEF_ADD_RSP_JSON_WRAPPER(FamilysituationJsonVO);
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("familysituation.field.id");
		info->queryParams["id"].addExample("default", String("12239214873271218176"));
 	}
 	// 定义查询指定家庭情况接口处理
 	ENDPOINT(API_M_GET, "/c3-family-info/family-query-one", queryOneFamilysituation, QUERIES(QueryParams, queryParams))
 	{
 		// 解析查询参数
 		API_HANDLER_QUERY_PARAM(oneQuery, FamilysituationQuery, queryParams);
 		// 响应结果
 		API_HANDLER_RESP_VO(execOneQueryFamilysituation(oneQuery));
 	}
	// 定义添加家庭情况接口描述
	ENDPOINT_INFO(addFamilysituation)
	{
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("familysituation.post.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义添加接口处理
	ENDPOINT(API_M_POST, "/c3-family-info/family-add", addFamilysituation, API_HANDLER_AUTH_PARAME, BODY_DTO(FamilysituationDTO::Wrapper, dto))
	{
		// 响应结果
		API_HANDLER_RESP_VO(execAddFamilysituation(dto, authObject->getPayload()));
	}
	// 定义修改接口描述
	ENDPOINT_INFO(modifyFamilysituation)
	{
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("familysituation.put.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义修改接口处理
	ENDPOINT(API_M_PUT, "/c3-family-info/family-modify", modifyFamilysituation, API_HANDLER_AUTH_PARAME, BODY_DTO(FamilysituationDTO::Wrapper, dto))
	{
		// 响应结果
		API_HANDLER_RESP_VO(execModifyFamilysituation(dto, authObject->getPayload()));
	}
	// 定义删除接口描述
	ENDPOINT_INFO(removeFamilysituation)
	{
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("familysituation.del.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义删除接口处理
	ENDPOINT(API_M_DEL, "/c3-family-info/family-remove", removeFamilysituation, BODY_DTO(FamilyBatchDeleteDTO::Wrapper, dto))
	{
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveFamilysituation(dto));
	}
	// 定义导入接口描述
	ENDPOINT_INFO(importFile)
	{
		info->summary = ZH_WORDS_GETTER("familysituation.import-file.summary");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("familysituation.import-file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
	}
	// 定义导入接口处理
	ENDPOINT(API_M_POST, "/c3-family-info/family-import", importFile, BODY_STRING(String, body), QUERY(String, suffix))
	{
		// 执行文件保存和解析逻辑
		API_HANDLER_RESP_VO(executeImportFamilysituation(body, suffix));
	}
	
	// 定义导出接口描述
	ENDPOINT_INFO(exportFamilysituation)
	{
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("familysituation.export.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("sample.field.id");
		info->queryParams["id"].addExample("default", String("0000001"));
		info->queryParams["id"].required = true;
	}
	// 定义导出接口处理
	ENDPOINT(API_M_GET, "/c3-family-info/family-export", exportFamilysituation, QUERIES(QueryParams, qps))
	{
		// 响应结果
		API_HANDLER_QUERY_PARAM(query, FamilysituationQuery, qps);
		API_HANDLER_RESP_VO(execExportFamilysituation(query));
	}

private: // 定义接口执行函数
	// 查询数据响应
	FamilysituationPageJsonVO::Wrapper execQueryByFamilysituation(const FamilysituationQuery::Wrapper& query, const PayloadDTO& payload);
	// 指定查询数据响应
	FamilysituationJsonVO::Wrapper execOneQueryFamilysituation(const FamilysituationQuery::Wrapper& query);
	// 添加数据响应
	Uint64JsonVO::Wrapper execAddFamilysituation(const FamilysituationDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改数据响应
	Uint64JsonVO::Wrapper execModifyFamilysituation(const FamilysituationDTO::Wrapper& dto, const PayloadDTO& payload);
	// 删除数据响应
	Uint64JsonVO::Wrapper execRemoveFamilysituation(const FamilyBatchDeleteDTO::Wrapper& dto);
	// 导入数据响应
	StringJsonVO::Wrapper executeImportFamilysituation(const String& fileBody, const String& suffix);
	// 导出数据响应
	StringJsonVO::Wrapper execExportFamilysituation(const FamilysituationQuery::Wrapper & query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FAMILYSITUATIONCONTROLLER_H_