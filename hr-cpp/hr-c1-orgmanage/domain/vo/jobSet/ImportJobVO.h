#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/16 20:18:47

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
#ifndef _IMPORTJOBVO_H_
#define _IMPORTJOBVO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 装载新增id的ListVO领域模型
 * 负责人：Andrew
 */
class ImportJobVO : public oatpp::DTO
{
	DTO_INIT(ImportJobVO, DTO);
	DTO_FIELD(List<String>, newId) = {};
	DTO_FIELD_INFO(newId) {
		info->description = ZH_WORDS_GETTER("jobSet.export.id");
	}
};

/**
 * 使用JsonVO封装ImportJobVO
 * 负责人：Andrew
 */
class ImportJobJsonVO : public JsonVO<ImportJobVO::Wrapper>
{
	DTO_INIT(ImportJobJsonVO, JsonVO<ImportJobVO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORTJOBVO_H_