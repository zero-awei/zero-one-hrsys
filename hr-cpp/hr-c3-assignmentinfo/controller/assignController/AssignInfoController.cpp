#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/5/22 14:58:43

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
#include "AssignInfoController.h"
#include "../../service/assignInfo/AssignInfoQueryService.h"
Uint64JsonVO::Wrapper AssignInfoController::execAddAssignInfo(const AddAssignInfoDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->id || !dto->assign || !dto->organize || !dto->depart || !dto->job || !dto->post || !dto->startTime || !dto->endTime)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->id->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//// 定义一个Service
	//AddAssignInfoService service;
	//// 执行数据新增
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper AssignInfoController::execDeleteAssignInfo(const DeleteAssignInfoDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	if (!dto->id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//// 定义一个Service
	//SampleService service;
	//// 执行数据删除
	//if (service.removeData(dto->id.getValue(0))) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	//// 响应结果
	return jvo;
}

//导入不需要写exec函数
//ImportAssignInfoJsonVO::Wrapper AssignInfoController::execImportAssignInfo(const ImportAssignInfoDTO::Wrapper& dto)
//{
//	// 定义返回数据对象
//	auto jvo = ImportAssignInfoJsonVO::createShared();
//	return jvo;     
//}

Uint64JsonVO::Wrapper AssignInfoController::execModifyAssignInfo(const ModifyAssignInfoDTO::Wrapper& dto)
{
	//// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	if (!dto->id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//// 定义一个Service
	//SampleService service;
	//// 执行数据修改
	//if (service.updateData(dto)) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	//// 响应结果
	return jvo;
}

AssignInfoQueryJsonVO::Wrapper AssignInfoController::execAssignQuery(const AssignInfoQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	AssignInfoQueryService service;
	//// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = AssignInfoQueryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

AssignInfoQueryDetailJsonVO::Wrapper AssignInfoController::execAssignQueryDetail(const AssignInfoQueryDetail::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = AssignInfoQueryDetailJsonVO::createShared();
	return jvo;
}