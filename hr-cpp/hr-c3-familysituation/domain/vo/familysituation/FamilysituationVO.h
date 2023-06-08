#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Marvin
 @Date: 2023/05/18 20:10:24

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
#ifndef _FAMILYSITUATIONVO_H_
#define _FAMILYSITUATIONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/familysituation/FamilysituationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 家庭情况显示JsonVO，用于响应给客户端的Json对象
 */
class FamilysituationJsonVO : public JsonVO<FamilysituationDTO::Wrapper>
{
	DTO_INIT(FamilysituationJsonVO, JsonVO<FamilysituationDTO::Wrapper>);
};

/**
 * 家庭情况分页显示JsonVO，用于响应给客户端的Json对象
 */
class FamilysituationPageJsonVO : public JsonVO<FamilysituationPageDTO::Wrapper> {
	DTO_INIT(FamilysituationPageJsonVO, JsonVO<FamilysituationPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FAMILYSITUATIONVO_H_