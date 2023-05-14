#include "stdafx.h"
#include "ContractController.h"

ContractPageJsonVO::Wrapper ContractController::execQueryContract(const ContractQuery::Wrapper& query) {
	// ÏìÓ¦½á¹û
	auto jvo = ContractPageJsonVO::createShared();
	jvo->success(ContractPageDTO::createShared());
	return jvo;
}