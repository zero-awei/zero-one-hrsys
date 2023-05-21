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
#include "LaborDispatchController.h"
#include "../../service/muggle/LaborDispatchService.h"

LaborDispatchJsonMVO::Wrapper LaborDispatchMController::execQueryLaborDispatch(const LaborDispatchMQuery::Wrapper& query)
{
	// 定义Service
	LaborDispatchMService service;
	// service执行并返回数据
	auto result = service.ListData(query);
	// 响应结果
	auto vo = LaborDispatchJsonMVO::createShared();
	vo->success(result);
	return vo;
}

StringJsonVO::Wrapper LaborDispatchMController::execModifyLaborDispatch()
{
	return StringJsonVO::Wrapper();
}
