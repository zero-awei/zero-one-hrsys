#include "stdafx.h"
#include "WorkHistoryController.h"
#include "../../service/work-history/WorkHistoryService.h"

WorkHistoryJsonVO::Wrapper WorkHistoryController::execQueryWorkHistory(const WorkHistoryQuery::Wrapper& query, const PayloadDTO& payload)
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
		/*jvo->success(dto->rzjssj);
		jvo->success(dto->ormorgname);
		jvo->success(dto->ormdutyname);
		jvo->success(dto->ormpostname);
		jvo->success(dto->cfplx);
		jvo->success(dto->enable);*/
	}
	else
	{
		jvo->fail(dto->rzkssj);
		/*jvo->fail(dto->rzjssj);
		jvo->fail(dto->ormorgname);
		jvo->fail(dto->ormdutyname);
		jvo->fail(dto->ormpostname);
		jvo->fail(dto->cfplx);
		jvo->fail(dto->enable);*/
	}
	// 响应结果
	return jvo;
}