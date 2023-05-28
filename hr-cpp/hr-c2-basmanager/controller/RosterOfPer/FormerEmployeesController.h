#pragma once

/**
 *  基础管理 —— 人员花名册 —— 离职员工 —— 楚孟献
 */

/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef __FORMER_EMPLOYEES_CONTROLLER_
#define __FORMER_EMPLOYEES_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/RosterOfPer/FormerEmployeesQuery.h"
#include "domain/dto/RosterOfPer/FormerEmployeesDTO.h"
#include "domain/vo/RosterOfPer/FormerEmployeesVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include <boost/throw_exception.hpp>

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class FormerEmployeesController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(FormerEmployeesController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述 询问所有离职员工数据
	ENDPOINT_INFO(queryFormerEmployees) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("formeremployees.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FormerEmployeesPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<UInt64>("id").description = ZH_WORDS_GETTER("formeremployees.field.id");
		info->queryParams["id"].addExample("default", String("1"));
		info->queryParams["id"].required = false;
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("formeremployees.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/query-all-FormerEmployees", queryFormerEmployees, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, FormerEmployeesQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryFormerEmployees(userQuery, authObject->getPayload()));
	}

	// 3.1 定义导出接口描述
	ENDPOINT_INFO(exportFormerEmployees) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("formeremployees.get.out");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		//// 定义其他表单参数描述
		//info->queryParams.add<UInt64>("outbenye").description = ZH_WORDS_GETTER("formeremployees.field.outbenye");
		//info->queryParams["outbenye"].addExample("default", String("1"));
		//info->queryParams["outbenye"].required = false;
		//info->queryParams.add<UInt64>("outall").description = ZH_WORDS_GETTER("formeremployees.field.outall");
		//info->queryParams["outall"].addExample("default", String("0"));
		//info->queryParams["outall"].required = false;
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/get-FormerEmployees", exportFormerEmployees, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(Query, FormerEmployeesQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execExportFormerEmployees(Query, authObject->getPayload()));
	}
private:
	// 3.3 演示分页查询数据
	FormerEmployeesPageJsonVO::Wrapper execQueryFormerEmployees(const FormerEmployeesQuery::Wrapper& query, const PayloadDTO& payload);
	// 返回离职员工Excel表格
	StringJsonVO::Wrapper execExportFormerEmployees(const FormerEmployeesQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_