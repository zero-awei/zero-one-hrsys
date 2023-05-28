#pragma once
#ifndef _EMPLOYEE_NOT_IN_AECHIVE_QUERY_
#define _EMPLOYEE_NOT_IN_AECHIVE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询员工不在档案提醒
 */
class EmployeeNotInArchiveQuery : public PageQuery
{
	DTO_INIT(EmployeeNotInArchiveQuery, PageQuery);

	// 员工姓名
	DTO_FIELD(String, PimPersonName);
	DTO_FIELD_INFO(PimPersonName) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.PimPersonName");
	}
	// 员工id
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.pimpersonid");
	}

};
class ArchiveOutQuery : public PageQuery
{
	DTO_INIT(ArchiveOutQuery, PageQuery);

	// 归档地变更记录
	DTO_FIELD(String, ArchiveOut);
	DTO_FIELD_INFO(ArchiveOut) {
		info->description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.ArchiveOut");
	}

};


#include OATPP_CODEGEN_END(DTO)
#endif