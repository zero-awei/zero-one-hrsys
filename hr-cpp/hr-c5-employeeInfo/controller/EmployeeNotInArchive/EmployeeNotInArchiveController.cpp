#include "stdafx.h"
#include "EmployeeNotInArchiveController.h"

EmployeeNotInArchivePageJsonVO::Wrapper EmployeeNotInArchiveController::execQueryTest(const EmployeeNotInArchiveQuery::Wrapper& query)
{
	auto vo = EmployeeNotInArchivePageJsonVO::createShared();
	vo->success("test query success");
	return vo;
	/*
	// 定义一个JsonVO对象
	auto vo = EmployeeNotInArchivePageJsonVO::createShared();
	// 定义一个分页对象
	auto page = EmployeeNotInArchivePageDTO::createShared();
	page->pageIndex = query->pageIndex;
	page->pageSize = query->pageSize;
	page->total = 20;
	page->calcPages();

	// 模拟计算分页数据
	int64_t start = (page->pageIndex.getValue(1) - 1) * page->pageSize.getValue(1);
	int64_t end = start + page->pageSize.getValue(1);
	// 边界值值处理
	if (start >= page->total.getValue(0) || start < 0) {
		//vo->fail(page);
		return vo;
	}
	if (end > page->total.getValue(0)) end = page->total.getValue(0);
	// 循环生成测试数据
	for (int64_t i = start; i < end; i++)
	{
		auto user = EmployeeNotInArchiveDto::createShared();
		user->nummber = query->pimpersonid;
		page->addData(user);
	}
	//vo->success(page);
	return vo;*/
}

ArchiveOutPageJsonVO::Wrapper EmployeeNotInArchiveController::QueryTest(const ArchiveOutQuery::Wrapper& query)
{
	auto v = ArchiveOutPageJsonVO::createShared();
	v->success("test query success");
	return v;
}