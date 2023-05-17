#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 13:50:53

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _CONTRACTDO_H_
#define _CONTRACTDO_H_

#include "../DoInclude.h"

class ContractDO
{
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, name, Name);
	CC_SYNTHESIZE(string, unit, Unit);
	CC_SYNTHESIZE(string, state, State);
	CC_SYNTHESIZE(string, unitTime, UnitTime);
	CC_SYNTHESIZE(string, contractID, ContractID);
	CC_SYNTHESIZE(string, contractUnit, ContractUnit);
	CC_SYNTHESIZE(string, contractCategory, ContractCategory);
	CC_SYNTHESIZE(string, contractType, ContractType);
	CC_SYNTHESIZE(string, startDate, StartDate);
	CC_SYNTHESIZE(string, endDate, EndDate);
	CC_SYNTHESIZE(string, contractStatus, ContractStatus);
	CC_SYNTHESIZE(string, remaining, Remaining);
	CC_SYNTHESIZE(string, trialExpiration, TrialExpiration);
};

#endif // !_CONTRACTDO_H_