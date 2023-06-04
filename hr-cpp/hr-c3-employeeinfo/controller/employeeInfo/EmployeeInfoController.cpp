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

#include "stdafx.h"
#include "EmployeeInfoController.h"
#include "domain/vo/jobList/JobListVO.h"

EmployeeInfoVO::Wrapper EmployeeInfoController::execEmployeeQuery(const EmployeeInfoQuery::Wrapper& query)
{
	EmployeeInfoService service;
	auto result = service.listEmployee(query);
	auto jvo = EmployeeInfoVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper EmployeeInfoController::execEmployeeModify(const EmployeeInfoDTO::Wrapper& dto, const PayloadDTO& payLoad) {
	//auto vo = StringJsonVO::createShared();
	auto jvo = StringJsonVO::createShared();
	if (!dto->empid || !dto->name || !dto->idtype || !dto->idnum)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->age < 0 )
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->idtype.getValue({}) != "10" && dto->idtype.getValue({}) != "20" && dto->idtype.getValue({}) != "30")
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//vo->success("Employee information modify success");
	EmployeeInfoService service;
	if (service.updateEmployee(dto,payLoad)) {
		jvo->success(dto->pimpersonid);
	}
	else {
		jvo->fail(dto->pimpersonid);
	}
	return jvo;
}
StringJsonVO::Wrapper EmployeeInfoController::execEmployeePut(const EmployeeInfoAddDTO::Wrapper& dto,const PayloadDTO& payLoad) {
	//auto vo = StringJsonVO::createShared();
	auto jvo = StringJsonVO::createShared();
	if (!dto->empid || !dto->name || !dto->idType || !dto->idNum)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->idType.getValue({}) != "10" && dto->idType.getValue({}) != "20" && dto->idType.getValue({}) != "30")//另一张状态表里
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->phoneNum.get()->length() != 11 && dto->state.getValue({}) != "10" && dto->state.getValue({}) != "20" && dto->state.getValue({}) != "30")//同理
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	EmployeeInfoService service;
	if (service.insertEmployee(dto,payLoad)) {
		jvo->success(dto->empid);
	}
	else {
		jvo->fail(dto->empid);
	}
	//vo->success("Job list information query success");
	return jvo;
}
JobListPageJsonVO::Wrapper EmployeeInfoController::execJobListQuery(const JobListQuery::Wrapper& query) {
	JobListService service;
	auto jvo = JobListPageJsonVO::createShared();
	auto res = service.listAll(query);
	jvo->success(res);
	return jvo;
}