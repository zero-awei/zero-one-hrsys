#include "stdafx.h"
#include "JobTitleController.h"

JTQueryPageJsonVO::Wrapper JobTitleController::execQueryPage(const PageQuery::Wrapper& query)
{
	auto Dto = JobTitlePageDTO::createShared();
	auto Jvo = JTQueryPageJsonVO::createShared();
	cout << "实现分页查询(无参数)" << endl;
	Jvo->success(Dto);
	return Jvo;
}

JTQueryPageJsonVO::Wrapper JobTitleController::execQueryPageSB(const RetirementQuery::Wrapper& query)
{
	auto Dto = JobTitlePageDTO::createShared();
	auto Jvo = JTQueryPageJsonVO::createShared();
	cout << "实现分页查询(有参数，搜索框使用)" << endl;
	Jvo->success(Dto);
	return JTQueryPageJsonVO::Wrapper();
}

Uint64JsonVO::Wrapper JobTitleController::execRemoveJobTitle(const JobTitleDTO::Wrapper& dto)
{
	auto Jvo = Uint64JsonVO::createShared();
	cout << "实现职务删除" << endl;
	Jvo->success(dto->id);
	return Jvo;
}

Uint64JsonVO::Wrapper JobTitleController::execAddJobTitle(const JobTitleDTO::Wrapper& dto)
{
	auto Jvo = Uint64JsonVO::createShared();
	cout << "实现添加职称" << endl;
	Jvo->success(dto->id);
	return Uint64JsonVO::Wrapper();
}
