#include "stdafx.h"
#include "WorkHistoryController.h"
#include "../../service/work-history/WorkHistoryService.h"

WorkHistoryVO::Wrapper WorkHistoryController::execQueryWorkHistory(const WorkHistoryQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	WorkHistoryService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = WorkHistoryVO::createShared();
	jvo->success(result);
	return jvo;
}
Uint64JsonVO::Wrapper WorkHistoryController::execModifyWorkHistory(const WorkHistoryDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->rzkssj || !dto->rzjssj|| !dto->ormorgname || !dto->ormdutyname || !dto->ormpostname || !dto->cfplx||!dto->enable)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	SampleService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->rzkssj);
		jvo->success(dto->rzjssj);
		jvo->success(dto->ormorgname);
		jvo->success(dto->ormdutyname);
		jvo->success(dto->ormpostname);
		jvo->success(dto->cfplx);
		jvo->success(dto->enable);
	}
	else
	{
		jvo->fail(dto->rzkssj);
		jvo->fail(dto->rzjssj);
		jvo->fail(dto->ormorgname);
		jvo->fail(dto->ormdutyname);
		jvo->fail(dto->ormpostname);
		jvo->fail(dto->cfplx);
		jvo->fail(dto->enable);
	}
	// 响应结果
	return jvo;
}