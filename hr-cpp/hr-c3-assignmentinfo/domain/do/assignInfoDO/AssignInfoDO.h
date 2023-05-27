#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/5/26 11:52:32

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
#ifndef _ASSIGN_INFO_DO_
#define _ASSIGN_INFO_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class AssignInfoDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 分配(主分配或次分配)
	CC_SYNTHESIZE(string, assign, Assign);
	// 类型
	CC_SYNTHESIZE(string, etype, Etype);
	// 组织
	CC_SYNTHESIZE(string, organize, Organize);
	// 部门
	CC_SYNTHESIZE(string, depart, Depart);
	// 职务
	CC_SYNTHESIZE(string, job, Job);
	// 岗位
	CC_SYNTHESIZE(string, post, Post);
	// 任职开始时间
	CC_SYNTHESIZE(string, startTime, StartTime);
	// 任职结束时间
	CC_SYNTHESIZE(string, endTime, EndTime);

public:
	AssignInfoDO() {
		id = "";
		assign = "";
		etype = "";
		organize = "";
		depart = "";
		job = "";
		post = "";
		startTime = "";
		endTime = "";
	}
};

#endif // !_Assign_Info_DO_