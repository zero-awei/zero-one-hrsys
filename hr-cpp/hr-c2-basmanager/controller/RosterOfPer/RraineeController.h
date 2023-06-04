#pragma once
#ifndef _PAGEQUERYEMPLOYEELIST_CONTROLLER_
#define _PAGEQUERYEMPLOYEELIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/RosterOfPer/RraineeDO.h"
#include "domain/dto/RosterOfPer/RraineeDTO.h"
#include "domain/vo/RosterOfPer/RraineeVO.h"
#include "domain/query/RosterOfPer/RraineeQuery.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

/**
 *  基础管理 —— 人员花名册 —— 见习员工  ——Cpt
 */

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

namespace multipart = oatpp::web::mime::multipart;

class RraineeController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(RraineeController); // 定义控制器访问入口
public:

	// 定义查询接口描述
	ENDPOINT_INFO(queryRrainee) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("RosterOfPer.query.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(RraineePageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		/*info->queryParams.add<String>("ygbh").description = ZH_WORDS_GETTER("RosterOfPer.field.ygbh");
		info->queryParams["ygbh"].addExample("default", String("li ming"));
		info->queryParams["ygbh"].required = false;
		info->queryParams.add<String>("pcmjxszzkhjgjlname").description = ZH_WORDS_GETTER("RosterOfPer.field.pcmjxszzkhjgjlname");
		info->queryParams["pcmjxszzkhjgjlname"].addExample("default", String(""));
		info->queryParams["pcmjxszzkhjgjlname"].required = false;*/
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/query-RraineePageQueryEmployeeList", queryRrainee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, RraineeQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execRraineeQuery(userQuery, authObject->getPayload()));
	} 

	ENDPOINT_INFO(exportRrainee) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("RosterOfPer.export.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(RraineePageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
	}

	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/export-RraineeExportEmployee", exportRrainee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, RraineeQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execRraineeExport(userQuery, authObject->getPayload()));
	}


	// 文件导出
	//ENDPOINT_INFO(exportLEM) {
	//	// 定义接口标题
	//	info->summary = ZH_WORDS_GETTER("LegalEntitySet.export.summary");
	//	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	//	API_DEF_ADD_AUTH();
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
	//	// 定义分页参数描述
	//	API_DEF_ADD_PAGE_PARAMS();
	//	// 定义其他查询参数描述
	//	info->queryParams.add<String>("ORMSIGNORGID").description = ZH_WORDS_GETTER("LegalEntitySet.field.id");
	//	info->queryParams["ORMSIGNORGID"].addExample("default", String("11F28C41-1D50-4503-B925-D86D1F70A1D2"));
	//	info->queryParams.add<String>("UPDATEMAN").description = ZH_WORDS_GETTER("LegalEntitySet.field.updateman");
	//	info->queryParams["UPDATEMAN"].addExample("default", String("guest"));
	//	info->queryParams.add<String>("CREATEMAN").description = ZH_WORDS_GETTER("LegalEntityM	ai.field.createman");
	//	info->queryParams["CREATEMAN"].addExample("default", String("1944DE89-8E28-4D10-812C-CAEEAAE8A927"));
	//	info->queryParams.add<String>("CREATEDATE").description = ZH_WORDS_GETTER("LegalEntitySet.field.createdate");
	//	info->queryParams["CREATEDATE"].addExample("default", String("2019-09-10 20:45:00"));
	//	info->queryParams.add<String>("ORMSIGNORGNAME").description = ZH_WORDS_GETTER("LegalEntitySet.field.name");
	//	info->queryParams["ORMSIGNORGNAME"].addExample("default", String(ZH_WORDS_GETTER("LegalEntitySet.sample.name")));
	//	info->queryParams.add<String>("UPDATEDATE").description = ZH_WORDS_GETTER("LegalEntitySet.field.updatedate");
	//	info->queryParams["UPDATEDATE"].addExample("default", String("2020-05-29 10:49:53"));
	//	info->queryParams.add<String>("ORGCODE").description = ZH_WORDS_GETTER("LegalEntitySet.field.orgcode");
	//	info->queryParams["ORGCODE"].addExample("default", String("104"));
	//}
	//ENDPOINT(API_M_GET, "/ExportLEM", exportLEM, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
	//	// 解析查询参数
	//	API_HANDLER_QUERY_PARAM(legalEntityMaiQuery, LegalEntityMaiQuery, queryParams);
	//	// 响应结果
	//	API_HANDLER_RESP_VO(execExportLEM(legalEntityMaiQuery));
	//}


private:
	// 演示分页查询数据
	RraineePageJsonVO::Wrapper execRraineeQuery(const RraineeQuery::Wrapper& query, const PayloadDTO& payload);
	RraineePageJsonVO::Wrapper execRraineeExport(const RraineeQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PAGEQUERYEMPLOYEELIST_CONTROLLER_