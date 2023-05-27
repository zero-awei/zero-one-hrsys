#pragma once
/*
（人员花名册-借调人员-分页查询员工列表（导出本页在前端完成））--luoluo
*/
#ifndef _LOANEDPERPAGE_VO_
#define _LOANEDPERPAGE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/LoanedPerPageDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class LoanedPerVO : public JsonVO<LoanedPerDTO::Wrapper> {
	DTO_INIT(LoanedPerVO, JsonVO<LoanedPerDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class LoanedPerPageVO : public JsonVO<LoanedPerPageDTO::Wrapper> {
	DTO_INIT(LoanedPerPageVO, JsonVO<LoanedPerPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LOANEDPERPAGE_VO_