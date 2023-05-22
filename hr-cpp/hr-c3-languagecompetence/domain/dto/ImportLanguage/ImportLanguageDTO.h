#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/17 19:52:10

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
#ifndef _IMPORTLANGUAGEDTO_H_
#define _IMPORTLANGUAGEDTO_H_

#include "../../GlobalInclude.h"
#include "../Language/LanguageDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 语言指定导入对象
 */
class ImportLanguageDTO : public PageDTO<LanguageDTO::Wrapper>
{
	DTO_INIT(ImportLanguageDTO, DTO);
	//文件路径
	DTO_FIELD(String, url);
	DTO_FIELD_INFO(url) {
		info->description = "URL";
	}
	// 编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORTLANGUAGEDTO_H_