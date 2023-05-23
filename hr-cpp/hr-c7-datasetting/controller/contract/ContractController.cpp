#include "stdafx.h"
#include "ContractController.h"
//#include"../../service/contract/ContractService.h"

ContractTypePageJsonVO::Wrapper ContractController::execQueryContractType(const ContractTypeQuery::Wrapper& query)
{
	//// 定义一个Service
	//ContractService service;
	//// 查询数据
	//auto result = service.listAll(query);
	// 响应结果
	// 创建响应对象
	auto jvo = ContractTypePageJsonVO::createShared();
	// 创建分页对象
	auto pdto = ContractTypePageDTO::createShared();
	pdto->addData(ContractTypeDTO::createShared("1", "zs"));
	pdto->addData(ContractTypeDTO::createShared("2", "ls"));
	//jvo->success(result);
	jvo->success(pdto);
	return jvo;
}

Uint64JsonVO::Wrapper ContractController::execAddContractType(const ContractTypeDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验&非空校验 待判断值(|| !dto->department || !dto->stat)

	//if (!dto->id || !dto->name || !dto->contractId || !dto->contract_type) {
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// 有效值校验
	//if (stoi(dto->id) < 0 || dto->name->empty() || dto->contractId->empty() || dto->contract_type->empty()) {
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}

	//// 定义一个Service
	//ContractService service;
	//// 新增数据
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	//响应结果
	jvo->success(1);
	return jvo;
}

Uint64JsonVO::Wrapper ContractController::execModifyContractType(const ContractTypeDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验

	/*if (!dto->id || stoi(dto->id) <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/

	//// 定义一个Service
	//ContractService service;
	//// 执行数据修改
	//if (service.updateData(dto)) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	// 响应结果
	jvo->success(1);
	return jvo;
}

Uint64JsonVO::Wrapper ContractController::execRemoveContractType(const ContractTypeDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验

	/*if (!dto->id || stoi(dto->id) <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}*/

	//// 定义一个Service
	//ContractService service;
	//// 执行数据删除
	//if (service.removeData(stoull(dto->id))) {
	//	jvo->success(dto->id);
	//}
	//else
	//{
	//	jvo->fail(dto->id);
	//}
	//// 响应结果
	jvo->success(1);
	return jvo;
}
