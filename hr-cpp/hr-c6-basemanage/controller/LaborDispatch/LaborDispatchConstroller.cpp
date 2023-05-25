/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/15 15:32:21

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
#include "LaborDispatchConstroller.h"
#include "service/laborDispatch/LaborDispatchService-mh.h"



LaborDispatchPageJsonVO::Wrapper LaborDispatchConstroller::executeQueryAll_ld(const LaborDispatchQuery::Wrapper& query)
{
	//定义一个Service
	LaborDispatchService service;
	//查询数据
	auto result = service.listAll_ld(query);
	//响应结果
	auto jvo = LaborDispatchPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper LaborDispatchConstroller::execAddLaborDispatch_ld(const LaborDispatchDTO::Wrapper& dto)
{
	auto vo =Uint64JsonVO::createShared();
	vo->init(UInt64(1), RS_SUCCESS);
	return vo;
}

Uint64JsonVO::Wrapper LaborDispatchConstroller::execRemoveLaborDispatch_ld(const LaborDispatchDTO::Wrapper& dto)
{
	auto vo = Uint64JsonVO::createShared();
	vo->init(UInt64(1), RS_SUCCESS);
	return vo;
}

StringJsonVO::Wrapper LaborDispatchConstroller::execExportLaborDispatch_ld(const LaborDispatchDTO::Wrapper& dto)
{
	auto vo = StringJsonVO::createShared();
	vo->success("export success");
	return vo;
}

