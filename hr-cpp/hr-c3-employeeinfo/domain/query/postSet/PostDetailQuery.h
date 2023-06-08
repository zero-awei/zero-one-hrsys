#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/06/08 13:33:38

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
 * 岗位设置 - 查询指定岗位详情Query
 */
class PostDetailQuery : public PageQuery
{
	DTO_INIT(PostDetailQuery, PageQuery);
	// 排序类别:排序方式,(asc/desc)
	DTO_FIELD(String, sortTypeAndMethod);
	DTO_FIELD_INFO(sortTypeAndMethod) {
		info->description = ZH_WORDS_GETTER("employee.query.sortTypeAndMethod");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_POSTDETAIL_QUERY_
