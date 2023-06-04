#pragma once
/*
（证书管理-证书信息-导出证书（导出本页在前端完成））--洛洛
*/
#ifndef _EXPORTCERTIF_CONTROLLER_
#define _EXPORTCERTIF_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/ExportCertifQuery.h"
#include "domain/dto/CertificateManage/ExportCertifDTO.h"
#include "domain/vo/CertificateManage/ExportCertifJsonVO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 文件导出
 */
class ExportCertifController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ExportCertifController);
public: // 定义接口
	// 定义查询接口描述
	ENDPOINT_INFO(ExportCertif) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("certif.export.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ExportCertifJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("sample.field.sex");
		info->queryParams["sex"].addExample("default", String("N"));
		info->queryParams["sex"].required = false;

	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/export-certif", ExportCertif, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, ExportCertifQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execExportCertif(userQuery, authObject->getPayload()));
	}
private: // 定义接口执行函数
	// 演示分页查询数据
	ExportCertifJsonVO::Wrapper execExportCertif(const ExportCertifQuery::Wrapper& query, const PayloadDTO& payload);

};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPORTCERTIF_CONTROLLER_