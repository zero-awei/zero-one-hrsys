#pragma once
#ifndef _CONTRACTDO_H_
#define _CONTRACTDO_H_

#include "../DoInclude.h"

class ContractDO
{
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, name, Name);
	CC_SYNTHESIZE(string, department, Department);
	CC_SYNTHESIZE(string, state, State);
	CC_SYNTHESIZE(string, unitArrivalTime, UnitArrivalTime);
	CC_SYNTHESIZE(string, contractId, ContractId);
	CC_SYNTHESIZE(string, signingUnit, SigningUnit);
	CC_SYNTHESIZE(string, contract_category, Contract_category);
	CC_SYNTHESIZE(string, contract_type, Contract_type);
	CC_SYNTHESIZE(string, startDate, StartDate);
	CC_SYNTHESIZE(string, endDate, EndDate);
	CC_SYNTHESIZE(string, contractStatus, ContractStatus);
	CC_SYNTHESIZE(string, remainingDays, RemainingDays);
	CC_SYNTHESIZE(string, expiryDate, ExpiryDate);
};

#endif // !_CONTRACTDO_H_