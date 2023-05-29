#pragma once
#ifndef _UPDATELEGALERSETINGMESSAGE_VO_
#define _UPDATELEGALERSETINGMESSAGE_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/LegalEntitySet/UpdateLegalerSetingMessageDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class UpdateLegalerSetingMessageJsonVO : public JsonVO<UpdateLegalerSetingMessageDTO::Wrapper> {
	DTO_INIT(UpdateLegalerSetingMessageJsonVO, JsonVO<UpdateLegalerSetingMessageDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class UpdateLegalerSetingMessagePageJsonVO : public JsonVO<UpdateLegalerSetingMessagePageDTO::Wrapper> {
	DTO_INIT(UpdateLegalerSetingMessagePageJsonVO, JsonVO<UpdateLegalerSetingMessagePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UPDATELEGALERSETINGMESSAGE_VO_