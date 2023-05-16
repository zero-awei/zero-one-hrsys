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



StringJsonVO::Wrapper LaborDispatchConstroller::executeQueryAll(const PageQuery::Wrapper& query)
{
	// 响应结果
	auto vo = StringJsonVO::createShared();
	vo->success("export success");
	return vo;
}

Uint64JsonVO::Wrapper LaborDispatchConstroller::execAddLaborDispatch(const LaborDispatchDTO::Wrapper& dto)
{
	auto vo =Uint64JsonVO::createShared();
	vo->init(UInt64(-1), RS_PARAMS_INVALID);
	return vo;
}

Uint64JsonVO::Wrapper LaborDispatchConstroller::execRemoveLaborDispatch(const LaborDispatchDTO::Wrapper& dto)
{
	auto vo = Uint64JsonVO::createShared();
	vo->init(UInt64(-1), RS_PARAMS_INVALID);
	return vo;
}

StringJsonVO::Wrapper LaborDispatchConstroller::execExportLaborDispatch(const PageQuery::Wrapper& query)
{
	// 响应结果
	auto vo = StringJsonVO::createShared();
	vo->success("export success");
	return vo;
}

