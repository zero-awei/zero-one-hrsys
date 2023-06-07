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
#ifndef _ASSIGN_INFO_DELETE_DTO_
#define _ASSIGN_INFO_DELETE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 新增指定员工分配信息
 */
class AssignInfoDeleteDTO : public oatpp::DTO
{
	DTO_INIT(AssignInfoDeleteDTO, DTO);
	//分配信息标识
	API_DTO_FIELD_DEFAULT(String, assignId, ZH_WORDS_GETTER("employee.t_pimperson.assignId"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // ! _ASSIGN_INFO_DELETE_DTO_