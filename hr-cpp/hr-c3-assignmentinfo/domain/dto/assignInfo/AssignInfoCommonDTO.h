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
#ifndef _ASSIGN_INFO_COMMON_DTO_
#define _ASSIGN_INFO_COMMON_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 新增指定员工分配信息
 */
class AssignInfoCommonDTO : public oatpp::DTO
{
	DTO_INIT(AssignInfoCommonDTO, DTO);
	//分配信息标识
	API_DTO_FIELD_DEFAULT(String, assignId, ZH_WORDS_GETTER("employee.t_pimperson.assignId"));
	//编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("employee.t_pimperson.id"));
	//DTO_FIELD(String, id);
	//DTO_FIELD_INFO(id) {
	//	info->description = ZH_WORDS_GETTER("employee.field.id");
	//}
	// 分配(主分配或次分配)
	API_DTO_FIELD_DEFAULT(String, assign, ZH_WORDS_GETTER("employee.t_pimperson.assign"));
	//分配状态
	API_DTO_FIELD_DEFAULT(String, assignState, ZH_WORDS_GETTER("employee.t_pimperson.assignState"));
	// 类型
	API_DTO_FIELD_DEFAULT(String, etype, ZH_WORDS_GETTER("employee.t_pimperson.etype"));
	// 组织
	API_DTO_FIELD_DEFAULT(String, organize, ZH_WORDS_GETTER("employee.t_pimperson.organize"));
	// 部门
	API_DTO_FIELD_DEFAULT(String, depart, ZH_WORDS_GETTER("employee.t_pimperson.depart"));
	// 职务
	API_DTO_FIELD_DEFAULT(String, job, ZH_WORDS_GETTER("employee.t_pimperson.job"));
	// 岗位
	API_DTO_FIELD_DEFAULT(String, post, ZH_WORDS_GETTER("employee.t_pimperson.post"));
	// 任职开始时间
	API_DTO_FIELD_DEFAULT(String, startTime, ZH_WORDS_GETTER("employee.t_pimperson.startTime"));
	// 任职结束时间
	API_DTO_FIELD_DEFAULT(String, endTime, ZH_WORDS_GETTER("employee.t_pimperson.endTime"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_ASSIGN_INFO_COMMON_DTO_