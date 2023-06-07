#pragma once
#ifndef _QULIFICATIONVO_H_
#define _QULIFICATIONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Qulification/QulificationDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个执业资格信息显示JsonVO对象，用于响应给客户端
 */

class qulificationJsonVO : public JsonVO<QulificationDTO::Wrapper>
{
	DTO_INIT(QulificationJsonVO, JsonVO<QulificationDTO::Wrapper>);
};

/**
 * 定义一个执业资格信息分页显示JsonVO对象，用于响应给客户端
 */
class QulificationPageJsonVO : public JsonVO<QulificationPageDTO::Wrapper>
{
	DTO_INIT(QulificationPageJsonVO, JsonVO<QulificationPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif
 