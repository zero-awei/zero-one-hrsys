#pragma once
/**
 *  证书管理 —— 证书信息 —— 查询、更新指定证书 —— 楚孟献
 */

#ifndef __UPDATECERTIFIDATE_CONTROLLER_
#define __UPDATECERTIFIDATE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/SpercificCertificateQuery.h"
#include "domain/dto/CertificateManage/SpercificCertificateDTO.h"
#include "domain/vo/CertificateManage/SpercificCertificateVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

// 实现查询指定证书详细信息和更新指定证书功能
class UpdateCertificateController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(UpdateCertificateController);
	// 定义接口
public:
	// 定义更新指定证书接口描述
	ENDPOINT_INFO(updateCertificate) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("spercificcertificate.get.update");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义表单参数
		/*info->queryParams.add<String>("PIMVOCATIONALID").description = ZH_WORDS_GETTER("spercificcertificate.field.PIMVOCATIONALID");
		info->queryParams["PIMVOCATIONALID"].addExample("default", String("1"));

		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("spercificcertificate.field.pimperSonName");
		info->queryParams["name"].addExample("default", String("li ming"));

		info->queryParams.add<String>("zgzsbh").description = ZH_WORDS_GETTER("spercificcertificate.field.zgzsbh");
		info->queryParams["zgzsbh"].addExample("default", String("1111"));

		info->queryParams.add<String>("zslx").description = ZH_WORDS_GETTER("spercificcertificate.field.zgzsbh");
		info->queryParams["zslx"].addExample("default", String("岗位（技能）证书"));

		info->queryParams.add<String>("pimVocationalName").description = ZH_WORDS_GETTER("spercificcertificate.field.pimVocationalName");
		info->queryParams["pimVocationalName"].addExample("default", String("安全员"));

		info->queryParams.add<String>("zghqrq").description = ZH_WORDS_GETTER("spercificcertificate.field.pimVocationalName");
		info->queryParams["zghqrq"].addExample("default", String("2002-5-15"));



		info->queryParams.add<String>("pimVocationalName").description = ZH_WORDS_GETTER("spercificcertificate.field.pimVocationalName");
		info->queryParams["pimVocationalName"].addExample("default", String("安全员"));
		info->queryParams["zgzsbh"].required = false;*/
	}
	// 定义修改接口处理
	ENDPOINT(API_M_PUT, "/bas/update-Certificater", updateCertificate, BODY_DTO(SpercificCertificateDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execUpdateSpercificCertificate(dto));
	}

	// 定义查询指定证书信息接口描述
	ENDPOINT_INFO(getSpercificCertificate) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("spercificcertificate.get.query");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SpercificCertificateJsonVO);
		info->queryParams.add<String>("PIMVOCATIONALID").description = ZH_WORDS_GETTER("spercificcertificate.field.PIMVOCATIONALID");
		info->queryParams["PIMVOCATIONALID"].addExample("default", String("1"));
	}


	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/query-Certificater", getSpercificCertificate, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(Query, SpercificCertificateQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execGetSpercificCertificate(Query));
	}
private:
	// 更新证书信息
	StringJsonVO::Wrapper execUpdateSpercificCertificate(const SpercificCertificateDTO::Wrapper& dto);
	// 查询证书信息
	SpercificCertificateJsonVO::Wrapper execGetSpercificCertificate(const SpercificCertificateQuery::Wrapper& query);
};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // __UPDATECERTIFIDATE_CONTROLLER_