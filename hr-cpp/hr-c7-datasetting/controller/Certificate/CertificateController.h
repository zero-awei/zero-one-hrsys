#pragma once
#ifndef _CERTIFICATECONTROLLLER_
#define _CERTIFICATECONTROLLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Certificate/CertificateQuery.h"
#include "domain/dto/Certificate/CertificateDTO.h"
#include "domain/vo/Certificate/CertificateVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class CertificateController : public oatpp::web::server::api::ApiController // 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CertificateController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryCertificate) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("certificate.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CertificatePageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	ENDPOINT(API_M_GET, "/certificate/query-certificate", queryCertificate, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(CertificateQuery, CertificateQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryCertificate(CertificateQuery, authObject->getPayload()));
	}
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addCertificate) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("certificate.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/certificate/add-certificate", addCertificate, BODY_DTO(CertificateDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddCertificate(dto));
	}
	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyCertificate) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("certificate.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/certificate/modify-certificate", modifyCertificate, BODY_DTO(CertificateDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyCertificate(dto));
	}
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeCertificate) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("certificate.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/certificate/remove-certificate", removeCertificate, BODY_DTO(CertificateDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveCertificate(dto));
	}
private:
	// 3.3 演示分页查询数据
	CertificatePageJsonVO::Wrapper execQueryCertificate(const CertificateQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddCertificate(const CertificateDTO::Wrapper& dto);
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyCertificate(const CertificateDTO::Wrapper& dto);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveCertificate(const CertificateDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 