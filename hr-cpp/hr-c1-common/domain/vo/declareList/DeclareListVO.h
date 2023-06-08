//2023年5月20日
//申报类型下拉列表
//作者：狗皮电耗子
#pragma once
#ifndef _DECLARE_LIST_
#define _DECLARE_LIST_

#include "../../GlobalInclude.h"
#include "../../dto/declareType/DeclareTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeclareListVO : public JsonVO<DeclareTypeListDTO::Wrapper>
{
	DTO_INIT(DeclareListVO, JsonVO<DeclareTypeListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif