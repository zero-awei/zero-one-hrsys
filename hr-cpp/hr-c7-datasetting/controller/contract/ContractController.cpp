#include "stdafx.h"
#include "ContractController.h"
#include"../../service/contract/ContractService.h"

ContractTypePageJsonVO::Wrapper ContractController::execQueryTest(const ContractTypeQuery::Wrapper& query)
{
	// 定义一个Service
	ContractService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ContractTypePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}