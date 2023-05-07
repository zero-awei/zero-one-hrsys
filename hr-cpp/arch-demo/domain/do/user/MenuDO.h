#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#ifndef _SAMPLEMENUDO_H_
#define _SAMPLEMENUDO_H_

#include "../DoInclude.h"
/**
 * 测试菜单数据库实体
 */
class MenuDO
{
	// 唯一编号
	CC_SYNTHESIZE(string, id, Id);
	// 节点文本描述
	CC_SYNTHESIZE(string, text, Text);
	// 节点文本描述
	CC_SYNTHESIZE(string, icon, Icon);
	// 路由
	CC_SYNTHESIZE(string, href, Href);
	// 父节点ID
	CC_SYNTHESIZE(string, parentId, ParentId);
public:
	MenuDO() {}
	MenuDO(string id, string text, string icon, string href, string parentId)
	{
		this->id = id;
		this->text = text;
		this->icon = icon;
		this->href = href;
		this->parentId = parentId;
	}
};

#endif // !_SAMPLEMENUDO_H_