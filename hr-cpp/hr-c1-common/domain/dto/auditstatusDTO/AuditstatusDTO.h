#pragma once
#ifndef _Auditstatus_DTO_
#define _Auditstatus_DTO_
#include "../../GlobalInclude.h"
#include <domain/query/auditstatusQuery/auditstatusQuery.h>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class AuditstatusDTO : public oatpp::DTO
{
	DTO_INIT(AuditstatusDTO, DTO);
};

/**
 * 示例分页传输对象
 */
class AuditstatusPageDTO : public PageDTO<AuditstatusDTO::Wrapper>
{
	DTO_INIT(AuditstatusPageDTO, PageDTO<AuditstatusDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_AuditstatusDTO_DTO_