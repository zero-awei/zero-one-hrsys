#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
 @Date: 2022/10/25 11:52:32

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
#ifndef _ORG_SECTOR_DO_
#define _ORG_SECTOR_DO_
#include "../DoInclude.h"

class OrgSectorDO
{
    // 部门名字
	CC_SYNTHESIZE(string, orgsectorname, OrgSectorName);
    // 部门id
	CC_SYNTHESIZE(string, orgsectorid, OrgSectorID);
    // 组织名字
	CC_SYNTHESIZE(string, orgid, OrgID);
    // 组织id
	CC_SYNTHESIZE(string, orgname, OrgName);
public:
	OrgSectorDO() {
        orgsectorname = "";
        orgsectorid = "";
        orgid = "";
        orgname = "";
    }

};

#endif // !_ORG_SECTOR_DO_