#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/16 14:29:12

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
#ifndef _LEGALENTITYMAIVO_H_
#define _LEGALENTITYMAIVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/LegalEntityMai/LegalEntityMaiDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* 定义一个用户信息显示JsonVO对象，用于响应给客户端 */
class LegalEntityMaiJsonVO : public JsonVO<LegalEntityMaiDTO::Wrapper>
{
	DTO_INIT(LegalEntityMaiJsonVO, JsonVO<LegalEntityMaiDTO::Wrapper>);
};

/* 定义一个用户信息分页显示JsonVO对象，用于响应给客户端 */
class LegalEntityMaiPageJsonVO : public JsonVO<LegalEntityMaiPageDTO::Wrapper>
{
	DTO_INIT(LegalEntityMaiPageJsonVO, JsonVO<LegalEntityMaiPageDTO::Wrapper>)
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAIVO_H_