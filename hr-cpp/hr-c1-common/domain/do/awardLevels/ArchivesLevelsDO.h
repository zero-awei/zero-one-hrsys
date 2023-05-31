#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/25 0:52:24

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
#ifndef _ARCHIVESLEVELSDO_H_
#define _ARCHIVESLEVELSDO_H_
#include "../DoInclude.h"
class ArchivesLevelsDO
{
	
	//获奖情况标识
	CC_SYNTHESIZE(string, pcmawardswonsid, Pcmawardswonsid);
	//获奖等级
	CC_SYNTHESIZE(string, awardlevel, Awardlevel);

public:
	ArchivesLevelsDO() {
		
		pcmawardswonsid = "";
		awardlevel = "";
	}
	ArchivesLevelsDO(string code, string val) {

		pcmawardswonsid = code;
		awardlevel = val;
	}
};

#endif // !_ARCHIVESLEVELSDO_H_