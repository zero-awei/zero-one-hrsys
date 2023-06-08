/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/24 17:41:08

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
#include "ContractStatusController.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "service/statusContract/StatusContractService.h"
/**
 * 实现合同状态下拉列表
 * 负责人：远翔
 */
PullListVO::Wrapper ConstractStatusController::execQueryContractStatus()
{
	auto dto = PullListDTO::createShared();
	StatusContractService service;
	dto = service.listAll();
	auto vo = PullListVO::createShared();
	vo->success(dto);
	return vo;
}
