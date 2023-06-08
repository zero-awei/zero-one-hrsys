#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
 @Date: 2022/10/25 11:08:56

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
#ifndef _ORG_SERVICE_
#define _ORG_SERVICE_
#include <list>
// #include "domain/vo/org/"
#include "domain/dto/org/OrgTreeDTO.h"
#include "dao/org/OrgDAO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class OrgService
{
public:
	// 查询部门结构树
	vector<shared_ptr<OrgTreeDTO>> getOrgTree(const string& userID);
};

#endif // !_ORG_SERVICE_

