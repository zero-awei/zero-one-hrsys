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


StringJsonVO::Wrapper AssignInfoController::execAddAssignInfo(const AssignInfoCommonDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->assignId)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	AssignInfoService service;
	// 执行数据新增
	auto id = service.saveData(dto,payload);
	if (id > 0) {
		jvo->success(to_string(id));
	}
	else
	{
		jvo->fail(to_string(id));
	}
	//响应结果
	return jvo;
}

StringJsonVO::Wrapper AssignInfoController::execDeleteAssignInfo(const AssignInfoDeleteDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	//// 参数校验
	if (!dto->assignId)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	AssignInfoService service;
	auto id = service.removeData(dto->assignId.getValue(""));
	// 执行数据删除
	if (id) {
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String(id));
	}
	// 响应结果
	return jvo;
}


StringJsonVO::Wrapper AssignInfoController::execModifyAssignInfo(const AssignInfoCommonDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	//// 参数校验
	if (!dto->assignId)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	AssignInfoService service;
	auto id = service.updateData(dto,payload);
	// 执行数据修改
	if (id) {
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String(id));
	}
	// 响应结果
	return jvo;
}

AssignInfoPageJsonVO::Wrapper AssignInfoController::execAssignQuery(const AssignInfoQuery::Wrapper& query, const PayloadDTO& payload)
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

AssignInfoQueryJsonVO::Wrapper AssignInfoController::execAssignQueryDetail(const AssignInfoQueryDetail::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = AssignInfoQueryJsonVO::createShared();

	//// 定义一个Service
	AssignInfoService service;
	////// 查询数据
	auto result = service.QueryDetail(dto);
	jvo->success(result);
	return jvo;
}

//导入员工信息
ImportAssignJsonVO::Wrapper AssignInfoController::execImportAssignInfo(const ImportAssignInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 构建返回VO
	auto vo = ImportAssignJsonVO::createShared();
	// 参数校验
	if (dto->filePath->empty()) {
		vo->init({}, RS_PARAMS_INVALID);
		return vo;
	}

	// 构建返回样例
	/*String str1 = "123abc";
	String str2 = "456def";
	String str3 = "789ghi";
	auto ij = ImportJobVO::createShared();
	ij->newId->push_back("123abc");
	ij->newId->push_back("456def");
	ij->newId->push_back("789ghi");
	vo->init(ij, RS_SUCCESS);*/

	// TODO: 调用service
	std::list<std::string> result;
	AssignInfoService service;
	auto res = service.addMultiAssignInfo(dto, payload);

	if (res->newId->size())
		vo->init(res, RS_SUCCESS);
	else
		vo->init(res, RS_FAIL);

	return vo;

}

MulDeleteAssignInfoVO::Wrapper  AssignInfoController::execMulDeleteAssignInfoById(const MulDeleteAssignInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto vo = MulDeleteAssignInfoVO::createShared();
	// 参数校验
	if (!dto->assignIds)
	{
		vo->init(dto, RS_PARAMS_INVALID);
		return vo;
	}
	AssignInfoService service;
	auto result = service.removeMulData(dto);
	// 执行数据删除
	if (result) {
		vo->success(dto);
	}
	else
	{
		vo->fail(dto);
	}
	return vo;
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