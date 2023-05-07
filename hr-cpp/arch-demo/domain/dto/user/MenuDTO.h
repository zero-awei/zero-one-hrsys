#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/04/11 15:00:21

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
#ifndef _MENUDTO_H_
#define _MENUDTO_H_

#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例菜单数据传输对象
 */
class MenuDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(MenuDTO, DTO);
	// 菜单名称
	DTO_FIELD(String, text);
	DTO_FIELD_INFO(text) {
		info->description = ZH_WORDS_GETTER("user.field.menuname");
	}
	// 图标名称
	DTO_FIELD(String, icon);
	DTO_FIELD_INFO(icon) {
		info->description = ZH_WORDS_GETTER("user.field.menuicon");
	}
	// 路由地址
	DTO_FIELD(String, href);
	DTO_FIELD_INFO(href) {
		info->description = ZH_WORDS_GETTER("user.field.menuhref");
	}
	// 子菜单
	DTO_FIELD(List<MenuDTO::Wrapper>, children) = {};
	DTO_FIELD_INFO(children) {
		info->description = ZH_WORDS_GETTER("user.field.menusub");
	}
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<MenuDTO>(child), Wrapper::Class::getType()));
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUDTO_H_