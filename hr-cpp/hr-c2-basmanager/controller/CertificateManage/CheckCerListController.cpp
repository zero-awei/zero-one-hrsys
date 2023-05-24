
#include "stdafx.h"
#include "CheckCerListController.h"
//#include "../../service/sample/SampleService.h"

CheckCerListPageJsonVO::Wrapper CheckCerListController::execQueryCheckCerList(const PageQuery::Wrapper& query)
{
	//创建响应对象
	auto vo = CheckCerListPageJsonVO::createShared();
	//创建分页对象
	auto pdto = CheckCerListPageDTO::createShared();
	pdto->addData(CheckCerListDTO::createShared(1, "zs"));
	pdto->addData(CheckCerListDTO::createShared(2, "ls"));
	//响应结果
	vo->success(pdto);
	return vo;
}
