#pragma once
#ifndef _EXPORTEMPLOYEE_CONTROLLER_
#define _EXPORTEMPLOYEE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/RosterOfPer/ExportEmployeeDO.h"
#include "domain/dto/RosterOfPer/ExportEmployeeDTO.h"
#include "domain/vo/RosterOfPer/ExportEmployeeVO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"
#include "ExcelComponent.h"

using namespace oatpp;


#include OATPP_CODEGEN_BEGIN(ApiController)  
namespace multipart = oatpp::web::mime::multipart;


class ExportEmployeeController : public oatpp::web::server::api::ApiController {
	
	API_ACCESS_DECLARE(ExportEmployeeController); // 2 定义控制器访问入口
public:
	ENDPOINT_INFO(addExportEmployee) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/ExportEmployee", addExportEmployee, BODY_DTO(ExportEmployeeDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddExportEmployee(dto));
	}


	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyExportEmployee) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/ExportEmployee", modifyExportEmployee, BODY_DTO(ExportEmployeeDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyExportEmployee(dto));
	}


	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeExportEmployee) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/ExportEmployee", removeExportEmployee, BODY_DTO(ExportEmployeeDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveExportEmployee(dto));
	}


	//// 文件导入
	//ENDPOINT_INFO(importLEM) {
	//	// 定义接口标题
	//	info->summary = ZH_WORDS_GETTER("LegalEntitySet.import.summary");
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
	//}
	//ENDPOINT(API_M_POST, "/ImportLEM", importLEM, BODY_DTO(ExportEmployeeDTO::Wrapper, dto)) {
	//	// 响应结果
	//	API_HANDLER_RESP_VO(execImportLEM(dto));
	//}


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
	//// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddExportEmployee(const ExportEmployeeDTO::Wrapper& dto);
	//// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyExportEmployee(const ExportEmployeeDTO::Wrapper& dto);
	// //3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveExportEmployee(const ExportEmployeeDTO::Wrapper& dto);
	// 导入数据 
	//BooleanJsonVO::Wrapper execImportLEM(const ExportEmployeeDTO::Wrapper& dto);
	//// 导出数据
	//BooleanJsonVO::Wrapper execExportLEM(const ExportEmployeeDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _EXPORTEMPLOYEE_CONTROLLER_