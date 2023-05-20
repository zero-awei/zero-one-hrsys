#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/17 23:04:11

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
#ifndef _PULLLISTDTO_H_
#define _PULLLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ItemDTO : public oatpp::DTO
{
	DTO_INIT(ItemDTO, DTO);
	// 列表项代号
	DTO_FIELD_INFO(key) {
		info->description = ZH_WORDS_GETTER("common.dto.code");
	}
	DTO_FIELD(UInt32, key);
	// 对应值
	DTO_FIELD_INFO(val) {
		info->description = ZH_WORDS_GETTER("common.dto.value");
	}
	DTO_FIELD(String, val);

public:
	ItemDTO()
	{
		key = 1;
		val = "否";
	}

	ItemDTO(Int32 k, String v)
	{
		key = k;
		val = v;
	}
};

template <typename T>
class ListDTO : public oatpp::DTO
{
	DTO_INIT(ListDTO, DTO);
	DTO_FIELD_INFO(pullList) {
		info->description = ZH_WORDS_GETTER("common.dto.list");
	}
	DTO_FIELD(List<T>, pullList) = {};
};

class PullListDTO : public ListDTO<ItemDTO::Wrapper>
{
	DTO_INIT(PullListDTO, ListDTO<ItemDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_PULLLISTDTO_H_