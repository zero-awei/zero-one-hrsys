#include "stdafx.h"
#include "EmployeeInformationController.h"
#include "service/EmployeeInformation/EmployeeInformationServicer.h"

//分页查询员工列表
EmployeeInformationPageJsonVO::Wrapper EmployeeInformationController::execEmployeeInformation(const EmployeeInformationPageQuery::Wrapper& query)
{
	// 定义一个Service
	EmployeeInformationServicer service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = EmployeeInformationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
//导入员工信息
Uint64JsonVO::Wrapper EmployeeInformationController::execImportEmployeeInfo(const EmployeeInformationDTO::Wrapper& importInfo)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!importInfo->id || !importInfo->name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (importInfo->id->empty() || importInfo->name->empty() || importInfo->age < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	EmployeeInformationServicer service;
	// 执行数据新增
	uint64_t id = service.saveData(importInfo);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;

}
//导出员工信息(导出本页在前端完成)
StringJsonVO::Wrapper EmployeeInformationController::execExportEmployeeInfo(const EmployeeExportQuery::Wrapper& query)
{
	auto jvo = StringJsonVO::createShared();
	// 定义一个Service
	EmployeeInformationServicer service;
	//// 查询数据
	// auto result = service.exportData(query);
	// if (!result.empty()) {
	// 	jvo->success(result);
	// } else {
	// 	jvo->fail("export fail");
	// }
	return jvo;
}

//新增员工信息 
Uint64JsonVO::Wrapper EmployeeInformationController::execAddEmployee(const EmployeeInformationDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->id || !dto->name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->id->empty() || dto->name->empty()|| dto->age < 0 )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	EmployeeInformationServicer service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}