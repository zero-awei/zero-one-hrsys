#pragma once
#ifndef _QUALIFICATION_CONTROLLER_
#define _QUALIFICATION_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Qualification/QualificationQuery.h"
#include "domain/dto/Qualification/QualificationDTO.h"
#include "domain/vo/Qualification/QualificationVO.h"
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
class QualificationController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(QualificationController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryQualification) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("qualification.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(QualificationPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/qualification/query-qualification", queryQualification, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, QualificationQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryQualification(userQuery, authObject->getPayload()));
	}
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addQualification) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("qualification.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/qualification/add-qualification", addQualification, BODY_DTO(QualificationDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddQualification(dto));
	}
	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyQualification) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("qualification.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/qualification/modify-qualification", modifyQualification, BODY_DTO(QualificationDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyQualification(dto));
	}
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeQualification) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("qualification.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/qualification/remove-qualification", removeQualification, BODY_DTO(QualificationDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveQualification(dto));
	}
private:
	// 3.3 演示分页查询数据
	QualificationPageJsonVO::Wrapper execQueryQualification(const QualificationQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddQualification(const QualificationDTO::Wrapper& dto);
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyQualification(const QualificationDTO::Wrapper& dto);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveQualification(const QualificationDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
