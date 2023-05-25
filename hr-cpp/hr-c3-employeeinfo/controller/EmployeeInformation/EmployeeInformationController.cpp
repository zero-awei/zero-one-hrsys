#include "stdafx.h"
#include "EmployeeInformationController.h"
//#include "../../service/EmployeeInformation/EmployeeInformationService.h"

//分页查询员工列表
EmployeeInformationPageJsonVO::Wrapper EmployeeInformationController::execEmployeeInformation(const EmployeeInformationPageQuery::Wrapper& query)
{
	// 定义一个Service
	//EmployeeInformationService service;
	// 查询数据
	//auto result = service.listAll(query);
	// 响应结果
	auto jvo = EmployeeInformationPageJsonVO::createShared();
	return jvo;

}
//导入员工信息
EmployeeInformationPageJsonVO::Wrapper EmployeeInformationController::execImportEmployeeInfo(const EmployeeInformationPageQuery::Wrapper& importInfo)
{
	// 定义一个Service
	//EmployeeInformationService service;
	// 查询数据
	//auto result = service.listAll(importInfo);
	// 响应结果
	auto jvo = EmployeeInformationPageJsonVO::createShared();
	//jvo->success(result);
	return jvo;

}
//导出员工信息(导出本页在前端完成)
EmployeeInformationPageJsonVO::Wrapper EmployeeInformationController::execExportEmployeeInfo(const EmployeeInformationPageQuery::Wrapper& exportInfo)
{
	// 定义一个Service
	//EmployeeInformationService service;
	// 查询数据
	//auto result = service.listAll(exportInfo);
	// 响应结果
	auto jvo = EmployeeInformationPageJsonVO::createShared();
	//jvo->success(result);
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
	if (dto->id->empty() || dto->name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//// 定义一个Service
	//EmployeeInformationService service;
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