#include "stdafx.h"//cpp文件第一件事导入预编译标头
#include "controller/GoshController/TestController.h"
#include "service/Gosh/GoshService.h"
#include "domain/vo/Gosh/ContractVO.h"

//演示查询合同信息
ContractPageJsonVO::Wrapper GoshController::execQueryContract(const ContractQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	GoshService service;
	// 查询数据
	auto result = service.listContract(query);
	// 响应结果
	auto jvo = ContractPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//演示查询个人信息
ContractPageJsonVO::Wrapper GoshController::execQueryPerson(const ContractQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	GoshService service;
	// 查询数据
	auto result = service.listContract(query);
	// 响应结果
	auto jvo = ContractPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//演示新增合同数据
Uint64JsonVO::Wrapper GoshController::execAddContract(const ContractDTO_gs::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (dto->name->empty() || dto->type->empty() || dto->variety->empty() || dto->date->empty() || dto->condition->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	GoshService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id >= 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}
//演示删除合同数据
Uint64JsonVO::Wrapper GoshController::execRemoveContract(const ContractDTO_gs_delete::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	if (!dto->id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	GoshService service;
	// 执行数据删除
	if (service.removeData(dto->id.getValue(0))) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}