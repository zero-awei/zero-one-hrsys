#pragma once

/**
* Query参数对象，接收前端传过来的查询参数
*/

#ifndef _JOBTITLE_QUERY_
#define _JOBTITLE_QUERY_

#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class JobTitleQuery :public PageQuery {
	DTO_INIT(JobTitleQuery, PageQuery);
	// 查询的第一个参数，职称编号
	DTO_FIELD(String, param);
	DTO_FIELD_INFO(param) {
		info->description = ZH_WORDS_GETTER("title.query.param");
	}
	DTO_FIELD(String, employee_id);
	DTO_FIELD_INFO(employee_id) {
		info->description = ZH_WORDS_GETTER("title.field.employee_id");
	}

	DTO_FIELD(String, employee_name);
	DTO_FIELD_INFO(employee_name) {
		info->description = ZH_WORDS_GETTER("title.field.employee_name");
	}
	DTO_FIELD(String, org_name);
	DTO_FIELD_INFO(org_name) {
		info->description = ZH_WORDS_GETTER("title.field.org_name");
	}
	DTO_FIELD(String, jobtitle_name);
	DTO_FIELD_INFO(jobtitle_name) {
		info->description = ZH_WORDS_GETTER("title.field.jobtitle_name");
	}
	DTO_FIELD(String, jobtitle_grades);
	DTO_FIELD_INFO(jobtitle_grades) {
		info->description = ZH_WORDS_GETTER("title.field.jobtitle_grades");
	}
	DTO_FIELD(String, b_highest_professional_title);
	DTO_FIELD_INFO(b_highest_professional_title) {
		info->description = ZH_WORDS_GETTER("title.field.b_highest_professional_title");
	}

	//DTO_FIELD(String, name);
	//// 查询的第二个参数，职称名称
	//DTO_FIELD_INFO(name) {
	//	info->description = ZH_WORDS_GETTER("title.field.name");
	//}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_JOBTITLE_QUERY_
