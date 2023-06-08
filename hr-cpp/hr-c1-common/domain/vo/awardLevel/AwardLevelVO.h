#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanchen
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
#ifndef _AWARDLEVELVO_H_
#define _AWARDLEVELVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/awardLevel/AwardLevelDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * »ñ½±µÈ¼¶JsonVO
 */
class AwardLevelPageJsonVO : public JsonVO<AwardLevelPageDTO::Wrapper>
{
	DTO_INIT(AwardLevelPageJsonVO, JsonVO<AwardLevelPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTVO_H_