#include "stdafx.h"
#include "AuditstatusController.h"


AuditstatusPageJsonVO::Wrapper AuditstatusController::executeQueryAuditstatus(const AuditstatusQuery::Wrapper& auditstatusQuery)
{
	auto vo = AuditstatusPageJsonVO::createShared();

	vo->success("query user success");
	return vo;
}

