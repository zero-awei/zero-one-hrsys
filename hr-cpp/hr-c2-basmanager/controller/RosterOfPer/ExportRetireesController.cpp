#include "stdafx.h"
#include "ExportRetireesController.h"
//#include "../../service/sample/SampleService.h"
/**
 * 人员花名册-（离退休员工-导出员工）--pine
 */
ExportRetireesPageJsonVO::Wrapper ExportRetireesController::execQueryExportRetirees(const PageQuery::Wrapper& query)
{
	//创建响应对象
	auto vo = ExportRetireesPageJsonVO::createShared();
	//创建分页对象
	auto pdto = ExportRetireesPageDTO::createShared();
	pdto->addData(ExportRetireesDTO::createShared(5, "zs"));
	pdto->addData(ExportRetireesDTO::createShared(6, "ls"));
	//响应结果
	vo->success(pdto);
	return vo;
}
