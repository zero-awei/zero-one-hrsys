/*
 Copyright Zero One Star. All rights reserved.

 @Author: luoluo
 @Date: 2023/05/18 16:12:54

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
#ifndef _EMPLOYEEPAGECONTROLLER_H_
#define _EMPLOYEEPAGECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/RosterOfPer/EmployeePageDTO.h"
#include "domain/query/RosterOfPer/EmployeePageQuery.h"
#include "domain/vo/RosterOfPer/EmployeePageVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include OATPP_CODEGEN_BEGIN(ApiController)

class EmployeePageController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(EmployeePageController);
public: // 定义接口
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryEmployeePage) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(EmployeePageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("EMPLOYEEID").description = ZH_WORDS_GETTER("employee.field.employeeid");
		info->queryParams["EMPLOYEEID"].addExample("default", String("N"));
		info->queryParams["EMPLOYEEID"].required = false;
		info->queryParams.add<String>("EMPLOYEENAME").description = ZH_WORDS_GETTER("employee.field.employeename");
		info->queryParams["EMPLOYEENAME"].addExample("default", String("li ming"));
		info->queryParams["EMPLOYEENAME"].required = false;
		
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/query-employeePage", queryEmployeePage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, EmployeePageQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryEmployeePage(userQuery, authObject->getPayload()));
	}
private: // 定义接口执行函数
	// 3.3 演示分页查询数据
	EmployeePageJsonVO::Wrapper execQueryEmployeePage(const EmployeePageQuery::Wrapper& query, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EMPLOYEEPAGECONTROLLER_H_
