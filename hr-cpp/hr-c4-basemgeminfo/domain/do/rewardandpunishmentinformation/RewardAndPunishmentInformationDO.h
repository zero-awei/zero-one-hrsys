#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: arui
 @Date: 2023/05/24 20:13:43

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
#ifndef _REWARDANDPUNISHMENTINFORMATIONDO_H_
#define _REWARDANDPUNISHMENTINFORMATIONDO_H_
#include "../DoInclude.h"

class RewardAndPunishmentInformationDO
{
	CC_SYNTHESIZE(string, lx, Lx);
	CC_SYNTHESIZE(string, pimrewardpunishmentname, Pimrewardpunishmentname);
	CC_SYNTHESIZE(string, jcjb, Jcjb);
	CC_SYNTHESIZE(double, jcje, Jcje);
	CC_SYNTHESIZE(string, jlsj, Jlsj);
	CC_SYNTHESIZE(string, jcsj, Jcsj);
	CC_SYNTHESIZE(string, bz, Bz);
	CC_SYNTHESIZE(string, fj, Fj);
	CC_SYNTHESIZE(string, pimpersonid, Pimpersonid);
	CC_SYNTHESIZE(string, pimrewardpunishmentid, Pimrewardpunishmentid);
	CC_SYNTHESIZE(string, updateman, Updateman);
	CC_SYNTHESIZE(string, createman, Createman);
	CC_SYNTHESIZE(string, createdate, Createdate);
	CC_SYNTHESIZE(string, updatedate, Updatedate);




public:
	RewardAndPunishmentInformationDO() = default;

	RewardAndPunishmentInformationDO(std::vector<std::string> vec)
	{
		int i = 0;
		setLx(vec[i++]);
		setPimrewardpunishmentname(vec[i++]);
		setJcjb(vec[i++]);
		setJlsj(vec[i++]);
		setJcsj(vec[i++]);
		setBz(vec[i++]);
		setFj(vec[i++]);
	}
};

#endif // !_REWARDANDPUNISHMENTINFORMATIONDO_H_