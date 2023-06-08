/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/21 12:05:31

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
#pragma once
#ifndef _LDJ_M_VO_
#define _LDJ_M_VO_
#include "../../GlobalInclude.h"
#include "domain/vo/JsonVO.h"
#include "domain/dto/LaborDispatch/LaborDispatchDTO-mg.h"
#include "domain/dto/LaborDispatch/LaborDispatchDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class LaborDispatchJsonMVO : public JsonVO<LaborDispatchPageMDTO::Wrapper>
{
	DTO_INIT(LaborDispatchJsonMVO, JsonVO<LaborDispatchPageMDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_LDJ_M_VO_
