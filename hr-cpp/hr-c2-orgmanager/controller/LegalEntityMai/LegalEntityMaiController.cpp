#include "stdafx.h"
#include "LegalEntityMaiController.h"


LegalEntityMaiPageJsonVO::Wrapper LegalEntityMaiController::executeQueryById(const LegalEntityMaiQuery::Wrapper& legalEntityMaiQuery)
{
	// 定义一个JsonVO对象
	auto vo = LegalEntityMaiPageJsonVO::createShared();
	// 定义一个分页对象
	auto pageDTO = LegalEntityMaiPageDTO::createShared();
	pageDTO->addData(LegalEntityMaiDTO::createShared("1", "zs"));
	pageDTO->addData(LegalEntityMaiDTO::createShared("2", "ls"));
	// 响应结果
	vo->success(pageDTO);
	return vo;
}

