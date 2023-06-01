/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/27 0:21:35

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
#ifndef _EXPENSELEDGER_DO_
#define _EXPENSELEDGER_DO_
#include "../DoInclude.h"

class ExpenseLedgerDO
{
	//费用台账名称
	CC_SYNTHESIZE(string, name, Name);
	//费用台账标识
	CC_SYNTHESIZE(string, id, Id);
	//更新人
	CC_SYNTHESIZE(string, updateman, Updateman);
	//建立时间
	CC_SYNTHESIZE(string, createdate, Createdate);
	//建立人
	CC_SYNTHESIZE(string, createman, Createman);
	//更新时间
	CC_SYNTHESIZE(string, updatedate, Updatedate);

	//费用类别
	CC_SYNTHESIZE(string, fylb, Fylb);
	//费用金额
	CC_SYNTHESIZE(long double, fyje, Fyje);
	//发放人数
	CC_SYNTHESIZE(int, ffrs, Ffrs);
	//发放时间
	CC_SYNTHESIZE(string, ffsj, Ffsj);
	//费用标准
	CC_SYNTHESIZE(string, fybz, Fybz);
	//备注
	CC_SYNTHESIZE(string, bz, Bz);
	// 组织标识
	CC_SYNTHESIZE(string, ormorgid, Ormorgid);
public:
	ExpenseLedgerDO() {
		name = "";
		id = "";
		createdate = "";
		createman = "";
		updateman = "";
		updatedate = "";

		fylb = "";
		fyje = 0;
		ffrs = 0;
		ffsj = "";
		fybz = "";
		bz = "";
		ormorgid = "";
	}
};
#endif