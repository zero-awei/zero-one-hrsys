#pragma once

#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#ifndef _CONTEACTMANAGERQUERY_H_
#define _CONTEACTMANAGERQUERY_H_


#include OATPP_CODEGEN_BEGIN(DTO)


class contractManagerQuery :public PageQuery {

	DTO_INIT(contractManagerQuery, PageQuery);
	// 员工id 1
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.id");
	}
	DTO_FIELD(String, name);
	// 查询的第二个参数，员工姓名
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.name");
	}
	DTO_FIELD(String, Employee_status);
	// 查询的第三个参数，员工状态
	DTO_FIELD_INFO(Employee_status) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.Employee_status");
	}
	DTO_FIELD(String, contract_id);
	// 合同编号4
	DTO_FIELD_INFO(contract_id) {
		info->description = "he tong bian hao";
	}
	DTO_FIELD(String, contract_class);
	// 合同类别5
	DTO_FIELD_INFO(contract_class) {
		info->description = "he tong lei bie";
	}
	DTO_FIELD(String, contract_state);
	// 合同状态6
	DTO_FIELD_INFO(contract_state) {
		info->description = "he tong zhuang tai";
	}
	DTO_FIELD(String, start_date);
	// 开始日期7
	DTO_FIELD_INFO(start_date) {
		info->description = "kai shi r qi";
	}
	DTO_FIELD(String, stop_date);
	// 结束日期8
	DTO_FIELD_INFO(stop_date) {
		info->description = "jie shu r qi";
	}
	DTO_FIELD(String, contract_type);
	// 合同类型9
	DTO_FIELD_INFO(contract_type) {
		info->description = "he tong lei xin";
	}
};

#include OATPP_CODEGEN_END(DTO)



#endif // !_CONTEACTMANAGERQUERY_H_

