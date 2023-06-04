#pragma once
/**
 * 人员花名册 - 试用人员响应类型实现 - 楚孟献
 */

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
#endif // !_PROBATIONARY_EMPLOYEE_VO_
