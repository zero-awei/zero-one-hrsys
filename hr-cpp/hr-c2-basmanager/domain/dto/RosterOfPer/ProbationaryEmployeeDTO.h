#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _PROBATIONARY_EMPLOYEE_DTO_
#define _PROBATIONARY_EMPLOYEE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 试用人员传输对象
 */
class ProbationaryEmployeeDTO : public oatpp::DTO
{
public:
	//无参构造
	ProbationaryEmployeeDTO() {};

	DTO_INIT(ProbationaryEmployeeDTO, DTO);
	// 编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 姓名A
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// 组织
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.zz");
	}
	// 部门
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.bm");
	}
	// 职务
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.zw");
	}
	// 岗位
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.gw");
	}
	// 任职时间
	DTO_FIELD(String, rzsj);
	DTO_FIELD_INFO(rzsj) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.rzsj");
	}
	// 试用到期时间
	DTO_FIELD(String, time);
	DTO_FIELD_INFO(time) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.time");
	}
};

/**
 * 示例分页传输对象
 */
class ProbationaryEmployeePageDTO : public PageDTO<ProbationaryEmployeeDTO::Wrapper>
{
	DTO_INIT(ProbationaryEmployeePageDTO, PageDTO<ProbationaryEmployeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 