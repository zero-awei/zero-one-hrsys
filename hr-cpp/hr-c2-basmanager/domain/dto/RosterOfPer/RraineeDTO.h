#pragma once
#ifndef _RRAINEE_DTO_
#define _RRAINEE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  基础管理 —— 人员花名册 —— 见习员工  ——Cpt
 */
class RraineeDTO : public oatpp::DTO {
	DTO_INIT(RraineeDTO, DTO);
	// 编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// 年龄
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("sample.field.age");
	}
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("sample.field.sex");
	}
};

/**
 * 示例分页传输对象
 */
class RraineePageDTO: public PageDTO<RraineeDTO::Wrapper> {
	DTO_INIT(RraineePageDTO, PageDTO<RraineeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RRAINEE_DTO_