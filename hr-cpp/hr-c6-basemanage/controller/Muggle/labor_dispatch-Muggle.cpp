#include "stdafx.h"
#include "labor_dispatch-Muggle.h"

LaborDispatchJsonMVO::Wrapper LaborDispatchMController::execQueryLaborDispatch(const LaborDispatchMQuery::Wrapper& query)
{
	auto dto = LaborDispatchMDTO::createShared();
	dto->corporateAddress = "cosmic";
	dto->corporateContact = "muggle";
	dto->corporateName = "zerone";
	dto->corporateNumber = "8848";
	auto vo = LaborDispatchJsonMVO::createShared();
	vo->success(dto);
	return vo;
}

StringJsonVO::Wrapper LaborDispatchMController::execModifyLaborDispatch()
{
	return StringJsonVO::Wrapper();
}
