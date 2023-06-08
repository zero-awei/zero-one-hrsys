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
#include "SciResultController.h"
#include"../../service/sciresult/SciResultService.h"
//查询
SciResultPageJsonVO::Wrapper SciResultController::execQueryTest(const SciResultQuery::Wrapper& query)
{
	auto vo = SciResultPageJsonVO::createShared();

	auto pdto = SciResultPageDTO::createShared();
	// 定义一个Service
	SciResultService service;
	// 查询数据

	pdto = service.listAll(query);

	vo->success(pdto);

	return vo;
}


//新增
Uint64JsonVO::Wrapper SciResultController::execAddSciResult(const Add2SciResultDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();

	if (!dto->PIMRESEARCHFINDINGSNAME || !dto->HQSJ || !dto->PIMPERSONID)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//有效值效验
	if (dto->PIMRESEARCHFINDINGSNAME->empty() || dto->HQSJ->empty()  || dto->PIMPERSONID->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	
	// TODO : 处理附件上传

	SciResultService service;
	uint64_t id = service.saveData(dto,payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}

	return jvo;
}


//删除
Uint64JsonVO::Wrapper SciResultController::execDelSciResult(const DelSciResultDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	int length = dto->deleteById->size();

	if (length <= 0 || !dto->PIMPERSONID)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		if (!(*it))
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}

     SciResultService service;
	if (service.removeData(dto))
	{
		jvo->success(1);
	}
	else
	{
		jvo->fail(1);
	}
	return jvo;
}
//导入
StringJsonVO::Wrapper SciResultController::execIntoSciResult(const String& body, const String& suffix, const String& pimpersonid, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (!pimpersonid || !body || !suffix)
	{
		jvo->fail("导入失败,文件为空");
	}
	if (pimpersonid->empty() || body->empty() || suffix->empty())
	{
		jvo->fail("导入失败,没有数据");
	}
	SciResultService service;
	service.saveManyData(body, suffix, pimpersonid,payload);
	jvo->success("文件导入成功");
	return jvo;
}





