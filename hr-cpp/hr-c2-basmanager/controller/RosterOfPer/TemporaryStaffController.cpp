#include "stdafx.h"
#include "TemporaryStaffController.h"
#include "./service/RosterOfPer/TemporaryStaffService.h"
TemporaryStaffPageJsonVO::Wrapper TempStaffController::execQueryTempstaff(const TempStaffQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	TemporaryStaffService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = TemporaryStaffPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper TempStaffController::execExportTempstaff(const TempStaffQuery::Wrapper& query, const PayloadDTO& payload)
{
	return StringJsonVO::Wrapper();
}
