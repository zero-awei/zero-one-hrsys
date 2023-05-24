
#include "stdafx.h"
#include "CheckRetiresListController.h"
//#include "../../service/sample/SampleService.h"

CheckRetiresListPageJsonVO::Wrapper CheckRetiresListController::execQueryCheckRetiresList(const PageQuery::Wrapper& query)
{
	//创建响应对象
	auto vo = CheckRetiresListPageJsonVO::createShared();
	//创建分页对象
	auto pdto = CheckRetiresListPageDTO::createShared();
	pdto->addData(CheckRetiresListDTO::createShared(3, "zs"));
	pdto->addData(CheckRetiresListDTO::createShared(4, "ls"));
	//响应结果
	vo->success(pdto);
	return vo;
}
