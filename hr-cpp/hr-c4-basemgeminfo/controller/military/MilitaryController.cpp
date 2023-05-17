#include "stdafx.h"
#include "MilitaryController.h"
#include "../../service/military/MilitaryService.h"

MilitaryJsonVO::Wrapper MilitaryController::execQueryMilitary(const MilitaryDetailQuery::Wrapper& query) {
	// 定义一个Service
	MilitaryService service;
	// 查询数据
	auto result = service.listDetail(query);
	// 响应结果
	auto jvo = MilitaryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper MilitaryController::execModifyMilitary(const MilitaryDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (dto->PIMARMYCADRESID.getValue("").empty())
	{
		jvo->init(String("PIMARMYCADRESID must be not null"), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	MilitaryService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->PIMARMYCADRESID);
	}
	else
	{
		jvo->fail(dto->PIMARMYCADRESID);
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper MilitaryController::execDownloadMilitary(const MilitaryDownloadQuery::Wrapper& query)
{
	// 创建响应对象
	auto vo = StringJsonVO::createShared();
	// 响应结果
	vo->success("Download-Link");
	return vo;
}
