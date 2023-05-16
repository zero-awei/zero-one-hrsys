#include "stdafx.h"//cpp文件第一件事导入预编译标头
#include "TestController.h"
#include "../arch-demo/service/sample/SampleService.h"
#include "domain/dto/sample/ContractDTO.h"
StringJsonVO::Wrapper FindController::execQueryContract(const PageQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();
	vo	->success("contract get success");
	return vo; 
}

StringJsonVO::Wrapper FindController::execQueryPerson(const PageQuery_person::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();
	vo->success("person information get success");
	return vo;
}

//Uint64JsonVO::Wrapper FindController::execAddSample(const SampleDTO::Wrapper& dto)
//{
//	// 定义返回数据对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 参数校验
//	// 非空校验
//	if (!dto->age || !dto->name || !dto->sex)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 有效值校验
//	if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	// 定义一个Service
//	SampleService service;
//	// 执行数据新增
//	uint64_t id = service.saveData(dto);
//	if (id > 0) {
//		jvo->success(UInt64(id));
//	}
//	else
//	{
//		jvo->fail(UInt64(id));
//	}
//	//响应结果
//	return jvo;
//}

Uint64JsonVO::Wrapper FindController::execAddContract(const ContractDTO::Wrapper& dto)
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
	return jvo;

	//// 定义一个Service
	//SampleService service;
	//// 执行数据新增
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	////响应结果
	//return jvo;
}

Uint64JsonVO::Wrapper FindController::execRemoveContract(const ContractDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	//if (!dto->id || dto->id <= 0)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
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

//StringJsonVO::Wrapper Person_FindController::execQueryPerson(const PageQuery::Wrapper& query)
//{
//	auto vo = StringJsonVO::createShared();
//	vo->success("person information get success");
//	return vo;
//}
