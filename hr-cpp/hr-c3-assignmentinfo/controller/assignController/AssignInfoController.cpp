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
#include "../../service/assignInfo/AssignInfoService.h"

bool isNum(string str1) {
	for (auto i : str1) {
		if (i < 48 || i > 57) {
			return false;
		}
	}
	return true;
}
StringJsonVO::Wrapper AssignInfoController::execAddAssignInfo(const AssignInfoDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->id || !dto->assign || !dto->assignState|| !dto->organize || !dto->depart || !dto->job || !dto->post || !dto->startTime || !dto->endTime)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->id->empty() && !isNum(dto->id))
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	AssignInfoService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String(id));
	}
	//响应结果
	return jvo;
}

StringJsonVO::Wrapper AssignInfoController::execDeleteAssignInfo(const AssignInfoDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	//// 参数校验
	if (!dto->id)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (!isNum(dto->id))
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	AssignInfoService service;
	// 执行数据删除
	if (service.removeData(dto->id.getValue(""))) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}

//导入不需要写exec函数
//ImportAssignInfoJsonVO::Wrapper AssignInfoController::execImportAssignInfo(const ImportAssignInfoDTO::Wrapper& dto)
//{
//	// 定义返回数据对象
//	auto jvo = ImportAssignInfoJsonVO::createShared();
//	return jvo;     
//}

StringJsonVO::Wrapper AssignInfoController::execModifyAssignInfo(const AssignInfoDTO::Wrapper& dto)
{
	//// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	//// 参数校验
	if (!dto->id)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (!isNum(dto->id))
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	AssignInfoService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}

AssignInfoPageJsonVO::Wrapper AssignInfoController::execAssignQuery(const AssignInfoQuery::Wrapper& query)
{
	// 定义一个Service
	AssignInfoService service;
	//// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = AssignInfoPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

AssignInfoJsonVO::Wrapper AssignInfoController::execAssignQueryDetail(const AssignInfoQueryDetail::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = AssignInfoJsonVO::createShared();

	//// 定义一个Service
	//AssignInfoService service;
	////// 查询数据
	//auto result = service.QueryDetail(dto);
	//jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper AssignInfoController::execExportAssign(const AssignExportQuery::Wrapper& query) {
	auto jvo = StringJsonVO::createShared();
	// 定义一个Service
	AssignInfoService service;
	//// 查询数据
	auto result = service.exportData(query);
	if (!result.empty()) {
		jvo->success(result);
	} else {
		jvo->fail("export fail");
	}
	return jvo;
}