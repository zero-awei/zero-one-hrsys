#pragma once
#ifndef _Auditstatus_QUERY_
#define _Auditstatus_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class AuditstatusQuery : public PageQuery
{
	DTO_INIT(AuditstatusQuery, PageQuery);
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Auditstatus_QUERY_