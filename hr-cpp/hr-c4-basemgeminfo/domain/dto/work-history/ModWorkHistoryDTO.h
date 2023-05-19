#pragma once
#ifndef _MODWORKHISTORY_DTO_H_
#define _MODWORKHISTORY_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ModWorkHistoryDTO : public oatpp::DTO
{
	DTO_INIT(ModWorkHistoryDTO, DTO);

	// rzkssj: 任职开始时间
	DTO_FIELD(String, rzkssj);
	DTO_FIELD_INFO(rzkssj) {
		info->description = ZH_WORDS_GETTER("rzkssj");
	}
	// rzjssj: 任职结束时间
	DTO_FIELD(String, rzjssj);
	DTO_FIELD_INFO(rzjssj) {
		info->description = ZH_WORDS_GETTER("rzjssj");
	}
	//ormorgname: 工作单位
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("ormorgname");
	}
	// ormdutyname: 职务
	DTO_FIELD(String, ormdutyname);
	DTO_FIELD_INFO(ormdutyname) {
		info->description = ZH_WORDS_GETTER("ormdutyname");
	}
	//ormpostname: 岗位
	DTO_FIELD(String, ormpostname);
	DTO_FIELD_INFO(ormpostname) {
		info->description = ZH_WORDS_GETTER("ormpostname");
	}
	//cfplx: 兼职借调类型
	DTO_FIELD(String, cfplx);
	DTO_FIELD_INFO(cfplx) {
		info->description = ZH_WORDS_GETTER("cfplx");
	}
	//enable: 是否主要经历
	DTO_FIELD(String, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("workhistory.field.enable");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif
