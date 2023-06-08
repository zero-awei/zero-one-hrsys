#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/05/24 17:58:45

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
#ifndef _DELETEPROJTAGDTO_H_
#define _DELETEPROJTAGDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeleteProjTagDTO : public oatpp::DTO
{
	DTO_INIT(DeleteProjTagDTO, DTO);
	DTO_FIELD(String, tagId);
	DTO_FIELD_INFO(tagId) {
		info->description = ZH_WORDS_GETTER("projTag.tagId");
	}
};

/**
 * 删除多条岗位信息传输对象
 */
class DeleteProjTagBatchDTO : public oatpp::DTO
{
	DTO_INIT(DeleteProjTagBatchDTO, DTO);
	// 岗位集标识集
	DTO_FIELD(oatpp::List<String>, tagIds);
	DTO_FIELD_INFO(tagIds) {
		info->description = ZH_WORDS_GETTER("projTag.tagIds");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETEPROJTAGDTO_H_