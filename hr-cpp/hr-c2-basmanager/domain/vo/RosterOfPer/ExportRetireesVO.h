#pragma once
#ifndef _EXPORT_RETIREES_VO_
#define _EXPORT_RETIREES_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/ExportRetireesDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExportRetireesJsonVO : public JsonVO<ExportRetireesDTO::Wrapper> {
	DTO_INIT(ExportRetireesJsonVO, JsonVO<ExportRetireesDTO::Wrapper>);
};

class ExportRetireesPageJsonVO : public JsonVO<ExportRetireesPageDTO::Wrapper> {
	DTO_INIT(ExportRetireesPageJsonVO, JsonVO<ExportRetireesPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORT_RETIREES_VO_