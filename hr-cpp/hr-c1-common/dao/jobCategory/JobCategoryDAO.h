#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/23 23:42:52

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
#ifndef _JOBCATEGORYDAO_H_
#define _JOBCATEGORYDAO_H_

#include "BaseDAO.h"
#include "domain/do/jobCategory/JobCategoryDO.h"
class JobCategoryDAO : public BaseDAO
{
private:
	// 岗位类型对应哈希表
	unordered_map<string, string> jobCategory = {
		{"9171", u8"房屋建筑类"},
		{"9191", u8"基础设施类"},
		{"9163", u8"金融投资类"},
		{"9183", u8"勘察设计类"},
		{"9153", u8"职能管理类"},
	};
public:
	// 查询数据
	list<JobCategoryDO> selectAll();
	// 返回下拉列表
	unordered_map<string, string> getMapList();
};

#endif // !_ARMYLEVELTYPEDAO_H_#pragma once
