#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/24 13:59:37

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
#ifndef _Root_Org_DO_
#define _Root_Org_DO_
#include "../DoInclude.h"

/*
根组织实体类
*/
class RootOrgDO
{
	// 搜索匹配
	CC_SYNTHESIZE(string, filter, Filter);
	// 排序方式
	CC_SYNTHESIZE(string, sort, Sort);
public:
	RootOrgDO() {
		filter = "";
		sort = "";
	}
};

#endif // !_Root_Org_DO_
