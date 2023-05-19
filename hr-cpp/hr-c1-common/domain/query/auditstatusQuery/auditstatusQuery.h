#pragma once
#ifndef _Auditstatus_QUERY_
#define _Auditstatus_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 查询对象
 * 处理人：fengchu
 */
class AuditstatusQuery : public PageQuery
{
public:
	DTO_INIT(AuditstatusQuery, PageQuery);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Auditstatus_QUERY_