/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/19 23:25:03

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
#include "LaborDispatchController-mg.h"
#include "../../service/laborDispatch/LaborDispatchService-mg.h"

LaborDispatchJsonMVO::Wrapper LaborDispatchMController::execQueryLaborDispatch(const LaborDispatchMQuery::Wrapper& query)
{
	// 定义Service
	LaborDispatchMService service;
	// service执行并返回数据
	auto result = service.ListAll(query);
	// 响应结果
	auto jvo = LaborDispatchJsonMVO::createShared();
	if (result->rows->empty())
	{
		jvo->fail(result);
	}
	else
	{
		jvo->success(result);
	}
	return jvo;
}

StringJsonVO::Wrapper LaborDispatchMController::execModifyLaborDispatch(const LaborDispatchUpdateDTO::Wrapper& dto)
{
	auto jvo = StringJsonVO::createShared();

	if (!dto->corporateID ||!dto->organizationID)
	{
		jvo->init("-1", RS_PARAMS_INVALID);
		return jvo;
	}
	LaborDispatchMService service;
	if (service.updateData(dto))
	{
		jvo->success(dto->corporateName);
		
	} 
	else
	{
		jvo->fail(dto->corporateName);
	}
	return jvo;
}
