/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/20 15:29:33

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
#include "ModifyProjTagController.h"
#include "SimpleDateTimeFormat.h"
#include "service/projTag/ProjTagService.h"

StringJsonVO::Wrapper ModifyProjTagController::execModifyTag(const ModifyTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 创建返回参数
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->tagId || dto->tagId->empty())
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// TODO: 调用service执行更新
	ProjTagService service;
	if (service.updateProjTag(dto, payload))
	{
		jvo->success(dto->tagId);
	}
	else
	{
		jvo->fail(dto->tagId);
	}

	return jvo;
}
