#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/16 17:02:58

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
#ifndef _MENUVO_H_
#define _MENUVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/user/MenuDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个示例菜单显示JsonVO对象，用于响应给前端
 */
class MenuJsonVO : public JsonVO<List<MenuDTO::Wrapper>>
{
	DTO_INIT(MenuJsonVO, JsonVO<List<MenuDTO::Wrapper>>);
public:
	// 在构造函数中实例化data列表
	MenuJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUVO_H_