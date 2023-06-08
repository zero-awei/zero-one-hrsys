#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/27 10:11:00

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
#ifndef _ADDJOBDTO_H_
#define _ADDJOBDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddJobDTO : public oatpp::DTO
{
	DTO_INIT(AddJobDTO, DTO);
	// 岗位集名称
	DTO_FIELD(String, postName);
	DTO_FIELD_INFO(postName) {
		info->description = ZH_WORDS_GETTER("jobSet.add.postName");
	}
	// 岗位集标识
	/*DTO_FIELD(String, postId);
	DTO_FIELD_INFO(postId) {
		info->description = ZH_WORDS_GETTER("jobSet.add.postId");
	}*/
	// 组织标识
	DTO_FIELD(String, orgId);
	DTO_FIELD_INFO(orgId) {
		info->description = ZH_WORDS_GETTER("jobSet.add.orgId");
	}
	// 岗位类型
	DTO_FIELD(String, jobType);
	DTO_FIELD_INFO(jobType) {
		info->description = ZH_WORDS_GETTER("jobSet.add.jobType");
	}
	// 岗位分类
	DTO_FIELD(String, jobClass);
	DTO_FIELD_INFO(jobClass) {
		info->description = ZH_WORDS_GETTER("jobSet.add.jobClass");
	}
	// 是否临时数据
	DTO_FIELD(String, isTemp);
	DTO_FIELD_INFO(isTemp) {
		info->description = ZH_WORDS_GETTER("jobSet.add.isTemp");
	}
	// 是否保密岗位
	DTO_FIELD(String, isConfidential);
	DTO_FIELD_INFO(isConfidential) {
		info->description = ZH_WORDS_GETTER("jobSet.add.isConfidential");
	}
	// 岗位性质
	DTO_FIELD(String, postNature);
	DTO_FIELD_INFO(postNature) {
		info->description = ZH_WORDS_GETTER("jobSet.add.postNature");
	}
	// 是否关键岗位
	DTO_FIELD(String, isKeyPostion);
	DTO_FIELD_INFO(isKeyPostion) {
		info->description = ZH_WORDS_GETTER("jobSet.add.isKeyPostion");
	}
	// 启用标识
	DTO_FIELD(String, sign);
	DTO_FIELD_INFO(sign) {
		info->description = ZH_WORDS_GETTER("jobSet.add.sign");
	}
	// 建议交流年限
	DTO_FIELD(UInt32, yearLimit);
	DTO_FIELD_INFO(yearLimit) {
		info->description = ZH_WORDS_GETTER("jobSet.add.yearLimit");
	}
	// 必须交流年限
	DTO_FIELD(UInt32, mustYearLimit);
	DTO_FIELD_INFO(mustYearLimit) {
		info->description = ZH_WORDS_GETTER("jobSet.add.mustYearLimit");
	}
public:
	AddJobDTO()
	{
		sign = "";
		isKeyPostion = "";
		postNature = "";
		isConfidential = "";
		isTemp = "";
		jobClass = "";
		jobType = "";
		orgId = "";
		postName = "";
		yearLimit = 1;
		mustYearLimit = 1;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDJOBDTO_H_