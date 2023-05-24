#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/17 22:56:57

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
#ifndef _PULLLISTVO_H_
#define _PULLLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/pullList/PullListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 下拉列表VO领域模型
 * 负责人：Andrew
 */
class PullListVO : public JsonVO<PullListDTO::Wrapper>
{
	DTO_INIT(PullListVO, JsonVO<PullListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_PULLLISTVO_H_
