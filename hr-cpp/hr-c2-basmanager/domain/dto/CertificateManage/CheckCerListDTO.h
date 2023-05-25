#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _CHECK_CER_DTO_
#define _CHECK_CER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class CheckCerListDTO : public oatpp::DTO
{
public:
	//�޲ι���
	CheckCerListDTO() {};
	//�вι���
	//CheckCerListDTO(UInt64 id, String name, Int32 age, String sex) {};
	CheckCerListDTO(UInt64 id, String name) :id(id), name(name) {};
	DTO_INIT(CheckCerListDTO, DTO);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// ����A
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// ����
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("sample.field.age");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("sample.field.sex");
	}
};

/**
 * ʾ����ҳ�������
 */
class CheckCerListPageDTO : public PageDTO<CheckCerListDTO::Wrapper>
{
	DTO_INIT(CheckCerListPageDTO, PageDTO<CheckCerListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 