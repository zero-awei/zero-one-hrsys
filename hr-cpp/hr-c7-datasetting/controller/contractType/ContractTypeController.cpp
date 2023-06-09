#include "stdafx.h"
#include "ContractTypeController.h"
#include"../../service/contractType/ContractTypeService.h"

ContractTypePageJsonVO::Wrapper  ContractTypeController::execQueryContractType(const ContractTypeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	ContractTypeService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	// 创建响应对象
	auto jvo = ContractTypePageJsonVO::createShared();
	// 创建分页对象
	/*auto pdto = ContractTypePageDTO::createShared();
	pdto->addData(ContractTypeDTO::createShared("1", "zs"));
	pdto->addData(ContractTypeDTO::createShared("2", "ls"));*/
	jvo->success(result);
	//jvo->success(pdto);
	return jvo;
}

Uint64JsonVO::Wrapper ContractTypeController::execAddContractType(const ContractTypeDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验&非空校验 待判断值(|| !dto->department || !dto->stat)

	if (!dto->id || !dto->name) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (stoll(dto->id) < 0 || dto->name->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	ContractTypeService service;
	// 新增数据
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	//jvo->success(1);
	return jvo;
}

Uint64JsonVO::Wrapper ContractTypeController::execModifyContractType(const ContractTypeDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验

	if (!dto->id || stoll(dto->id) <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	ContractTypeService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(stoull(dto->id));
	}
	else
	{
		jvo->fail(stoull(dto->id));
	}
	// 响应结果
	//jvo->success(1);

	return jvo;
}

Uint64JsonVO::Wrapper ContractTypeController::execRemoveContractType(const ContractTypeDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->id || stoll(dto->id) <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	ContractTypeService service;
	// 执行数据删除
	if (service.removeData(stoull(dto->id))) {
		jvo->success(stoull(dto->id));
	}
	else
	{
		jvo->fail(stoull(dto->id));
	}
	// 响应结果
	//jvo->success(1);
	return jvo;
}
