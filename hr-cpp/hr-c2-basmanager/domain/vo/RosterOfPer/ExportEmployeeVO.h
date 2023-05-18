#pragma once
#ifndef _EXPORTEMPLOYEE_VO_
#define _EXPORTEMPLOYEE_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/RosterOfPer/ExportEmployeeDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ExportEmployeeVO : public JsonVO<ExportEmployeeDTO::Wrapper> {
	DTO_INIT(ExportEmployeeVO, JsonVO<ExportEmployeeDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ExportEmployeePageJsonVO : public JsonVO<ExportEmployeeDTO::Wrapper> {
	DTO_INIT(ExportEmployeePageJsonVO, JsonVO<ExportEmployeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTEMPLOYEE_VO_