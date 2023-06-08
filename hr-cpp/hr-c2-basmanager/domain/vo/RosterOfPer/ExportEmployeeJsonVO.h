#pragma once
/*
（人员花名册-人员花名册-导出员工（导出本页在前端完成））--luoluo
*/
#ifndef _EXPORTEMPLOYEE_VO_
#define _EXPORTEMPLOYEE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/ExportEmployeeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExportEmployeeJsonVO : public JsonVO<ExportEmployeeDTO::Wrapper> {
	DTO_INIT(ExportEmployeeJsonVO, JsonVO<ExportEmployeeDTO::Wrapper>);
};

class ExportEmployeePageJsonVO : public JsonVO<ExportEmployeePageDTO::Wrapper> {
	DTO_INIT(ExportEmployeePageJsonVO, JsonVO<ExportEmployeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTEMPLOYEE_VO_