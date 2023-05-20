#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/19 14:44:00

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
#ifndef _EMPLOYEEINFORMATION_H_
#define _EMPLOYEEINFORMATION_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/EmployeeInformationPageQuery/EmployeeInformationPageQuery.h"
#include "domain/vo/EmployeeInformation/EmployeeInformationVO.h"
#include "domain/dto/AddEmployeeAssignInfo/AddEmployeeAssignInfo.h"
#include "domain/dto/EmployeeInformationPageQuery/EmployeeInformationPageQueryDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
/*
员工信息控制器
*/
class EmployeeInformationController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(EmployeeInformationController);
public: // 定义接口

	//定义分页查询员工列表接口端点描述
	ENDPOINT_INFO(PageQueryInfo) {
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("sample.get.summary");
		//定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(EmployeeInformationPageJsonVO);
		//定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("sample.field.sex");
		info->queryParams["sex"].addExample("default", String("N"));
		info->queryParams["sex"].required = false;
	}
	//定义分页查询员工列表接口端点处理
	ENDPOINT(API_M_GET, "/EmployeeInformation/Employee-Info1", PageQueryInfo, QUERIES(QueryParams, queryParams)) {
		//解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, EmployeeInformationPageQuery, queryParams);
		//响应结果
		API_HANDLER_RESP_VO(execEmployeeInformation(query));
	}
	//定义导入员工信息接口端点描述
	ENDPOINT_INFO(importEmployeeInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("user.query-all.import");
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON(EmployeeInformationPageJsonVO::Wrapper);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	//定义导入员工信息接口端点处理
	ENDPOINT(API_M_GET, "/EmployeeInformation/Employee-Info2", importEmployeeInfo, API_HANDLER_AUTH_PARAME,QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(importInfo, EmployeeInformationPageQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execImportEmployeeInfo(importInfo));
	}
	//定义导出员工信息(导出本页在前端完成)接口端点描述
	ENDPOINT_INFO(exportEmployeeInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("user.query-all.export");
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON(EmployeeInformationPageJsonVO::Wrapper);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	//定义导出员工信息(导出本页在前端完成)接口端点处理
	ENDPOINT(API_M_GET, "/EmployeeInformation/Employee-Info3", exportEmployeeInfo, API_HANDLER_AUTH_PARAME,QUERIES(QueryParams,queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(exportInfo, EmployeeInformationPageQuery,queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execExportEmployeeInfo(exportInfo));
	}
	//定义新增员工信息接口端点描述
	ENDPOINT_INFO(addEmployee) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("member.field.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//定义新增员工信息接口端点处理
	ENDPOINT(API_M_POST, "/EmployeeInformation/Employee-Info4", addEmployee, BODY_DTO(EmployeeInformationDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddEmployee(dto));
	}
private:// 定义接口执行函数
	
	//分页查询员工列表
	EmployeeInformationPageJsonVO::Wrapper execEmployeeInformation(const EmployeeInformationPageQuery::Wrapper& query);
	//导入员工信息
	EmployeeInformationPageJsonVO::Wrapper execImportEmployeeInfo(const EmployeeInformationPageQuery::Wrapper& importInfo);
	//导出员工信息(导出本页在前端完成)
	EmployeeInformationPageJsonVO::Wrapper execExportEmployeeInfo(const EmployeeInformationPageQuery::Wrapper& exportInfo);
	//新增员工信息
	Uint64JsonVO::Wrapper execAddEmployee(const EmployeeInformationDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EMPLOYEEINFORMATION_H_
