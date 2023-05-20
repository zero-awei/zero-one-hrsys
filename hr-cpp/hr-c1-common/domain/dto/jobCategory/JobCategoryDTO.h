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
#ifndef _JOBCATEGORYDTO_H_
#define _JOBCATEGORYDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 测试功能传输数据类型
 */
class JobCategoryDTO : public oatpp::DTO
{
public:
	JobCategoryDTO() {};
	JobCategoryDTO(UInt32 key, String job) :key(key), job(job) {};

	DTO_INIT(JobCategoryDTO, DTO);

	// 获奖编号
	DTO_FIELD(UInt32, key);
	DTO_FIELD_INFO(key) {
		info->description = ZH_WORDS_GETTER("common.dto.code");
	}
	// 获奖等级
	DTO_FIELD(String, job);
	DTO_FIELD_INFO(job) {
		info->description = ZH_WORDS_GETTER("common.dto.value");
	}



};

/**
 * 测试功能分页传输数据类型
 */
template <typename T>
class ListDTO : public oatpp::DTO
{
	DTO_INIT(ListDTO, DTO);
	DTO_FIELD_INFO(pullList) {
		info->description = ZH_WORDS_GETTER("common.dto.list");
	}
	DTO_FIELD(List<T>, pullList) = {};
};

class PullListDTO : public ListDTO<JobCategoryDTO::Wrapper>
{
	DTO_INIT(PullListDTO, ListDTO<JobCategoryDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTDTO_H_#pragma once
