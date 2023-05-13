#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/13 19:52:05

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
#ifndef _TESTDTO_H_
#define _TESTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 测试功能传输数据类型
 */
class TestDTO : public oatpp::DTO
{
public:
	TestDTO() {};
	TestDTO(UInt64 id, String name) :id(id), name(name) {};

	DTO_INIT(TestDTO, DTO);

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

/**
 * 测试功能分页传输数据类型
 */
class TestPageDTO : public PageDTO<TestDTO::Wrapper>
{
	DTO_INIT(TestPageDTO, PageDTO<TestDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTDTO_H_