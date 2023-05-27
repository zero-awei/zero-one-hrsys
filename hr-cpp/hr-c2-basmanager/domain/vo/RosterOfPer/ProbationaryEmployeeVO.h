#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: awei
 @Date: $DATE$ $HOUR$:$MINUTE$:$SECOND$
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

// 试用员工响应类型

#ifndef _PROBATIONARY_EMPLOYEE_VO_
#define _PROBATIONARY_EMPLOYEE_VO_
#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/ProbationaryEmployeeDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class ProbationaryEmployeeJsonVO : public JsonVO<ProbationaryEmployeeDTO::Wrapper>
{
	DTO_INIT(ProbationaryEmployeeJsonVO, JsonVO<ProbationaryEmployeeDTO::Wrapper>);
};

/**
 * 离职员工分页传输对象
 */
class ProbationaryEmployeePageJsonVO : public JsonVO<ProbationaryEmployeePageDTO::Wrapper>
{
	DTO_INIT(ProbationaryEmployeePageJsonVO, JsonVO<ProbationaryEmployeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 
