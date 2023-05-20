#pragma once
#ifndef _PAGEQUERYVO_H_
#define _PAGEQUERYVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/pageQuery/PageQueryDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 下拉列表VO领域模型
 * 负责人：Andrew
 */
class PageQueryVO : public JsonVO<PageQueryDTO::Wrapper>
{
	DTO_INIT(PageQueryVO, JsonVO<PageQueryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAGEQUERYVO_H_