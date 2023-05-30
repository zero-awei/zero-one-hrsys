#include "stdafx.h"
#include "ScientificController.h"
#include "../../service/scientific/ScientificService.h"

ScientificJsonVO::Wrapper ScientificController::execQueryScientific(const ScientificViewQuery::Wrapper& query) {
	// 定义一个Service
	ScientificService service;
	// 查询数据
	auto result = service.listDetail(query);
	// 响应结果
	auto jvo = ScientificJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper ScientificController::execModifyScientific(const ScientificDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	 //参数校验
	if (dto->pimresearchfindingsid.getValue("").empty())
	{
		jvo->init(String("pimresearchfindingsid must be not null"), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ScientificService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->pimresearchfindingsid);
	}
	else
	{
		jvo->fail(dto->pimresearchfindingsid);
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper ScientificController::execDownloadScientific(const ScientificDownloadQuery::Wrapper& query)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	string filedName = ScientificService().download(query);
	// 响应结果
	if (filedName.empty()) {
		jvo->fail("download failed!");
	}
	else {
		jvo->success(filedName);
	}
	return jvo;
}