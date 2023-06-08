#pragma once
#ifndef _TEMPORARYSTAFF_QUERY_
#define _TEMPORARYSTAFF_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 挂职人员分页查询对象--(人员花名册-挂职人员-分页查询员工列表)--weixiaoman
 */
class TempStaffQuery : public PageQuery
{
	DTO_INIT(TempStaffQuery, PageQuery);
	// 姓名
	DTO_FIELD(String, idandname);
	DTO_FIELD_INFO(idandname) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.idandname");
	}
	//// 编号
	//DTO_FIELD(String, id);
	//DTO_FIELD_INFO(id) {
	//	info->description = ZH_WORDS_GETTER("TempStaff.field.id");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TEMPORARYSTAFF_QUERY_