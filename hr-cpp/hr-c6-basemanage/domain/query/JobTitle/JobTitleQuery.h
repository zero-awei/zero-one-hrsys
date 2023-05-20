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
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("title.field.id");
	}
	DTO_FIELD(String, name);
	// 查询的第二个参数，职称名称
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("title.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_JOBTITLE_QUERY_
 