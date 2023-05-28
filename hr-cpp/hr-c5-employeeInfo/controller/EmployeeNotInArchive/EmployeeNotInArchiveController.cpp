#include "stdafx.h"
#include "EmployeeNotInArchiveController.h"

EmployeeNotInArchivePageJsonVO::Wrapper EmployeeNotInArchiveController::execQueryTest(const EmployeeNotInArchiveQuery::Wrapper& query)
{
	auto vo = EmployeeNotInArchivePageJsonVO::createShared();
	vo->success("test query success");
	return vo;
	/*
	// ����һ��JsonVO����
	auto vo = EmployeeNotInArchivePageJsonVO::createShared();
	// ����һ����ҳ����
	auto page = EmployeeNotInArchivePageDTO::createShared();
	page->pageIndex = query->pageIndex;
	page->pageSize = query->pageSize;
	page->total = 20;
	page->calcPages();

	// ģ������ҳ����
	int64_t start = (page->pageIndex.getValue(1) - 1) * page->pageSize.getValue(1);
	int64_t end = start + page->pageSize.getValue(1);
	// �߽�ֵֵ����
	if (start >= page->total.getValue(0) || start < 0) {
		//vo->fail(page);
		return vo;
	}
	if (end > page->total.getValue(0)) end = page->total.getValue(0);
	// ѭ�����ɲ�������
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