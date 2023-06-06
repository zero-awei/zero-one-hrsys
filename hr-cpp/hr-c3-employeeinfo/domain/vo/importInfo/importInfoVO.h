#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/06/06 9:37:23

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
#ifndef _IMPORTINFOV0_H_
#define _IMPORTINFOV0_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 装载新增id的ListVO领域模型
 */
class importInfoVO : public oatpp::DTO
{
	DTO_INIT(importInfoVO, DTO);
	DTO_FIELD(List<String>, newId) = {};
	DTO_FIELD_INFO(newId) {
		info->description = ZH_WORDS_GETTER("importInfo.import.id");
	}
};

/**
 * 使用JsonVO封装importInfoVO   
 */
class ImportJobJsonVO : public JsonVO<importInfoVO::Wrapper>
{
	DTO_INIT(ImportJobJsonVO, JsonVO<importInfoVO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORTINFOV0_H_