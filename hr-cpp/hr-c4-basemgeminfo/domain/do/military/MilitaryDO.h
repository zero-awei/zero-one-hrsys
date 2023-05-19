#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 19:42:46

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
#ifndef _MILITARYDO_H_
#define _MILITARYDO_H_
#include "../DoInclude.h"

class MilitaryDO
{

	CC_SYNTHESIZE(string, UPDATEDATE, _UPDATEDATE);
	CC_SYNTHESIZE(string, PIMARMYCADRESNAME, _PIMARMYCADRESNAME);
	CC_SYNTHESIZE(string, FJ, _FJ);
	CC_SYNTHESIZE(string, CREATEDATE, _CREATEDATE);
	CC_SYNTHESIZE(string, UPDATEMAN, _UPDATEMAN);
	CC_SYNTHESIZE(string, ENABLE, _ENABLE);
	CC_SYNTHESIZE(string, PIMARMYCADRESID, _PIMARMYCADRESID);
	CC_SYNTHESIZE(string, CREATEMAN, _CREATEMAN);
	CC_SYNTHESIZE(string, PIMPERSONID, _PIMPERSONID);
	CC_SYNTHESIZE(string, FSSJ, _FSSJ);
	CC_SYNTHESIZE(string, JLSS, _JLSS);
	CC_SYNTHESIZE(string, JLSPZT, _JLSPZT);
	CC_SYNTHESIZE(string, JLGLBH, _JLGLBH);
	CC_SYNTHESIZE(string, JLCZZ, _JLCZZ);
	CC_SYNTHESIZE(string, TROOPTYPE, _TROOPTYPE);
	CC_SYNTHESIZE(string, LEVELTYPE, _LEVELTYPE);
	CC_SYNTHESIZE(string, REASON, _REASON);
};

#endif // !_MILITARYDO_H_