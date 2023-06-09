﻿#pragma once

/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/13 19:55:40

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
#ifndef _ITEMLABELVO_H_
#define _ITEMLABELVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/itemLabel/ItemLabelDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ²âÊÔ¹¦ÄÜJsonVO
 */
class ItemLabelJsonVO : public JsonVO<ItemLabelDTO::Wrapper>
{
	DTO_INIT(ItemLabelJsonVO, JsonVO<ItemLabelDTO::Wrapper>);
};

/**
 * ²âÊÔ¹¦ÄÜ·ÖÒ³JsonVO
 */
class ItemLabelPageJsonVO : public JsonVO<ItemLabelPageDTO::Wrapper>
{
	DTO_INIT(ItemLabelPageJsonVO, JsonVO<ItemLabelPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTVO_H_