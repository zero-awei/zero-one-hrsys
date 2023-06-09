#pragma once
#ifndef _QUALIFICATIONVO_H_
#define _QUALIFICATIONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Qualification/QualificationDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个证书信息显示JsonVO对象，用于响应给客户端
 */

class QualificationJsonVO : public JsonVO<QualificationDTO::Wrapper>
{
	DTO_INIT(QualificationJsonVO, JsonVO<QualificationDTO::Wrapper>);
};

/**
 * 定义一个证书信息分页显示JsonVO对象，用于响应给客户端
 */
class QualificationPageJsonVO : public JsonVO<QualificationPageDTO::Wrapper>
{
	DTO_INIT(QualificationPageJsonVO, JsonVO<QualificationPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif
