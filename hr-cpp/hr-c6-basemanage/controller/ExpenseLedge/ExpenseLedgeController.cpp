#include "stdafx.h"
#include "ExpenseLedgeController.h"

ExpenseLedgeJsonVO::Wrapper ExpenseLedgeController::execQueryExpense(const ExpenseLedgeDTO::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = ExpenseLedgeJsonVO::createShared();
	auto result = ExpenseLedgeDTO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper ExpenseLedgeController::execGetExpense(const ExpenseLedgeDTO::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	String result;
	//此处插入测试数据
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper ExpenseLedgeController::execModifyExpense(const ExpenseLedgeDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	UInt64 res_id{};
	jvo->success(res_id);
	// 响应结果
	return jvo;
}
