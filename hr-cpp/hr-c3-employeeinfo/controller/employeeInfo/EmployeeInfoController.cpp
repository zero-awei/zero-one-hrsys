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

StringJsonVO::Wrapper EmployeeInfoController::execEmployeeQuery(const EmployeeInfoQuery::Wrapper& query) {
	auto vo = StringJsonVO::createShared();
	vo->success("Employee information query success");
	return vo;
}
StringJsonVO::Wrapper EmployeeInfoController::execEmployeeModify(const EmployeeInfoDTO::Wrapper& dto) {
	auto vo = StringJsonVO::createShared();
	auto jvo = Uint64JsonVO::createShared();
	if (!dto->age || !dto->name || !dto->sex)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	vo->success("Employee information modify success");
	return vo;
}
StringJsonVO::Wrapper EmployeeInfoController:: execEmployeePut(const EmployeeInfoAddDTO::Wrapper& dto){
	auto vo = StringJsonVO::createShared();
	auto jvo = Uint64JsonVO::createShared();
	if (!dto->empid || !dto->name || !dto->idType || !dto->idNum)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->idType!=nullptr&&(dto->idType!="10"|| dto->idType != "20"|| dto->idType != "30"))
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if(dto->phoneNum.get()->length() != 11 || dto->state!="10"||dto->state!="20"||dto->state!="30")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	vo->success("Job list information query success");
	return vo;
}
StringJsonVO::Wrapper EmployeeInfoController::execJobListQuery(const JobListQuery::Wrapper& query) {
	auto vo = StringJsonVO::createShared();
	vo->success("Job list information query success");
	return vo;
}