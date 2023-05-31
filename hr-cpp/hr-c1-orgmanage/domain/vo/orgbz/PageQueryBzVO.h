#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/30 20:56:02

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
#ifndef _PAGEQUERYBZVO_H_
#define _PAGEQUERYBZVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/orgbz/PageQueryBzDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询编制查询
 */
class PageQueryBzVO : public JsonVO<PageQueryBzDTO::Wrapper>
{
	DTO_INIT(PageQueryBzVO, JsonVO<PageQueryBzDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAGEQUERYBZVO_H_