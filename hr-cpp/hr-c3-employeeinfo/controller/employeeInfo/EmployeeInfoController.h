#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/18 21:20:54

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
#ifndef _EMPLOYEEINFOCONTROLLER_H_
#define _EMPLOYEEINFOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "../../domain/query/employeeInfo/EmployeeInfoQuery.h"
#include "../../domain/dto/employeeInfo/EmployeeInfoDTO.h"
#include "../../domain/query/jobList/JobListQuery.h"
#include "../../domain/dto/employeeInfo/EmployeeInfoAddDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class EmployeeInfoController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(EmployeeInfoController);
public:
	/* *
	* 查询指定员工信息接口
	* 执行人：Detachment
	*/
	ENDPOINT_INFO(employeeQuery) {
		info->summary = ZH_WORDS_GETTER("employee.get.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("employee.field.id"), "666", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("employee.field.name"), u8"徐梓炎", false);
		API_DEF_ADD_QUERY_PARAMS(String, "idType", ZH_WORDS_GETTER("employee.field.idType"), "10", false);
		API_DEF_ADD_QUERY_PARAMS(String, "idNum", ZH_WORDS_GETTER("employee.field.idNum"), "666", false);
		API_DEF_ADD_QUERY_PARAMS(String, "birthday", ZH_WORDS_GETTER("employee.field.birthday"), "6666-66-66 66:66:66", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "age", ZH_WORDS_GETTER("employee.field.age"), 66, false);
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("employee.field.sex"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "nation", ZH_WORDS_GETTER("employee.field.nation"), "01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "native", ZH_WORDS_GETTER("employee.field.native"), u8"日本北海道", false);
		API_DEF_ADD_QUERY_PARAMS(String, "marriage", ZH_WORDS_GETTER("employee.field.marriage"), "10", false);
		API_DEF_ADD_QUERY_PARAMS(String, "politic", ZH_WORDS_GETTER("employee.field.politic"), "10", false);
		API_DEF_ADD_QUERY_PARAMS(String, "rank", ZH_WORDS_GETTER("employee.field.rank"), u8"清洁工", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workTime", ZH_WORDS_GETTER("employee.field.workTime"), "6666-66-66 66:66:66", false);
		API_DEF_ADD_QUERY_PARAMS(String, "inTime", ZH_WORDS_GETTER("employee.field.inTime"), "6666-66-66 66:66:66", false);
		API_DEF_ADD_QUERY_PARAMS(String, "email", ZH_WORDS_GETTER("employee.field.email"), "666@666.com", false);
		API_DEF_ADD_QUERY_PARAMS(String, "techTitle", ZH_WORDS_GETTER("employee.field.techTitle"), u8"最佳清洁工", false);
		API_DEF_ADD_QUERY_PARAMS(String, "acaCredit", ZH_WORDS_GETTER("employee.field.acaCredit"), u8"北海道小学", false);
		API_DEF_ADD_QUERY_PARAMS(String, "firAcaCredit", ZH_WORDS_GETTER("employee.field.firAcaCredit"), u8"北海道小学", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pracCertificate", ZH_WORDS_GETTER("employee.field.pracCertificate"), u8"专业清洁工", false);
		API_DEF_ADD_QUERY_PARAMS(String, "photo", ZH_WORDS_GETTER("employee.field.photo"), u8"[{\"name\":\"组织管理.png\",\"id\":\"4d3c48ea78cc1d4a04bdb2142f136d28\"}]", false);
		API_DEF_ADD_QUERY_PARAMS(String, "phone", ZH_WORDS_GETTER("employee.field.phone"), "6666", false);
	}
	API_HANDLER_ENDPOINT_QUERY(API_M_GET, "/employee-info/employee-query", employeeQuery, EmployeeInfoQuery, execEmployeeQuery(query));
	/* *
	* 查询指定员工信息
	* 执行人：Detachment
	*/
	ENDPOINT_INFO(employeePut) {
		info->summary = ZH_WORDS_GETTER("employee.put.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("employee.field.name"), "HHH", true);
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("employee.field.id"), "666", true);
		API_DEF_ADD_QUERY_PARAMS(String, "idType", ZH_WORDS_GETTER("employee.field.idType"), "10", true);
		API_DEF_ADD_QUERY_PARAMS(String, "idNum", ZH_WORDS_GETTER("employee.field.idNum"), "666", true);
		API_DEF_ADD_QUERY_PARAMS(String, "phone", ZH_WORDS_GETTER("employee.field.phone"), "10086", false);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("employee.field.state"), "on", false);
	};
	API_HANDLER_ENDPOINT(API_M_PUT, "/employee-info/employeePut", employeePut, BODY_DTO(EmployeeInfoAddDTO::Wrapper, dto), execEmployeePut(dto));
	/* *
	* 修改指定员工员工信息接口
	* 执行人：Detachment
	*/
	ENDPOINT_INFO(employeePost) {
		info->summary = ZH_WORDS_GETTER("employee.post.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("employee.field.name"), u8"徐梓炎", true);
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("employee.field.id"), "666", true);
		API_DEF_ADD_QUERY_PARAMS(String, "idType", ZH_WORDS_GETTER("employee.field.idType"), "10", true);
		API_DEF_ADD_QUERY_PARAMS(String, "idNum", ZH_WORDS_GETTER("employee.field.idNum"), "666", true);
		API_DEF_ADD_QUERY_PARAMS(String, "birthday", ZH_WORDS_GETTER("employee.field.birthday"), "6666-66-66 66:66:66", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "age", ZH_WORDS_GETTER("employee.field.age"), 66, false);
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("employee.field.sex"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "blood", ZH_WORDS_GETTER("employee.field.blood"), "O", false);
		API_DEF_ADD_QUERY_PARAMS(String, "residentType", ZH_WORDS_GETTER("employee.field.residentType"), "Farmer", false);
		API_DEF_ADD_QUERY_PARAMS(String, "native", ZH_WORDS_GETTER("employee.field.native"), u8"日本北海道", false);
		API_DEF_ADD_QUERY_PARAMS(String, "residentPlace", ZH_WORDS_GETTER("employee.field.residentPlace"), "Japan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "residentresidentLocate", ZH_WORDS_GETTER("employee.field.residentLocate"), "Japan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "birthPlace", ZH_WORDS_GETTER("employee.field.birthPlace"), "Japan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "comPlace", ZH_WORDS_GETTER("employee.field.comPlace"), u8"日本", false);
		API_DEF_ADD_QUERY_PARAMS(String, "onlyCredit", ZH_WORDS_GETTER("employee.field.onlyCredit"), u8"是", false);
		API_DEF_ADD_QUERY_PARAMS(String, "hobby", ZH_WORDS_GETTER("employee.field.hobby"), u8"开impart", false);
		API_DEF_ADD_QUERY_PARAMS(String, "health", ZH_WORDS_GETTER("employee.field.health"), u8"情况堪忧", false);
		API_DEF_ADD_QUERY_PARAMS(String, "marriage", ZH_WORDS_GETTER("employee.field.marriage"), "10", false);
		API_DEF_ADD_QUERY_PARAMS(String, "politic", ZH_WORDS_GETTER("employee.field.politic"), "10", false);
		API_DEF_ADD_QUERY_PARAMS(String, "rank", ZH_WORDS_GETTER("employee.field.rank"), u8"清洁工", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workTime", ZH_WORDS_GETTER("employee.field.workTime"), "6666-66-66 66:66:66", false);
		API_DEF_ADD_QUERY_PARAMS(String, "inTime", ZH_WORDS_GETTER("employee.field.inTime"), "6666-66-66 66:66:66", false);
		API_DEF_ADD_QUERY_PARAMS(String, "photo", ZH_WORDS_GETTER("employee.field.photo"), u8"[{\"name\":\"组织管理.png\",\"id\":\"4d3c48ea78cc1d4a04bdb2142f136d28\"}]", false);
		API_DEF_ADD_QUERY_PARAMS(String, "phone", ZH_WORDS_GETTER("employee.field.phone"), "6666", true);
		API_DEF_ADD_QUERY_PARAMS(String, "email", ZH_WORDS_GETTER("employee.field.email"), "666@666.com", false);
	}
	API_HANDLER_ENDPOINT(API_M_POST, "/employee-info/employeePost", employeePost,BODY_DTO(EmployeeInfoDTO::Wrapper,dto), execEmployeeModify(dto));
	/* *
	* 岗位列表接口
	* 执行人：Detachment
	*/
	ENDPOINT_INFO(jobListQuery) {
		info->summary = ZH_WORDS_GETTER("employee.get.summaryList");
		API_DEF_ADD_QUERY_PARAMS(String, "jobName", ZH_WORDS_GETTER("employee.field.jobList"), u8"炒面岗", true);
		API_DEF_ADD_PAGE_PARAMS();
	}
	API_HANDLER_ENDPOINT_QUERY(API_M_GET, "/employee-info/job-list-query", jobListQuery, JobListQuery, execJobListQuery(query));
private: // 定义接口执行函数
	/* *
	* 查询指定员工员工信息执行接口
	* 执行人：Detachment
	*/
	StringJsonVO::Wrapper execEmployeeQuery(const EmployeeInfoQuery::Wrapper& query);
	/* *
	* 修改指定员工员工信息执行接口
	* 执行人：Detachment
	*/
	StringJsonVO::Wrapper execEmployeeModify(const EmployeeInfoDTO::Wrapper& dto);
	/* *
	* 增加员工信息执行接口
	* 执行人：Detachment
	*/
	StringJsonVO::Wrapper execEmployeePut(const EmployeeInfoAddDTO::Wrapper& dto);
	/* *
	* 岗位列表查询执行接口
	* 执行人：Detachment
	*/
	StringJsonVO::Wrapper execJobListQuery(const JobListQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EMPLOYEEINFOCONTROLLER_H_