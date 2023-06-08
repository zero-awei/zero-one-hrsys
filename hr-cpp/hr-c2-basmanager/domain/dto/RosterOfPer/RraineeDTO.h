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
	// 组织
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.zz");
	}
	// 部门
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.bm");
	}
	//职务/
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.zw");
	}
	//岗位
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.gw");
	}
	//见习期限（月）
	DTO_FIELD(String, duration);
	DTO_FIELD_INFO(duration) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.duration");
	}
	//到本单位时间
	DTO_FIELD(String, ksrq);
	DTO_FIELD_INFO(ksrq) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.ksrq");
	}
	//见习到期时间
	DTO_FIELD(String, jsrq);
	DTO_FIELD_INFO(jsrq) {
		info->description = ZH_WORDS_GETTER("RosterOfPer.field.jsrq");
	}
};

class RraineePageDTO: public PageDTO<RraineeDTO::Wrapper> {
	DTO_INIT(RraineePageDTO, PageDTO<RraineeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RRAINEE_DTO_