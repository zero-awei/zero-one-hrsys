#pragma once
#ifndef _SAMPLE_VO_
#define _SAMPLE_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/RosterOfPer/PageQueryEmployeeListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class PageQueryEmployeeListJsonVO : public JsonVO<PageQueryEmployeeListDTO::Wrapper> {
	DTO_INIT(PageQueryEmployeeListJsonVO, JsonVO<PageQueryEmployeeListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class PageQueryEmployeeListPageJsonVO : public JsonVO<PageQueryEmployeeListDTO::Wrapper> {
	DTO_INIT(PageQueryEmployeeListPageJsonVO, JsonVO<PageQueryEmployeeListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_