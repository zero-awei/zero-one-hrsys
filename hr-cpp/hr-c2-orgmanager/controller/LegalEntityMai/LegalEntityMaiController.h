#pragma once
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
#include "ExcelComponent.h"
#include "oatpp-swagger/Types.hpp"
#include "domain/dto/LegalEntityMai/LegalEntityMaiDelDTO.h"
#include "domain/dto/LegalEntityMai/LegalEntityMaiAddDTO.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)
namespace multipart = oatpp::web::mime::multipart;

/* 法人主体维护控制器设计--（组织管理-数据设置-法人主体维护）--TripleGold */
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
		/*info->queryParams.add<String>("ORMSIGNORGID").description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
		info->queryParams["ORMSIGNORGID"].addExample("default", String("11F28C41-1D50-4503-B925-D86D1F70A1D2"));
		info->queryParams.add<String>("UPDATEMAN").description = ZH_WORDS_GETTER("LegalEntityMai.field.updateman");
		info->queryParams["UPDATEMAN"].addExample("default", String("guest"));
		info->queryParams.add<String>("CREATEMAN").description = ZH_WORDS_GETTER("LegalEntityMai.field.createman");
		info->queryParams["CREATEMAN"].addExample("default", String("1944DE89-8E28-4D10-812C-CAEEAAE8A927"));
		info->queryParams.add<String>("CREATEDATE").description = ZH_WORDS_GETTER("LegalEntityMai.field.createdate");
		info->queryParams["CREATEDATE"].addExample("default", String("2019-09-10 20:45:00"));*/
		info->queryParams.add<String>("ORMSIGNORGNAME").description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
		info->queryParams["ORMSIGNORGNAME"].addExample("default", String(ZH_WORDS_GETTER("LegalEntityMai.sample.name")));
		info->queryParams["ORMSIGNORGNAME"].required = false;
		/*info->queryParams.add<String>("UPDATEDATE").description = ZH_WORDS_GETTER("LegalEntityMai.field.updatedate");
		info->queryParams["UPDATEDATE"].addExample("default", String("2020-05-29 10:49:53"));
		info->queryParams.add<String>("ORGCODE").description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
		info->queryParams["ORGCODE"].addExample("default", String("104"));*/
	}
	// 定义查询法人主体信息接口处理
	ENDPOINT(API_M_GET, "/org/query-LEM", queryLEM, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(legalEntityMaiQuery, LegalEntityMaiQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryLEM(legalEntityMaiQuery));
	}

	/* 定义更新法人主体名称，组织编号 */
	ENDPOINT_INFO(updateLEM) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 定义更新接口处理
	ENDPOINT(API_M_PUT, "/org/update-LEM", updateLEM, BODY_DTO(LegalEntityMaiDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execUpdateLEM(dto));
	}

	// 定义新增法人主体接口描述
	ENDPOINT_INFO(addLEM) {
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/org/add-LEM", addLEM, API_HANDLER_AUTH_PARAME, BODY_DTO(List<LegalEntityMaiAddDTO::Wrapper>, dtoList)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddLEM(dtoList, authObject->getPayload()));
	}

	// 定义删除法人主体接口描述
	ENDPOINT_INFO(removeLEM) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_DEL, "/org/remove-LEM", removeLEM, BODY_DTO(LegalEntityMaiDelDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveLEM(dto));
	}

	// 文件操作
	// 文件导入
	ENDPOINT_INFO(importLEM) {
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.import.summary");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("LegalEntityMai.import.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
	}
	ENDPOINT(API_M_POST, "/org/import-LEM", importLEM, API_HANDLER_AUTH_PARAME, 
		BODY_STRING(String, body), QUERY(String, suffix)) {
		// 执行文件保存逻辑
		API_HANDLER_RESP_VO(execImportLEM(body, suffix, authObject->getPayload()));
	}

	// 文件导出
	ENDPOINT_INFO(exportLEM) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.export.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		info->queryParams.add<String>("ORMSIGNORGNAME").description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
		info->queryParams["ORMSIGNORGNAME"].addExample("default", String(ZH_WORDS_GETTER("LegalEntityMai.sample.name")));
		info->queryParams["ORMSIGNORGNAME"].required = false;
		info->queryParams.add<String>("ORGCODE").description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
		info->queryParams["ORGCODE"].addExample("default", String("104"));
		info->queryParams["ORGCODE"].required = false;
	}
	ENDPOINT(API_M_GET, "/org/export-LEM", exportLEM, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(query, LegalEntityMaiQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execExportLEM(query));
	}
	
private: // 定义接口执行函数
	// 分页查询数据
	LegalEntityMaiPageJsonVO::Wrapper execQueryLEM(const LegalEntityMaiQuery::Wrapper& query);
	// 更新数据
	StringJsonVO::Wrapper execUpdateLEM(const LegalEntityMaiDTO::Wrapper& dto);
	// 批量新增数据
	Uint64JsonVO::Wrapper execAddLEM(const List<LegalEntityMaiAddDTO::Wrapper>& dtoList, const PayloadDTO& payload);
	// 删除数据
	Uint64JsonVO::Wrapper execRemoveLEM(const LegalEntityMaiDelDTO::Wrapper& dto);
	// 导入数据
	StringJsonVO::Wrapper execImportLEM(const String& body, const String& suffix, const PayloadDTO& payload);
	// 导出数据
	StringJsonVO::Wrapper execExportLEM(const LegalEntityMaiQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_LEGALENTITYMAICONTROLLER_H_