#pragma once
#ifndef MEMBER_DTO
#define MEMBER_DTO
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class MemberDTO : public oatpp::DTO
{
	DTO_INIT(MemberDTO, DTO);
    // 员工编号
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("member.field.ygbh");
	}
    // 员工姓名
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("member.field.pimpersonname");
	}
    // 组织
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("member.field.ormorgname");
	}
    // 部门
	DTO_FIELD(String, ormorgsectorname);
	DTO_FIELD_INFO(ormorgsectorname) {
		info->description = ZH_WORDS_GETTER("member.field.ormorgsectorname");
	}
    // 职务
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("member.field.zw");
	}
	// 岗位
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("member.field.gw");
	}
	// 证件号码
	DTO_FIELD(String, zjhm);
	DTO_FIELD_INFO(zjhm) {
		info->description = ZH_WORDS_GETTER("member.field.zjhm");
	}
	// 出生日期
	DTO_FIELD(String, csrq);
	DTO_FIELD_INFO(csrq) {
		info->description = ZH_WORDS_GETTER("member.field.csrq");
	}
	// 年纪
	DTO_FIELD(String, nj);
	DTO_FIELD_INFO(nj) {
		info->description = ZH_WORDS_GETTER("member.field.nj");
	}
	// 联系电话
	DTO_FIELD(String, lxdh);
	DTO_FIELD_INFO(lxdh) {
		info->description = ZH_WORDS_GETTER("member.field.lxdh");
	}
};

/**
 * 示例分页传输对象
 */
class PageMember : public PageDTO<MemberDTO::Wrapper> 
{
	DTO_INIT(PageMember, PageDTO<MemberDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Member_DTO_