#pragma once
#ifndef  _CONTRACTMANAGERVO_H_
#define  _CONTRACTMANAGERVO_H_


#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "domain/dto/retirement/contractManagerDto.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class contractManagerJsonVO : public JsonVO<contractmanagerDTO::Wrapper> {
	DTO_INIT(contractManagerJsonVO, JsonVO<contractmanagerDTO::Wrapper>);
};

// 分页查询返回的JsonVO
class contractManagerQueryPageJsonVO :public JsonVO<contractmanagerPageDTO::Wrapper> {
	DTO_INIT(contractManagerQueryPageJsonVO, JsonVO<contractmanagerPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)


#endif // ! _CONTRACTMANAGERVO_H_
