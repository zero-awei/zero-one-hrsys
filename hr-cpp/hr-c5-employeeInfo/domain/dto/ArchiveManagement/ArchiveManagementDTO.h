#pragma once
#ifndef _ArchiveManagementDTO_
#define _ArchiveManagementDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SampleDTO : public oatpp::DTO {
	DTO_INIT(SampleDTO, DTO);
	//档案编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("management.archive.id");
	}
	//管理单位
 	DTO_FIELD(String, gldw);
	DTO_FIELD_INFO(gldw) {
		info->description = ZH_WORDS_GETTER("management.archive.gldw");
	}
	//档案保管地
	DTO_FIELD(String, bgd);
	DTO_FIELD_INFO(bgd) {
		info->description = ZH_WORDS_GETTER("management.archive.bgd");
	}
	//档案室
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("management.center.name");
	}
	//档案状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("management.center.state");
	}
	//员工编号
	DTO_FIELD(String, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("management.user.number");
	}
	//员工姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("management.user.name");
	}
	//操作列
	DTO_FIELD(String, operat);
	DTO_FIELD_INFO(operat) {
		info->description = ZH_WORDS_GETTER("management.user.operator");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ArchiveManagementDTO_