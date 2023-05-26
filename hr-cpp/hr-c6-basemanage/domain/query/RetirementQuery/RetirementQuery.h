#pragma once

#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#ifndef _RETIREMENTQUERY_H_
#define _RETIREMENTQUERY_H_


#include OATPP_CODEGEN_BEGIN(DTO)


class RetirementQuery :public PageQuery {
	DTO_INIT(RetirementQuery, PageQuery);
	// 查询的第一个参数，员工编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.number");
	}
	DTO_FIELD(String, name);
	// 查询的第二个参数，员工姓名
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.name");
	}
	DTO_FIELD(String, idCard);
	// 查询的第三个参数，证件号码
	DTO_FIELD_INFO(IDcard) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.idcard");
	}
	DTO_FIELD(String, organization);
	// 查询的第四个参数，组织
	DTO_FIELD_INFO(organization) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.organization");
	}
	DTO_FIELD(String, department);
	// 查询的第五个参数，部门
	DTO_FIELD_INFO(department) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.department");
	}
};

#include OATPP_CODEGEN_END(DTO)



#endif // !_RETIREMENTQUERY_H_
