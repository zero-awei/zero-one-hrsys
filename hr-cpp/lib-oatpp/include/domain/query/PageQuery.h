#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:35:41

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
#ifndef _PAGE_QUERY_
#define _PAGE_QUERY_
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 分页查询对象父类，后续分页查询对象可以继承它
 */
class PageQuery : public oatpp::DTO
{
	// 初始化定义
	DTO_INIT(PageQuery, DTO);
	// 查询页码
	DTO_FIELD(UInt64, pageIndex) = 1;
	DTO_FIELD_INFO(pageIndex) {
#ifndef LINUX
		info->description = u8"当前页码";
#else
		info->description = "curr page index";
#endif
	}
	// 查询条数
	DTO_FIELD(UInt64, pageSize) = 5;
	DTO_FIELD_INFO(pageSize) {
#ifndef LINUX
		info->description = u8"每页数据条数";
#else
		info->description = "curr page size";
#endif
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PAGE_QUERY_
