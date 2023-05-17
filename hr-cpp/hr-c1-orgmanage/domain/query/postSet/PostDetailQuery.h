#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 18:36:29

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
#ifndef _POSTDETAIL_QUERY_
#define _POSTDETAIL_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询指定岗位详情
 */
class PostDetailQuery : public PageQuery
{
	DTO_INIT(PostDetailQuery, PageQuery);
	// 查询岗位名称
	DTO_FIELD(String, query);
	DTO_FIELD_INFO(query) {
		info->description = ZH_WORDS_GETTER("查询岗位名称");
	}
	// 排序方式:排序类别,(asc/desc)
	DTO_FIELD(String, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("排序方式:排序类别,(asc/desc)");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_POSTDETAIL_QUERY_