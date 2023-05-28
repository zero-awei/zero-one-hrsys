/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/27 10:04:04

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
#include "AddJobController.h"
#include "service/jobSet/JobSetService.h"

StringJsonVO::Wrapper AddJobController::execAddJob(const AddJobDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 构建返回对象
	auto jvo = StringJsonVO::createShared();

	// 参数校验
	if (!dto->orgId || dto->orgId->empty())
	{
		jvo->init("", RS_PARAMS_INVALID);
		return jvo;
	}

	// TODO: 调用service
	JobSetService service;
	auto id = service.saveJob(dto, payload);
	if (!id.empty())
	{
		jvo->init(id, RS_SUCCESS);
	}
	else
	{
		jvo->init(id, RS_FAIL);
	}
	return jvo;
}
