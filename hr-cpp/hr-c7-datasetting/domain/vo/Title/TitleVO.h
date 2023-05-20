#pragma once
#ifndef _TITLEVO_H_
#define _TITLEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Title/TitleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个职称目录信息显示JsonVO对象，用于响应给客户端
 */
class TitleJsonVO : public JsonVO<TitleDTO::Wrapper>
{
	DTO_INIT(TitleJsonVO, JsonVO<TitleDTO::Wrapper>);
};

/**
 * 定义一个职称目录信息分页显示JsonVO对象，用于响应给客户端
 */
class TitlePageJsonVO : public JsonVO<TitlePageDTO::Wrapper>
{
	DTO_INIT(TitlePageJsonVO, JsonVO<TitlePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif