#pragma once

// 
// 实现证书查询指定证书详情更新指定证书操作

#ifndef __UPDATECERTIFIDATE_CONTROLLER_
#define __UPDATECERTIFIDATE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/updateCertificateQuery.h"
#include "domain/dto/CertificateManage/CertificateInfoDTO.h"
#include "domain/vo/CertificateManage/CertificateInfoVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

// 实现查询指定证书详细信息和更新指定证书功能
class UpdateCertificateController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(UpdateCertificateController);
	// 3 定义接口
public:
	// 3.1 定义更新指定证书信息接口描述
	ENDPOINT_INFO(updateCertificate) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("certificate.update");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
		// 定义分页参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		//// 定义其他表单参数描述
		//info->queryParams.add<UInt64>("id").description = ZH_WORDS_GETTER("formeremployees.field.id");
		//info->queryParams["id"].addExample("default", String("1"));
		//info->queryParams["id"].required = false;
		//info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("formeremployees.field.name");
		//info->queryParams["name"].addExample("default", String("li ming"));
		//info->queryParams["name"].required = false;
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/update-Certificater", updateCertificate, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, updateCertificateQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execUpdateCertificateInfo(userQuery, authObject->getPayload()));
	}

	// 3.1 定义查询指定证书信息接口描述
	ENDPOINT_INFO(getCertificateInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("certificate.get");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CertificateInfoJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//// 定义其他表单参数描述
		//info->queryParams.add<UInt64>("outbenye").description = ZH_WORDS_GETTER("formeremployees.field.outbenye");
		//info->queryParams["outbenye"].addExample("default", String("1"));
		//info->queryParams["outbenye"].required = false;
		//info->queryParams.add<UInt64>("outall").description = ZH_WORDS_GETTER("formeremployees.field.outall");
		//info->queryParams["outall"].addExample("default", String("0"));
		//info->queryParams["outall"].required = false;
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/get-Certificater", getCertificateInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, updateCertificateQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execGetCertificateInfo(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 更新证书信息
	CertificateInfoPageJsonVO::Wrapper execUpdateCertificateInfo(const updateCertificateQuery::Wrapper& query, const PayloadDTO& payload);
	// 查询证书信息
	CertificateInfoPageJsonVO::Wrapper execGetCertificateInfo(const updateCertificateQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_