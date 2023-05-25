#include "stdafx.h"
#include "EmployeeNotInArchiveController.h"

EmployeeNotInArchivePageJsonVO::Wrapper EmployeeNotInArchiveController::execQueryTest(const EmployeeNotInArchiveQuery::Wrapper& query)
{
	auto vo = EmployeeNotInArchivePageJsonVO::createShared();
	vo->success("test query success");
	return vo;
}

ArchiveOutPageJsonVO::Wrapper EmployeeNotInArchiveController::QueryTest(const ArchiveOutQuery::Wrapper& query)
{
	auto v = ArchiveOutPageJsonVO::createShared();
	v->success("test query success");
	return v;
}