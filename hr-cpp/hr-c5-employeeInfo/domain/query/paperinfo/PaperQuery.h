#pragma once
#ifndef _PAPERINFO_QUERY_
#define _PAPERINFO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 论文信息分页查询对象
 */
class PaperQuery : public PageQuery
{
	DTO_INIT(PaperQuery, PageQuery);
	// 员工编号
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.pimpersonid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif