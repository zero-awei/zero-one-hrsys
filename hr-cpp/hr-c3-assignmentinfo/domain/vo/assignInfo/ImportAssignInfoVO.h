#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/06/06 11:50:24

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
#ifndef _IMPORT_ASSIGN_INFO_V0_
#define _IMPORT_ASSIGN_INFO_V0_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 装载新增id的ListVO领域模型
 */
class ImportInfoJsonVO : public oatpp::DTO
{
	DTO_INIT(ImportInfoJsonVO, DTO);
	DTO_FIELD(List<String>, newId) = {};
	DTO_FIELD_INFO(newId) {
		info->description = ZH_WORDS_GETTER("importInfo.import.id");
	}
};

/**
 * 使用JsonVO封装importAssignInfoVO
 */
class ImportAssignJsonVO : public JsonVO<ImportInfoJsonVO::Wrapper>
{
	DTO_INIT(ImportAssignJsonVO, JsonVO<ImportInfoJsonVO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORT_ASSIGN_INFO_V0_