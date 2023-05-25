#pragma once
#ifndef _EXPORTLEGALERSETTING_CONTROLLER_
#define _EXPORTLEGALERSETTING_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/LegalEntitySet/ExportLegalerSetingDO.h"
#include "domain/dto/LegalEntitySet/ExportLegalerSetingDTO.h"
#include "domain/query/LegalEntitySet/ExportLegalerSetingQuery.h"
#include "domain/vo/LegalEntitySet/ExportLegalerSetingVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ExportLegalerSetingController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(ExportLegalerSetingController); // 2 定义控制器访问入口
public:
	ENDPOINT_INFO(queryExportLegalerSeting) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.export.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ExportLegalerSetingPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/org/export-LegalerSeting", queryExportLegalerSeting, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, ExportLegalerSetingQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execExportLegalerSeting(userQuery, authObject->getPayload()));
	}
private:
	ExportLegalerSetingPageJsonVO::Wrapper execExportLegalerSeting(const ExportLegalerSetingQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPORTLEGALERSETTING_CONTROLLER_

