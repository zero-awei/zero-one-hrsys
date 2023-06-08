#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
 @Date: 2023/02/17 16:25:30

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
#ifndef _ORGTREEDO_H_
#define _ORGTREEDO_H_

#include "../DoInclude.h"
class OrgTreeDO
{
	// 根组织ID
	CC_SYNTHESIZE(string, orgtype, OrgType);
    // 组织名字
	CC_SYNTHESIZE(string, orgname, OrgName);
    // 组织id
	CC_SYNTHESIZE(string, orgid, OrgID);
    // 父组织名字
	// CC_SYNTHESIZE(string, porgname, Porgname);
    // 父组织id
	CC_SYNTHESIZE(string, porgid, PorgID);
public:
	OrgTreeDO() {}
};

#endif // !_ORGTREEDO_H_