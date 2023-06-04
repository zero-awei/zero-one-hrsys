#include "stdafx.h"
#include "ExpenseLedgeController.h"
#include "../../service/Expense/ExpenseLedgeService.h"

ExpenseLedgerJsonVO::Wrapper ExpenseLedgeController::execQueryExpense(const ExpenseLedgerDTO::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = ExpenseLedgerJsonVO::createShared();
	ExpenseLedgerService service;
	auto result = service.queryDataDetail(query);
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper ExpenseLedgeController::execGetExpense(const ExpenseLedgerDTO::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	ExpenseLedgerService service;
	auto res = service.listAllExpense(query);
	//此处插入测试数据
	if (res.empty())
		jvo->fail(res);
	else
		jvo->success(res);
	return jvo;
}

Uint64JsonVO::Wrapper ExpenseLedgeController::execModifyExpense(const ExpenseLedgerDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	ExpenseLedgerService service;
	auto res = service.updateData(dto);
	if (res)
		jvo->success(res);
	else
		jvo->fail(res);
	// 响应结果
	return jvo;
}
