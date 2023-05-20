/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/20 19:17:59
*/
#ifndef _EDUCATIONJSONVO_H_
#define _EDUCATIONJSONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Education/EducationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EducationSingleJsonVO : public JsonVO<EducationSingleDTO::Wrapper>
{
	DTO_INIT(EducationSingleJsonVO, JsonVO<EducationSingleDTO::Wrapper>);
	
};

class EducationPageJsonVO : public JsonVO<EducationPageDTO::Wrapper>
{
	DTO_INIT(EducationPageJsonVO, JsonVO<EducationSingleDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATIONJSONVO_H_#pragma once
