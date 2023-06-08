#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/30 20:53:07

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
#ifndef _EMPLOYEEINFOVO_H_
#define _EMPLOYEEINFOVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/employeeInfo/EmployeeInfoDTO.h"
#include "../../dto/employeeInfo/EmployeeInfoAddDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/* *
* 指定员工员工信息导出vo
* 执行人：Detachment
*/
class EmployeeInfoVO : public JsonVO<EmployeeInfoQuery::Wrapper>
{
	DTO_INIT(EmployeeInfoVO, JsonVO<EmployeeInfoQuery::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_EMPLOYEEINFOVO_H_