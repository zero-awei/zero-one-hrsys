#pragma once
/*
（人员花名册-借调人员-分页查询员工列表（导出本页在前端完成））--luoluo
*/
#ifndef _LOANEDPERPAGE_QUERY_
#define _LOANEDPERPAGE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class LoanedPerPageQuery : public PageQuery
{
	DTO_INIT(LoanedPerPageQuery, PageQuery);
	// 借调人员标识
	DTO_FIELD(String, PIMDISTIRBUTIONID);
	DTO_FIELD_INFO(PIMDISTIRBUTIONID) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.PIMDISTIRBUTIONID");
	}
	// 编号和姓名 模糊查询
	DTO_FIELD(String, idAndName);
	DTO_FIELD_INFO(idAndName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.idAndName");
	}
	// 姓名
	DTO_FIELD(String, pimPersonName);
	DTO_FIELD_INFO(pimPersonName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.pimPersonName");
	}
	// 编号
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.ygbh");
	}
	// 组织
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.zz1");
	}
	// 部门
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.bm1");
	}
	// 职务
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.zw1");
	}
	// 岗位
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.gw1");
	}
	// 分配
	DTO_FIELD(String, fp);
	DTO_FIELD_INFO(fp) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.fp");
	}
	// 类型
	DTO_FIELD(String, lx);
	DTO_FIELD_INFO(lx) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.lx");
	}
	// 分配状态
	DTO_FIELD(String, fpzt);
	DTO_FIELD_INFO(fpzt) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.fpzt");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LOANEDPERPAGE_QUERY_