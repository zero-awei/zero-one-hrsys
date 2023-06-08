#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/21 18:50:23

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
#ifndef _PROJTAGDO_H_
#define _PROJTAGDO_H_

#include "../DoInclude.h"

/**
 * 项目标签数据库实体类
 */

class ProjTagDO
{
	// 项目标签标识
	CC_SYNTHESIZE(string, id, Id);
	// 项目标签
	CC_SYNTHESIZE(string, tagName, TagName);
	// 建立人
	CC_SYNTHESIZE(string, creator, Creator);
	// 建立时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 更新人
	CC_SYNTHESIZE(string, updater, Updater);
	// 更新时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// 组织id
	CC_SYNTHESIZE(string, orgId, OrgId);
public:
	ProjTagDO()
	{
		id = "tag123";
		tagName = "tag-name";
		creator = "creator";
		createTime = "2000-01-01 00:00:00";
		updater = "updater";
		updateTime = "2000-01-01 00:00:00";
		orgId = "org123";
	}
};

#endif // !_PROJTAGDO_H_