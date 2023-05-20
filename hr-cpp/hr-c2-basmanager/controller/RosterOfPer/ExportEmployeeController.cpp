#include "stdafx.h"
#include "ExportEmployeeController.h"
//#include "../../service/ExportEmployee/ExportEmployeeService.h"

//ExportEmployeePageJsonVO::Wrapper ExportEmployeeController::execQueryExportEmployee(const ExportEmployeeQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	// 定义一个Service
//	ExportEmployeeService service;
//	// 查询数据
//	auto result = service.listAll(query);
//	// 响应结果
//	auto jvo = ExportEmployeePageJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//}

Uint64JsonVO::Wrapper ExportEmployeeController::execAddExportEmployee(const ExportEmployeeDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	//if (!dto->age || !dto->name || !dto->sex)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// 有效值校验
	//if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}

	// 定义一个Service 
	//ExportEmployeeService service;
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

Uint64JsonVO::Wrapper ExportEmployeeController::execModifyExportEmployee(const ExportEmployeeDTO::Wrapper& dto)
{
	//// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	//if (!dto->id || dto->id <= 0)
	//{
	//}
	//// 定义一个Service
	//ExportEmployeeService service;
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

Uint64JsonVO::Wrapper ExportEmployeeController::execRemoveExportEmployee(const ExportEmployeeDTO::Wrapper& dto)
{
	//// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	//if (!dto->id || dto->id <= 0)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// 定义一个Service
	//ExportEmployeeService service;
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

//BooleanJsonVO::Wrapper ExportEmployeeController::execImportLEM(const ExportEmployeeDTO::Wrapper& dto)
//{
//	return BooleanJsonVO::createShared();
//}

//BooleanJsonVO::Wrapper ExportEmployeeController::execExportLEM(const ExportEmployeeQuery::Wrapper& legalEntityMaiQuery)
//{
//	return BooleanJsonVO::createShared();
//}
