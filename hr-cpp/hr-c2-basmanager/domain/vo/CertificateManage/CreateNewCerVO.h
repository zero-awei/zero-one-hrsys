#pragma once

#ifndef _CREATE_NEW_CER_VO_
#define _CREATE_NEW_CER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/CertificateManage/CreateNewCerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class CreateNewCerJsonVO : public JsonVO<CreateNewCerDTO::Wrapper> {
	DTO_INIT(CreateNewCerJsonVO, JsonVO<CreateNewCerDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class CreateNewCerPageJsonVO : public JsonVO<CreateNewCerPageDTO::Wrapper> {
	DTO_INIT(CreateNewCerPageJsonVO, JsonVO<CreateNewCerPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 