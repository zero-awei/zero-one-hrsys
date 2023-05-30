#pragma once
/*
（人员花名册-借调人员-分页查询员工列表（导出本页在前端完成））--luoluo
*/
#ifndef _LOANEDPERPAGE_DTO_
#define _LOANEDPERPAGE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class LoanedPerDTO : public oatpp::DTO
{
	DTO_INIT(LoanedPerDTO, DTO);
	// 编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.id");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.name");
	}
	// 原组织
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.zz");
	}
	// 原部门
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.bm");
	}
	// 原职务
	DTO_FIELD(String, yzw);
	DTO_FIELD_INFO(yzw) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.yzw");
	}
	// 原岗位
	DTO_FIELD(String, ygw);
	DTO_FIELD_INFO(ygw) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.ygw");
	}
	// 新组织
	DTO_FIELD(String, ormName);
	DTO_FIELD_INFO(ormName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.ormName");
	}
	// 新部门
	DTO_FIELD(String, ormOrgSectorName);
	DTO_FIELD_INFO(ormOrgSectorName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.ormOrgSectorName");
	}
	// 新职务
	DTO_FIELD(String, ormDutyName);
	DTO_FIELD_INFO(ormDutyName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.ormDutyName");
	}
	// 新岗位
	DTO_FIELD(String, ormPostName);
	DTO_FIELD_INFO(ormPostName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.ormPostName");
	}
	// 借调状态（异动借调明细标识）
	DTO_FIELD(String, pcmydjdmxId);
	DTO_FIELD_INFO(pcmydjdmxId) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.pcmydjdmxId");
	}
	// 借调开始时间
	DTO_FIELD(String, jdksrq);
	DTO_FIELD_INFO(jdksrq) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.jdksrq");
	}
	// 借调结束时间
	DTO_FIELD(String, jdjsrq);
	DTO_FIELD_INFO(jdjsrq) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.jdjsrq");
	}
};

class LoanedPerPageDTO : public PageDTO<LoanedPerDTO::Wrapper>
{
	DTO_INIT(LoanedPerPageDTO, PageDTO<LoanedPerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LOANEDPERPAGE_DTO_