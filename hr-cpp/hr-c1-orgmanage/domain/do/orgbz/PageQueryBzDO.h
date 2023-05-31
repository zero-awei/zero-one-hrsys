#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/31 0:46:24

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
#ifndef _PAGEQUERYBZDO_H_
#define _PAGEQUERYBZDO_H_
#include "../DoInclude.h"
class PageQueryBzDO
{
	// 组织机构id
	CC_SYNTHESIZE(string, orgid, Orgid);
	// '组织机构
	CC_SYNTHESIZE(string, orgname, Orgname);
	// 部门
	CC_SYNTHESIZE(string, orgsectorname, Orgsectorname);
	// 部门组织编号
	CC_SYNTHESIZE(string, orgcode, Orgcode);
	// 人数编制
	CC_SYNTHESIZE(string, jhry, Jhry);
	// 实际人数编制
	CC_SYNTHESIZE(string, sjry, Sjry);


public:
	PageQueryBzDO()
	{
		orgid = "";
		orgname = "";
		orgsectorname = "";
		orgcode = "";
		jhry = "";
		sjry = "";

	}
};

#endif // !_PAGEQUERYBZDO_H_