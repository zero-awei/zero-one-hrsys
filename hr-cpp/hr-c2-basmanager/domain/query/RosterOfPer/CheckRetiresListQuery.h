#pragma once
#ifndef _CHECK_RETIRES_QUERY_
#define _CHECK_RETIRES_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
人员花名册-离退休人员-分页查询员工列表--pine
 */
class CheckRetiresListQuery : public PageQuery
{
	DTO_INIT(CheckRetiresListQuery, PageQuery);
	// 员工编号
	DTO_FIELD(UInt64, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.ygbh");
	}
	// 员工姓名
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.pimpersonname");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CheckRetiresList_QUERY_