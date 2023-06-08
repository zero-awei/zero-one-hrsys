#pragma once

#ifndef _LEGALENTITYMAIVO_H_
#define _LEGALENTITYMAIVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/LegalEntityMai/LegalEntityMaiDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* 法人主体维护VO对象定义--（组织管理-数据设置-法人主体维护）--TripleGold */

/* 定义一个用户信息显示JsonVO对象，用于响应给客户端 */
class LegalEntityMaiJsonVO : public JsonVO<LegalEntityMaiDTO::Wrapper>
{
	DTO_INIT(LegalEntityMaiJsonVO, JsonVO<LegalEntityMaiDTO::Wrapper>);
};

/* 定义一个用户信息分页显示JsonVO对象，用于响应给客户端 */
class LegalEntityMaiPageJsonVO : public JsonVO<LegalEntityMaiPageDTO::Wrapper>
{
	DTO_INIT(LegalEntityMaiPageJsonVO, JsonVO<LegalEntityMaiPageDTO::Wrapper>)
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAIVO_H_