#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 17:33:12

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
#ifndef _POSTDELETE_DTO_
#define _POSTDELETE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 删除单条岗位信息传输对象
 */
class PostDeleteDTO : public oatpp::DTO
{
	DTO_INIT(PostDeleteDTO, DTO);
	// 岗位集标识
	DTO_FIELD(String, ormPostId);
	DTO_FIELD_INFO(ormPostId) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.ormPostId");
	}
};

/**
 * 删除多条岗位信息传输对象
 */
class PostDeleteBatchDTO : public oatpp::DTO
{
	DTO_INIT(PostDeleteBatchDTO, DTO);
	// 岗位集标识集
	DTO_FIELD(oatpp::List<String>, ormPostIds);
	DTO_FIELD_INFO(ormPostIds) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.ormPostIds");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_POSTDELETE_DTO_