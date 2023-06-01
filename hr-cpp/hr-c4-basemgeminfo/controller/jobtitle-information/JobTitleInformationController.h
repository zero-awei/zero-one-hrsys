#pragma once
#ifndef _JOBTITLE_INFORMATIONCONTROLLER_H_
#define _JOBTITLE_INFORMATIONCONTROLLER_H_
#include "stdafx.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/certificate-information/JobTitleInformationPageQuery.h"
#include "domain/dto/certificate-information/JobTitleInformationDTO.h"
#include "domain/vo/certificate-information/JobTitleInformationVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 职称控制器，基础接口的使用
 */
class JobTitleInformationController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(JobTitleInformationController);
	// 定义接口
public:
	//定义查询接口描述
	ENDPOINT_INFO(queryJobTitleInformation) {
		// 定义接口标题,用到中英文字典函数，用过zh-dict.yaml确定参数
		info->summary = ZH_WORDS_GETTER("jobtitleinformation.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(JobTitleInformationPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		// 添加其他查询参数
		info->queryParams.add<String>("employeeid").description = ZH_WORDS_GETTER("jobtitleinformation.field.employeeid");
		info->queryParams["employeeid"].addExample("default", String("30601C0002"));
		info->queryParams["employeeid"].required = false;
		
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/jobtitle-information/select", queryJobTitleInformation, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, JobTitleInformationPageQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryJobTitleInformation(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 演示分页查询数据
	JobTitleInformationPageJsonVO::Wrapper execQueryJobTitleInformation(const JobTitleInformationPageQuery::Wrapper& query, const PayloadDTO& payload);
};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DEBUG





