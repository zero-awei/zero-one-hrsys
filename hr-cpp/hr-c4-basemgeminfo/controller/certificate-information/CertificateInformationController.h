#pragma once
#ifndef _CERTIFICATE_INFORMATIONCONTROLLER_H_
#define _CERTIFICATE_INFORMATIONCONTROLLER_H_
#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/certificate-information/CertificateInformationPageQuery.h"
#include "domain/dto/certificate-information/CertificateInformationDTO.h"
#include "domain/vo/certificate-information/CertificateInformationVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 证书控制器，基础接口的使用
 */
class CertificateInformationController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(CertificateInformationController);
	// 定义接口
public:
		//定义查询接口描述
	ENDPOINT_INFO(queryCertificateInformation) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("certificateinformation.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CertificateInformationPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 添加其他查询参数 
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("certificateinformation.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("DA185CBA-5D0C-4234-A9F7-37148C3BEA10"));
		info->queryParams["pimpersonid"].required = false;
		
		
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/certificate-information/select", queryCertificateInformation, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, CertificateInformationPageQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryCertificateInformation(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 演示分页查询数据
	CertificateInformationPageJsonVO::Wrapper execQueryCertificateInformation(const CertificateInformationPageQuery::Wrapper& query, const PayloadDTO& payload);
};
	// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DEBUG
