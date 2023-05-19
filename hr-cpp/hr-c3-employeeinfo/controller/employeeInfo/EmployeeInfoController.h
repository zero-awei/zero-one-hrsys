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

#include OATPP_CODEGEN_BEGIN(ApiController)

class EmployeeInfoController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(EmployeeInfoController);
public: // 定义接口
	//查询指定员工信息
	ENDPOINT_INFO(employeeQuery) {
		info->summary = ZH_WORDS_GETTER("employee.get.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("employee.field.name"), "HHH", true);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("employee.field.id"), 666, true);
		API_DEF_ADD_QUERY_PARAMS(String, "idType", ZH_WORDS_GETTER("employee.field.idType"), "idCard", true);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "idNum", ZH_WORDS_GETTER("employee.field.idNum"), 666, true);
		API_DEF_ADD_QUERY_PARAMS(String, "birthday", ZH_WORDS_GETTER("employee.field.birthday"), "6666-66-66 66:66:66", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "age", ZH_WORDS_GETTER("employee.field.age"), 66, false);
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("employee.field.sex"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "blood", ZH_WORDS_GETTER("employee.field.blood"), "O", false);
		API_DEF_ADD_QUERY_PARAMS(String, "nation", ZH_WORDS_GETTER("employee.field.nation"), "Japan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "native", ZH_WORDS_GETTER("employee.field.native"), "Japan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "marriage", ZH_WORDS_GETTER("employee.field.marriage"), "married", false);
		API_DEF_ADD_QUERY_PARAMS(String, "politic", ZH_WORDS_GETTER("employee.field.politic"), "people", false);
		API_DEF_ADD_QUERY_PARAMS(String, "rank", ZH_WORDS_GETTER("employee.field.rank"), "cleaner", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workTime", ZH_WORDS_GETTER("employee.field.workTime"), "6666-66-66 66:66:66", false);
		API_DEF_ADD_QUERY_PARAMS(String, "inTime", ZH_WORDS_GETTER("employee.field.inTime"), "6666-66-66 66:66:66", false);
		API_DEF_ADD_QUERY_PARAMS(String, "phone", ZH_WORDS_GETTER("employee.field.phone"), "6666", true);
		API_DEF_ADD_QUERY_PARAMS(String, "email", ZH_WORDS_GETTER("employee.field.email"), "666@666.com", false);
		API_DEF_ADD_QUERY_PARAMS(String, "techTitle", ZH_WORDS_GETTER("employee.field.techTitle"), "best cleaner", false);
		API_DEF_ADD_QUERY_PARAMS(String, "acaCredit", ZH_WORDS_GETTER("employee.field.acaCredit"), "primary school", false);
		API_DEF_ADD_QUERY_PARAMS(String, "firAcaCredit", ZH_WORDS_GETTER("employee.field.firAcaCredit"), "primary school", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pracCertificate", ZH_WORDS_GETTER("employee.field.pracCertificate"), "Java Boy", false);
	}
	API_HANDLER_ENDPOINT_QUERY(API_M_GET, "/employee-info/employee-query", employeeQuery, EmployeeInfoQuery, execEmployeeQuery(query));
	ENDPOINT_INFO(employeePut) {
		info->summary = ZH_WORDS_GETTER("employee.put.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("employee.field.name"), "HHH", true);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("employee.field.id"), 666, true);
		API_DEF_ADD_QUERY_PARAMS(String, "idType", ZH_WORDS_GETTER("employee.field.idType"), "idCard", true);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "idNum", ZH_WORDS_GETTER("employee.field.idNum"), 666, true);
		API_DEF_ADD_QUERY_PARAMS(String, "birthday", ZH_WORDS_GETTER("employee.field.birthday"), "6666-66-66 66:66:66", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "age", ZH_WORDS_GETTER("employee.field.age"), 66, false);
		API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("employee.field.sex"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "blood", ZH_WORDS_GETTER("employee.field.blood"), "O", false);
		API_DEF_ADD_QUERY_PARAMS(String, "residentType", ZH_WORDS_GETTER("employee.field.residentType"), "Farmer", false);
		API_DEF_ADD_QUERY_PARAMS(String, "native", ZH_WORDS_GETTER("employee.field.native"), "Japan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "residentPlace", ZH_WORDS_GETTER("employee.field.residentPlace"), "Japan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "residentresidentLocate", ZH_WORDS_GETTER("employee.field.residentLocate"), "Japan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "birthPlace", ZH_WORDS_GETTER("employee.field.birthPlace"), "Japan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "comPlace", ZH_WORDS_GETTER("employee.field.comPlace"), "Japan", false);
		API_DEF_ADD_QUERY_PARAMS(Boolean, "onlyCredit", ZH_WORDS_GETTER("employee.field.onlyCredit"), true, false);
		API_DEF_ADD_QUERY_PARAMS(String, "hobby", ZH_WORDS_GETTER("employee.field.hobby"), "go impart", false);
		API_DEF_ADD_QUERY_PARAMS(String, "health", ZH_WORDS_GETTER("employee.field.health"), "good", false);
		API_DEF_ADD_QUERY_PARAMS(String, "marriage", ZH_WORDS_GETTER("employee.field.marriage"), "married", false);
		API_DEF_ADD_QUERY_PARAMS(String, "politic", ZH_WORDS_GETTER("employee.field.politic"), "people", false);
		API_DEF_ADD_QUERY_PARAMS(String, "rank", ZH_WORDS_GETTER("employee.field.rank"), "cleaner", false);
		API_DEF_ADD_QUERY_PARAMS(String, "workTime", ZH_WORDS_GETTER("employee.field.workTime"), "6666-66-66 66:66:66", false);
		API_DEF_ADD_QUERY_PARAMS(String, "inTime", ZH_WORDS_GETTER("employee.field.inTime"), "6666-66-66 66:66:66", false);
		API_DEF_ADD_QUERY_PARAMS(String, "photo", ZH_WORDS_GETTER("employee.field.photo"), "/photo", false);
		API_DEF_ADD_QUERY_PARAMS(String, "phone", ZH_WORDS_GETTER("employee.field.phone"), "6666", true);
		API_DEF_ADD_QUERY_PARAMS(String, "email", ZH_WORDS_GETTER("employee.field.email"), "666@666.com", false);
	}
	API_HANDLER_ENDPOINT(API_M_PUT, "/employee-info/employeePut", employeePut,BODY_DTO(EmployeeInfoDTO::Wrapper,dto), execEmployeeModify(dto));
	ENDPOINT_INFO(jobListQuery) {
		info->summary = ZH_WORDS_GETTER("employee.get.summaryList");
		API_DEF_ADD_PAGE_PARAMS();
	}
	API_HANDLER_ENDPOINT_QUERY(API_M_GET, "/employee-info/job-list-query", jobListQuery, JobListQuery, execJobListQuery(query));
private: // 定义接口执行函数
	StringJsonVO::Wrapper execEmployeeQuery(const EmployeeInfoQuery::Wrapper& query);
	StringJsonVO::Wrapper execEmployeeModify(const EmployeeInfoDTO::Wrapper& dto);
	StringJsonVO::Wrapper execJobListQuery(const JobListQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EMPLOYEEINFOCONTROLLER_H_