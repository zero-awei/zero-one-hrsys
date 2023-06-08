#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: shiyu(xunzhao)
 @Date: 2022/10/25 10:58:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#include "./domain/do/JobTitle/JobTitleDo.h"  
#include "./domain/vo/JobTitle/JobTitleJsonVO.h"
#include "./domain/query/JobTitle/JobTitleQuery.h"
#include "./domain//vo/BaseJsonVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"
#include "./Macros.h"
#include "oatpp-swagger/Types.hpp"

using namespace std;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class JobTitleController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(JobTitleController);
public:
	// 职称查询(分页查询)接口描述
	ENDPOINT_INFO(queryJobTitle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("title.query.summary");
		// 定义响应参数格式 -- 分页查询JsonVO
		API_DEF_ADD_RSP_JSON_WRAPPER(JTQueryPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 过滤字段
		// 参数，过滤字段
		info->queryParams.add<String>("employee_id").description = ZH_WORDS_GETTER("title.field.employee_i");
		info->queryParams["employee_id"].addExample("default", NULL);
		info->queryParams["employee_id"].required = false;
		info->queryParams.add<String>("employee_name").description = ZH_WORDS_GETTER("title.field.employee_name");
		info->queryParams["employee_name"].addExample("default", NULL);
		info->queryParams["employee_name"].required = false;
		info->queryParams.add<String>("org_name").description = ZH_WORDS_GETTER("title.field.org_name");
		info->queryParams["org_name"].addExample("default", NULL);
		info->queryParams["org_name"].required = false;
		info->queryParams.add<String>("jobtitle_name").description = ZH_WORDS_GETTER("title.field.jobtitle_name");
		info->queryParams["jobtitle_name"].addExample("default", NULL);
		info->queryParams["jobtitle_name"].required = false;
		info->queryParams.add<String>("jobtitle_grades").description = ZH_WORDS_GETTER("title.field.jobtitle_grades");
		info->queryParams["jobtitle_grades"].addExample("default", NULL);
		info->queryParams["jobtitle_grades"].required = false;
		info->queryParams.add<String>("b_highest_professional_title").description = ZH_WORDS_GETTER("title.field.b_highest_professional_title");
		info->queryParams["b_highest_professional_title"].addExample("default", NULL);
		info->queryParams["b_highest_professional_title"].required = false;

	}
	// 职称查询(分页查询)接口
	ENDPOINT(API_M_GET, "/job-title-management/query-jobtitle", queryJobTitle, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数 , 将解析的查询参数给queryPage
		API_HANDLER_QUERY_PARAM(queryPage, JobTitleQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryPage(queryPage));
	}

	// 职称查询(分页查询-用于搜索框执行模糊查询)
	ENDPOINT_INFO(queryJobTitleSB) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("title.query.search-box");
		// 定义响应参数格式 -- 分页查询JsonVO
		API_DEF_ADD_RSP_JSON_WRAPPER(JTQueryPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 包含一个参数，用于模糊查询
		info->queryParams.add<String>("param").description = ZH_WORDS_GETTER("title.query.param");
		info->queryParams["param"].addExample("default", NULL);
		info->queryParams["param"].required = false;
		// 参数，过滤字段
		info->queryParams.add<String>("employee_id").description = ZH_WORDS_GETTER("title.field.employee_i");
		info->queryParams["employee_id"].addExample("default", NULL);
		info->queryParams["employee_id"].required = false;
		info->queryParams.add<String>("employee_name").description = ZH_WORDS_GETTER("title.field.employee_name");
		info->queryParams["employee_name"].addExample("default", NULL);
		info->queryParams["employee_name"].required = false;
		info->queryParams.add<String>("org_name").description = ZH_WORDS_GETTER("title.field.org_name");
		info->queryParams["org_name"].addExample("default", NULL);
		info->queryParams["org_name"].required = false;
		info->queryParams.add<String>("jobtitle_name").description = ZH_WORDS_GETTER("title.field.jobtitle_name");
		info->queryParams["jobtitle_name"].addExample("default", NULL);
		info->queryParams["jobtitle_name"].required = false;
		info->queryParams.add<String>("jobtitle_grades").description = ZH_WORDS_GETTER("title.field.jobtitle_grades");
		info->queryParams["jobtitle_grades"].addExample("default", NULL);
		info->queryParams["jobtitle_grades"].required = false;
		info->queryParams.add<String>("b_highest_professional_title").description = ZH_WORDS_GETTER("title.field.b_highest_professional_title");
		info->queryParams["b_highest_professional_title"].addExample("default", NULL);
		info->queryParams["b_highest_professional_title"].required = false;

	}
	// 职称查询(分页查询)接口
	ENDPOINT(API_M_GET, "/job-title-management/query-jobtitle-searchbox", queryJobTitleSB, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数 , 将解析的查询参数给queryPage
		API_HANDLER_QUERY_PARAM(queryPage, JobTitleQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryPageSB(queryPage));
	}

	// 删除职称
	ENDPOINT_INFO(removeJobTitle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("title.delete.summary");
		// 定义响应参数格式 -- 返回删除成功与否
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 删除职称接口
	ENDPOINT(API_M_DEL, "/job-title-management/remove-jobtitle", removeJobTitle, BODY_DTO(JobTitleDeleteDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveJobTitle(dto));
	}

	// 新增职称接口描述
	ENDPOINT_INFO(addJobTitle) {
		info->summary = ZH_WORDS_GETTER("title.add.summary");
		// 定于响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 新增职称接口
	ENDPOINT(API_M_POST, "/job-title-management/add-jobtitle", addJobTitle, BODY_DTO(JobTitleAddDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddJobTitle(dto));
	}

	// 附件上传接口
	// 定义文件上传端点描述
	ENDPOINT_INFO(postFileJobTitle) {
		info->summary = ZH_WORDS_GETTER("title.file.postfile");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("title.file.suffix");
		info->queryParams["suffix"].addExample("png", String(".png"));
		info->queryParams["suffix"].addExample("jpg", String(".jpg"));
		info->queryParams["suffix"].addExample("txt", String(".txt"));
		info->queryParams["suffix"].addExample("pdf", String(".pdf"));
	}
	// 定义文件上传端点处理
	ENDPOINT(API_M_POST, "/job-title-management/postfile-jobtitle", postFileJobTitle, BODY_STRING(String, body), QUERY(String, suffix)) {
		// 执行文件保存逻辑
		API_HANDLER_RESP_VO(execJobTitlePostFile(body, suffix));
	}
private:
	JTQueryPageJsonVO::Wrapper execQueryPage(const JobTitleQuery::Wrapper& query);
	JTQueryPageJsonVO::Wrapper execQueryPageSB(const JobTitleQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execRemoveJobTitle(const JobTitleDeleteDTO::Wrapper& dto);
	StringJsonVO::Wrapper execAddJobTitle(const JobTitleAddDTO::Wrapper& dto);
	StringJsonVO::Wrapper execJobTitlePostFile(const String& fileBody, const String& suffix);
};


#include OATPP_CODEGEN_END(ApiController)  // <- end
