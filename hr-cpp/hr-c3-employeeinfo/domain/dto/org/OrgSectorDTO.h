#pragma once
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class OrgSectorDTO : public oatpp::DTO
{
	DTO_INIT(OrgSectorDTO, DTO);
    // 部门名字
	DTO_FIELD(String, orgsectorname);
	DTO_FIELD_INFO(orgsectorname) {
		info->description = ZH_WORDS_GETTER("orgsector.field.orgname");
	}
    // 部门id
	DTO_FIELD(String, orgsectorid);
	DTO_FIELD_INFO(orgsectorid) {
		info->description = ZH_WORDS_GETTER("orgsector.field.orgsectorid");
	}
    // 组织名字
	DTO_FIELD(String, orgname);
	DTO_FIELD_INFO(orgname) {
		info->description = ZH_WORDS_GETTER("orgsector.field.orgname");
	}
    // 组织id
	DTO_FIELD(String, orgid);
	DTO_FIELD_INFO(orgid) {
		info->description = ZH_WORDS_GETTER("orgsector.field.orgid");
	}
    // // 父组织名字
	// DTO_FIELD(Int32, porgname);
	// DTO_FIELD_INFO(porgname) {
	// 	info->description = ZH_WORDS_GETTER("org.field.porgname");
	// }
    // // 父组织id
	// DTO_FIELD(String, porgid);
	// DTO_FIELD_INFO(porgid) {
	// 	info->description = ZH_WORDS_GETTER("org.field.porgid");
	// }
};

/**
 * 示例分页传输对象
 */
class PageOrgSector : public PageDTO<OrgSectorDTO::Wrapper> 
{
	DTO_INIT(PageOrgSector, PageDTO<OrgSectorDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_org_DTO_