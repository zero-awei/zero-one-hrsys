#include "stdafx.h"
#include "BlacklistController.h"

BlacklistPageJsonVO::Wrapper BlacklistController::execQueryBlacklist(const BlacklistQuery::Wrapper& query)
{
	// ������Ӧ����
	auto vo = BlacklistPageJsonVO::createShared();
	// ������ҳ����
	auto pdto = BlacklistPageDTO::createShared();
	pdto->addData(BlacklistDTO::createShared());
	pdto->addData(BlacklistDTO::createShared());
	// ��Ӧ���
	vo->success(pdto);
	return vo;
}