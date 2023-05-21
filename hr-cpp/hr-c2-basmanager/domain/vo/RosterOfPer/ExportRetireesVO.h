#pragma once
#ifndef _EXPORT_RETIREES_VO_
#define _EXPORT_RETIREES_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/ExportRetireesDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ExportRetireesJsonVO : public JsonVO<ExportRetireesDTO::Wrapper> {
	DTO_INIT(ExportRetireesJsonVO, JsonVO<ExportRetireesDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ExportRetireesPageJsonVO : public JsonVO<ExportRetireesPageDTO::Wrapper> {
	DTO_INIT(ExportRetireesPageJsonVO, JsonVO<ExportRetireesPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 