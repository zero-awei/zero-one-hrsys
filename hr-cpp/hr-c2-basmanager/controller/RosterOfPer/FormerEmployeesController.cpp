#pragma once

/**
 *  基础管理 —— 人员花名册 —— 离职员工 —— 楚孟献
 */

/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#include "stdafx.h"
#include "FormerEmployeesController.h"
#include "../../service/RosterOfPer/FormerEmployeesService.h"

FormerEmployeesPageJsonVO::Wrapper FormerEmployeesController::execQueryFormerEmployees(const FormerEmployeesQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	FormerEmployeesService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = FormerEmployeesPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

FormerEmployeesPageJsonVO::Wrapper FormerEmployeesController::execListFormerEmployees(const FormerEmployeesQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 响应结果
	auto jvo = FormerEmployeesPageJsonVO::createShared();
	// 创建分页对象
	auto pdtd = FormerEmployeesPageDTO::createShared();
	jvo->success(pdtd);
	return jvo;
}