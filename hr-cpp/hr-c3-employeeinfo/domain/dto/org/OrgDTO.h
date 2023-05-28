#pragma once
#ifndef _ORGDTO_
#define _ORGDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class OrgDTO : public oatpp::DTO
{
	DTO_INIT(OrgDTO, DTO);
	// 根组织ID
	DTO_FIELD(String, companyflag);
	DTO_FIELD_INFO(companyflag) {
		info->description = ZH_WORDS_GETTER("org.field.companyflag");
	}
    // 组织名字
	DTO_FIELD(String, orgname);
	DTO_FIELD_INFO(orgname) {
		info->description = ZH_WORDS_GETTER("org.field.orgname");
	}
    // 组织id
	DTO_FIELD(String, orgid);
	DTO_FIELD_INFO(orgid) {
		info->description = ZH_WORDS_GETTER("org.field.orgid");
	}
    // 父组织名字
	DTO_FIELD(String, porgname);
	DTO_FIELD_INFO(porgname) {
		info->description = ZH_WORDS_GETTER("org.field.porgname");
	}
    // 父组织id
	DTO_FIELD(String, porgid);
	DTO_FIELD_INFO(porgid) {
		info->description = ZH_WORDS_GETTER("org.field.porgid");
	}
};

/**
 * 示例分页传输对象
 */
class OrgPageDTO : public PageDTO<OrgDTO::Wrapper> 
{
	DTO_INIT(OrgPageDTO, PageDTO<OrgDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_org_DTO_