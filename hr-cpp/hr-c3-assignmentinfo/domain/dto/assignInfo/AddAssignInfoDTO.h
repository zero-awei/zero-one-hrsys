#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/5/22 14:58:43

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
#ifndef _ADD_EMPLOYEE_ASSIGN_INFO_DTO_
#define _ADD_EMPLOYEE_ASSIGN_INFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 新增指定员工分配信息
 */
class AddAssignInfoDTO : public oatpp::DTO
{
	DTO_INIT(AddAssignInfoDTO, DTO);
	//编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("employee.field.id"));
	//DTO_FIELD(String, id);
	//DTO_FIELD_INFO(id) {
	//	info->description = ZH_WORDS_GETTER("employee.field.id");
	//}
	// 分配(主分配或次分配)
	API_DTO_FIELD_DEFAULT(String, assign, ZH_WORDS_GETTER("employee.field.assign"));
	// 类型
	API_DTO_FIELD_DEFAULT(String, etype, ZH_WORDS_GETTER("employee.field.etype"));
	// 组织
	API_DTO_FIELD_DEFAULT(String, organize, ZH_WORDS_GETTER("employee.field.organize"));
	// 部门
	API_DTO_FIELD_DEFAULT(String, depart, ZH_WORDS_GETTER("employee.field.depart"));
	// 职务
	API_DTO_FIELD_DEFAULT(String, job, ZH_WORDS_GETTER("employee.field.job"));
	// 岗位
	API_DTO_FIELD_DEFAULT(String, post, ZH_WORDS_GETTER("employee.field.post"));
	// 任职开始时间
	API_DTO_FIELD_DEFAULT(String, startTime, ZH_WORDS_GETTER("employee.field.startTime"));
	// 任职结束时间
	API_DTO_FIELD_DEFAULT(String, endTime, ZH_WORDS_GETTER("employee.field.endTime"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_ADD_EMPLOYEE_ASSIGN_INFO_DTO_