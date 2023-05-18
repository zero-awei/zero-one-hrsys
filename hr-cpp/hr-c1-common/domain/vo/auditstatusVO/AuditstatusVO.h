#pragma once
#ifndef _Auditstatus_VO_
#define _Auditstatus_VO_

#include "../../GlobalInclude.h"
#include "../../dto/AuditstatusDTO/AuditstatusDTO.h"
#include <domain/vo/BaseJsonVO.h>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class AuditstatusJsonVO : public JsonVO<AuditstatusDTO::Wrapper> {
	DTO_INIT(AuditstatusJsonVO, JsonVO<AuditstatusDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class AuditstatusPageJsonVO : public JsonVO<AuditstatusPageDTO::Wrapper> {
	DTO_INIT(AuditstatusPageJsonVO, JsonVO<AuditstatusPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_Auditstatus_VO_