#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 18:20:09

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
#ifndef _LANGUAGE_QUERY_
#define _LANGUAGE_QUERY_

#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 语言指定查询对象
 */
class LanguageQuery : public oatpp::DTO
{
	DTO_INIT(LanguageQuery, DTO);
	//编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	//姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	//性别
	/*DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("sample.field.sex");
	}
	//年龄
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("sample.field.age");
	}*/
	//语种
	DTO_FIELD(String, languageType);
	DTO_FIELD_INFO(languageType) {
		info->description = ZH_WORDS_GETTER("user.language.type");
	}
	//语言等级
	DTO_FIELD(String, languageLevel);
	DTO_FIELD_INFO(languageLevel) {
		info->description = ZH_WORDS_GETTER("user.language.level");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LANGUAGE_QUERY_
