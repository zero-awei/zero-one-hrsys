#include "stdafx.h"
#include "PaperinfoController.h"
#include "../../service/paperinfo/PaperinfoService.h"

StringJsonVO::Wrapper PaperinfoController::execQueryPaperinfo(const PageQuery::Wrapper& query)
{
	// 定义一个Service
	PaperinfoService service;
	// 查询数据
	auto result = service.listByPimpersonId(query);
	// 响应结果
	auto jvo = PaperPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

	//auto vo = StringJsonVO::createShared();
	//vo->success("test query success");
	//return vo;
}
