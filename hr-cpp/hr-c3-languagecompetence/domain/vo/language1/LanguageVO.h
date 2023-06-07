#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/21 1:24:39

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
#ifndef _LANGUAGE_VO_
#define _LANGUAGE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/language/LanguageDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 语言能力显示JsonVO，用于响应给客户端的Json对象
 * 负责人：君
 */
class LanguageJsonVO : public JsonVO<LanguageDTO::Wrapper> {
	DTO_INIT(LanguageJsonVO, JsonVO<LanguageDTO::Wrapper>);
};

/**
 * 语言能力分页显示JsonVO，用于响应给客户端的Json对象
 * 负责人：君
 */
class LanguagePageJsonVO : public JsonVO<LanguagePageDTO::Wrapper> {
	DTO_INIT(LanguagePageJsonVO, JsonVO<LanguagePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LANGUAGE_VO_