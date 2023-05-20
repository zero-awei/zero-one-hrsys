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
#ifndef _AWARDLEVELDTO_H_
#define _AWARDLEVELDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 测试功能传输数据类型
 */
class AwardLevelDTO : public oatpp::DTO
{
public:
	AwardLevelDTO() {};
	AwardLevelDTO(String id, String level) :id(id), level(level) {};

	DTO_INIT(AwardLevelDTO, DTO);

	// 获奖编号
	DTO_FIELD(String,id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("common.dto.code");
	}
	// 获奖等级
	DTO_FIELD(String, level);
	DTO_FIELD_INFO(level) {
		info->description = ZH_WORDS_GETTER("common.dto.value");
	}
};

/**
 * 测试功能分页传输数据类型
 */
class AwardLevelPageDTO : public PageDTO<AwardLevelDTO::Wrapper>
{
	DTO_INIT(AwardLevelPageDTO, PageDTO<AwardLevelDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTDTO_H_