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
	// 员工编号
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.ygbh");
	}
	// 员工姓名
	DTO_FIELD(String, pcmjxszzkhjgjlname);
	DTO_FIELD_INFO(pcmjxszzkhjgjlname) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.pcmjxszzkhjgjlname");
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