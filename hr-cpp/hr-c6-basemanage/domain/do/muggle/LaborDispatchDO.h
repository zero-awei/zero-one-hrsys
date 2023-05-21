/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/20 10:53:13

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
#pragma once
#ifndef _LD_M_DO_
#define _LD_M_DO_
#include "../DoInclude.h"

class LaborDispatchMDO
{
	// 公司名称
	CC_SYNTHESIZE(string, corporatename, CorporateName);
	// 公司地址
	CC_SYNTHESIZE(string, corporateAddress, CorporateAddress);
	// 公司联系人
	CC_SYNTHESIZE(string, corporateContact, CorporateContact);
	// 公司联系电话
	CC_SYNTHESIZE(string, corporateNumber, CorporateNumber);
public:
	LaborDispatchMDO() {
		corporatename = "";
		corporateAddress = "";
		corporateContact = "";
		corporateNumber = "";
	}
};
#endif