#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/24 14:16:12

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
#ifndef _SECTORDO_H_
#define _SECTORDO_H_
#include "../DoInclude.h"

/*
组织实体类
*/
class SectorDO
{
	// 查询Sector的parent是OrmOrg还是OrmOrgsector
	CC_SYNTHESIZE(string, parentdename, Parentdename);
	// 查询的parent id
	CC_SYNTHESIZE(string, parentkey, Parentkey);
	// 排序方式
	CC_SYNTHESIZE(string, sort, Sort);
public:
	SectorDO() {
		parentdename = "";
		parentkey = "";
		sort = "";
	}
};

#endif // !_SECTORDO_H_
