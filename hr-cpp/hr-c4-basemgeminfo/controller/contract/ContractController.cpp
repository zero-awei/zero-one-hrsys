/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/08 21:19:56

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
#include "ContractController.h"
#include"../../service/contract/ContractService.h"

ContractPageJsonVO::Wrapper ContractController::execQueryTest(const ContractQuery::Wrapper& query)
{
	// 定义一个Service
	ContractService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ContractPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
