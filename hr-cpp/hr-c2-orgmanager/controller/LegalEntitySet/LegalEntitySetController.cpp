#include "stdafx.h"
#include "LegalEntitySetController.h"

//（数据设置——法人主体设置——导出法人主体设置(导出页面在前端完成) --cpt

Uint64JsonVO::Wrapper LegalEntitySetController::execAddLegalEntitySet(const LegalEntitySetDTO::Wrapper& dto) {
	return Uint64JsonVO::createShared();
}

LegalEntitySetPageJsonVO::Wrapper LegalEntitySetController::execExportLegalEntitySet(const LegalEntitySetQuery::Wrapper& query, const PayloadDTO& payload) {
	return LegalEntitySetPageJsonVO::Wrapper();
}

LegalEntitySetPageJsonVO::Wrapper LegalEntitySetController::execLegalEntitySetPullDownList(const LegalEntitySetQuery::Wrapper& query, const PayloadDTO& payload) {
	return LegalEntitySetPageJsonVO::Wrapper();
}

Uint64JsonVO::Wrapper LegalEntitySetController::execModifyLegalEntitySet(const LegalEntitySetDTO::Wrapper& dto) {
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}
