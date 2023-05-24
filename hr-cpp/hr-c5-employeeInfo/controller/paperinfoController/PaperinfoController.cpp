#include "stdafx.h"
#include "PaperinfoController.h"

PaperPageJsonVO::Wrapper PaperinfoController::execQueryPaperinfo(const PageQuery::Wrapper& query)
{
	// 创建响应对象
	auto vo = PaperPageJsonVO::createShared();
	// 创建分页对象
	auto pdto = PaperPageDTO::createShared();
	pdto->addData(PaperDTO::createShared());
	pdto->addData(PaperDTO::createShared());
	// 响应结果
	vo->success(pdto);
	return vo;
}

Uint64JsonVO::Wrapper PaperinfoController::execModifyPaperinfo(const PaperDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}
