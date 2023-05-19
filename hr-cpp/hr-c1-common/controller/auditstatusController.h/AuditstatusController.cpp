#include "stdafx.h"
#include "AuditstatusController.h"


StringJsonVO::Wrapper AuditstatusController::execQueryAuditstatus(const AuditstatusQuery::Wrapper& auditstatusQuery)
{
	auto vo =StringJsonVO::createShared();

	vo->success("query user success");
	return vo;
}

