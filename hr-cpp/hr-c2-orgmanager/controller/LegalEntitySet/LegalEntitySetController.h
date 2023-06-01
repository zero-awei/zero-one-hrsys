#pragma once
/*
组织管理 ——数据设置 —— 法人主体设置  -- cpt

法人主体名称下拉列表 `LegalEntitySetPullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `LegalEntitySet`

新增法人设置（支持批量新增）** `LegalEntitySet`
*/ 

// LegalEntitySetController

#pragma once

#ifndef _LEGALENTITYSET_CONTROLLER_
#define _LEGALENTITYSET_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/LegalEntitySet/LegalEntitySetDO.h"
#include "domain/dto/LegalEntitySet/LegalEntitySetDTO.h"
#include "domain/vo/LegalEntitySet/LegalEntitySetVO.h"
#include "domain/query/LegalEntitySet/LegalEntitySetQuery.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class LegalEntitySetController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(LegalEntitySetController); // 2 定义控制器访问入口
public:

	ENDPOINT_INFO(LegalEntitySet) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/org/add-LegalerSeting", LegalEntitySet, BODY_DTO(LegalEntitySetDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddLegalEntitySet(dto));
	}

	ENDPOINT_INFO(queryLegalEntitySet) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.export.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(LegalEntitySetPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/org/export-LegalerSeting", queryLegalEntitySet, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, LegalEntitySetQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execExportLegalEntitySet(userQuery, authObject->getPayload()));
	}

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryLegalEntitySetPullDownList) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.query.summary3");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(LegalEntitySetPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/org/query-LegalEntitySetPullDownList", queryLegalEntitySetPullDownList, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, LegalEntitySetQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execLegalEntitySetPullDownList());
	}

	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyLegalEntitySet) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("EmpInfo.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/org/update-LegalEntitySet", modifyLegalEntitySet, BODY_DTO(LegalEntitySetDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyLegalEntitySet(dto));
	}

	/* ---------------------------法人主体设置控制器设计--（组织管理-数据设置-法人主体设置）--TripleGold ----------------------------*/
	// 定义查询法人主体信息接口描述
	ENDPOINT_INFO(queryLES) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.query.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(LegalEntitySetPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		info->queryParams.add<String>("ormsignorgname").description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgname");
		info->queryParams["ormsignorgname"].addExample("default", String(ZH_WORDS_GETTER("LegalEntitySet.sample.name1")));
		info->queryParams["ormsignorgname"].required = false;
		info->queryParams.add<String>("contractsignorgname").description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgname");
		info->queryParams["contractsignorgname"].addExample("default", String(ZH_WORDS_GETTER("LegalEntitySet.sample.name2")));
		info->queryParams["contractsignorgname"].required = false;
	}
	// 定义查询法人主体信息接口处理
	ENDPOINT(API_M_GET, "/org/query-LES", queryLES, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(legalEntitySetQuery, LegalEntitySetQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryLES(legalEntitySetQuery));
	}

private:
	Uint64JsonVO::Wrapper execAddLegalEntitySet(const LegalEntitySetDTO::Wrapper& dto);

	LegalEntitySetPageJsonVO::Wrapper execExportLegalEntitySet(const LegalEntitySetQuery::Wrapper& query, const PayloadDTO& payload);

	LegalEntitySetPullDownJsonVO::Wrapper execLegalEntitySetPullDownList();
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyLegalEntitySet(const LegalEntitySetDTO::Wrapper& dto);
	// 分页查询数据
	LegalEntitySetPageJsonVO::Wrapper execQueryLES(const LegalEntitySetQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _LEGALENTITYSET_CONTROLLER_

