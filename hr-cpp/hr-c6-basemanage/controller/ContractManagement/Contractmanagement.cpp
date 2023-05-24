
#include "stdafx.h"
#include "Contractmanagement.h"

StringJsonVO::Wrapper ContractmanageController::execQueryContractmanage(const PageQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();
	vo->success("Contractmanage test qurey success");
	return vo;
}