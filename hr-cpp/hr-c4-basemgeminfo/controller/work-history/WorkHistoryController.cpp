#include "stdafx.h"
#include "WorkHistoryController.h"
#include "../../service/work-history/WorkHistoryService.h"

WorkHistoryJsonVO::Wrapper WorkHistoryController::execQueryWorkHistory(const WorkHistoryQuery::Wrapper& query)
{
	// 定义一个Service
	WorkHistoryService service;
	// 查询数据
	auto result = service.listDetail(query);
	// 响应结果
	auto jvo = WorkHistoryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
StringJsonVO::Wrapper WorkHistoryController::execModifyWorkHistory(const WorkHistoryDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (dto->rzkssj.getValue("").empty())
	{
		jvo->init(String("Rzkssj must be not null"), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	WorkHistoryService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->rzkssj);
		
	}
	else
	{
		jvo->fail(dto->rzkssj);
		
	}
	// 响应结果
	return jvo;
}