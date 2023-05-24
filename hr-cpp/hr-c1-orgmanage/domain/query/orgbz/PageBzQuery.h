#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/24 0:53:06

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
#ifndef _PAGEBZQUERY_H_
#define _PAGEBZQUERY_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class PageBzQuery : public oatpp::DTO
{
	DTO_INIT(PageBzQuery, DTO);
	DTO_FIELD_INFO(size) {
		info->description = ZH_WORDS_GETTER("orgbz.pageQuery.size");
	}
	DTO_FIELD(UInt8, size);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("orgbz.pageQuery.page");
	}
	DTO_FIELD(UInt8, page);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("orgbz.pageQuery.sort");
	}
	DTO_FIELD(String, sort);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_PAGEBZQUERY_H_