#pragma once

#ifndef JOBTITLEYCONTROLLER_H
#define JOBTITLEYCONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/JobTitleInfo/JobTitleInfoDTO.h"
#include "domain/vo/JobTitleInfo/JobTitleInfoVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * JobTitleY控制器：云隐负责
 */
class JobTitleInfoController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(JobTitleInfoController);
	// 3 定义接口
public:
	// 查询职称
	ENDPOINT_INFO(queryJobTitle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("jobtitle.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(JobTitleInfoJsonVO);
		// 定义其他表单参数描述
		info->queryParams.add<String>("employee_id").description = ZH_WORDS_GETTER("jobtitle.field.employee_id");
		info->queryParams["employee_id"].addExample("default", String("11"));
		info->queryParams["employee_id"].required = true;
		info->queryParams.add<String>("employee_name").description = ZH_WORDS_GETTER("jobtitle.field.employee_name");
		info->queryParams["employee_name"].addExample("default", String("li hua"));
		info->queryParams["employee_name"].required = true;
		info->queryParams.add<String>("jobtitle_name").description = ZH_WORDS_GETTER("jobtitle.field.jobtitle_name");
		info->queryParams["jobtitle_name"].addExample("default", String("statistician"));
		info->queryParams["jobtitle_name"].required = true;
		info->queryParams.add<String>("get_time").description = ZH_WORDS_GETTER("jobtitle.field.get_time");
		info->queryParams["get_time"].addExample("default", String("2023-05-15"));
		info->queryParams["get_time"].required = true;
		info->queryParams.add<String>("org_name").description = ZH_WORDS_GETTER("jobtitle.field.org_name");
		info->queryParams["org_name"].addExample("default", String("hua wei"));
		info->queryParams["org_name"].required = true;
		info->queryParams.add<String>("professor_grades").description = ZH_WORDS_GETTER("jobtitle.field.professor_grades");
		info->queryParams["professor_grades"].addExample("default", String("gaoji"));
		info->queryParams["professor_grades"].required = true;
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/job-title-management/query-job-title", queryJobTitle, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, JobTitleInfoDTO, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryJobTitle(userQuery, authObject->getPayload()));
	}

	// 导出职称
	ENDPOINT_INFO(getJobTitle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("jobtitle.export.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义其他表单参数描述
		info->queryParams.add<String>("employee_id").description = ZH_WORDS_GETTER("jobtitle.field.employee_id");
		info->queryParams["employee_id"].addExample("default", String("11"));
		info->queryParams["employee_id"].required = true;
		info->queryParams.add<String>("employee_name").description = ZH_WORDS_GETTER("jobtitle.field.employee_name");
		info->queryParams["employee_name"].addExample("default", String("li hua"));
		info->queryParams["employee_name"].required = true;
		info->queryParams.add<String>("jobtitle_name").description = ZH_WORDS_GETTER("jobtitle.field.jobtitle_name");
		info->queryParams["jobtitle_name"].addExample("default", String("statistician"));
		info->queryParams["jobtitle_name"].required = true;
		info->queryParams.add<String>("get_time").description = ZH_WORDS_GETTER("jobtitle.field.get_time");
		info->queryParams["get_time"].addExample("default", String("2023-05-15"));
		info->queryParams["get_time"].required = true;
		info->queryParams.add<String>("org_name").description = ZH_WORDS_GETTER("jobtitle.field.org_name");
		info->queryParams["org_name"].addExample("default", String("hua wei"));
		info->queryParams["org_name"].required = true;
		info->queryParams.add<String>("professor_grades").description = ZH_WORDS_GETTER("jobtitle.field.professor_grades");
		info->queryParams["professor_grades"].addExample("default", String("gaoji"));
		info->queryParams["professor_grades"].required = true;
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/job-title-management/export-job-title", getJobTitle, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, JobTitleInfoDTO, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execGetJobTitle(userQuery, authObject->getPayload()));
	}
	
	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyJobTitle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("jobtitle.update.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/job-title-management/modify-job-title", modifyJobTitle, BODY_DTO(JobTitleInfoDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyJobTitle(dto));
	}
private:
	// 3.3 演示查询数据
	JobTitleInfoJsonVO::Wrapper execQueryJobTitle(const JobTitleInfoDTO::Wrapper& query, const PayloadDTO& payload);
	StringJsonVO::Wrapper execGetJobTitle(const JobTitleInfoDTO::Wrapper& query, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execModifyJobTitle(const JobTitleInfoDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_