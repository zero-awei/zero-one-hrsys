#pragma once
#ifndef _PROBATIONARY_EMPLOYEE_QUERY_
#define _PROBATIONARY_EMPLOYEE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 人员花名册 - 试用人员Query实现 - 楚孟献
 */
class ProbationaryEmployeeQuery : public PageQuery
{
	DTO_INIT(ProbationaryEmployeeQuery, PageQuery);
	// 编号或名称
	DTO_FIELD(String, id_or_name);
	DTO_FIELD_INFO(id_or_name) {
		info->description = ZH_WORDS_GETTER("sample.field.id_or_name");
	}
	// 员工姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// 员工编号id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 证件号码
	DTO_FIELD(String, zjhm);
	DTO_FIELD_INFO(zjhm) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.zjhm");
	}
	// 组织名称
	DTO_FIELD(String, organization);
	DTO_FIELD_INFO(organization) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.organization");
	}
	// 部门
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.bm");
	}
	// 员工状态
	DTO_FIELD(String, ygzt);
	DTO_FIELD_INFO(ygzt) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.ygzt");
	}
	// 在岗状态
	DTO_FIELD(String, zgzt);
	DTO_FIELD_INFO(zgzt) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.zgzt");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
