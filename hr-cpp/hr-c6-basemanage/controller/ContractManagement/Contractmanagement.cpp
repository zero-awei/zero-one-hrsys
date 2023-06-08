
#include "stdafx.h"
#include "Contractmanagement.h"
#include "service/reitirement/contractManagerService.h"

contractManagerQueryPageJsonVO::Wrapper ContractmanageController::execQueryContractmanage(const contractManagerQuery::Wrapper& query)
{
	// 定义一个Service
	contractManagerService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = contractManagerQueryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}