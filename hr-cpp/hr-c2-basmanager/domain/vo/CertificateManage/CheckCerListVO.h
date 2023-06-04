#pragma once
#ifndef _CHECK_CER_VO_
#define _CHECK_CER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/CertificateManage/CheckCerListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CheckCerListJsonVO : public JsonVO<CheckCerListDTO::Wrapper> {
	DTO_INIT(CheckCerListJsonVO, JsonVO<CheckCerListDTO::Wrapper>);
};

class CheckCerListPageJsonVO : public JsonVO<CheckCerListPageDTO::Wrapper> {
	DTO_INIT(CheckCerListPageJsonVO, JsonVO<CheckCerListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CHECK_CER_VO_