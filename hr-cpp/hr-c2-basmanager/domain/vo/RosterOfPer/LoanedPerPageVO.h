#pragma once
/*
（人员花名册-借调人员-分页查询员工列表（导出本页在前端完成））--luoluo
*/
#ifndef _LOANEDPERPAGE_VO_
#define _LOANEDPERPAGE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/LoanedPerPageDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class LoanedPerVO : public JsonVO<LoanedPerDTO::Wrapper> {
	DTO_INIT(LoanedPerVO, JsonVO<LoanedPerDTO::Wrapper>);
};

class LoanedPerPageVO : public JsonVO<LoanedPerPageDTO::Wrapper> {
	DTO_INIT(LoanedPerPageVO, JsonVO<LoanedPerPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LOANEDPERPAGE_VO_