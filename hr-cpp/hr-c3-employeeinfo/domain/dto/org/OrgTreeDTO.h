#pragma once
#ifndef _ORGTREE_DTO
#define _ORGTREE_DTO
#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class OrgTreeDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(OrgTreeDTO, DTO);
    
	API_DTO_FIELD_DEFAULT(String, orgtype, ZH_WORDS_GETTER("org.field.orgtype"));
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
	DTO_FIELD(List<OrgTreeDTO::Wrapper>, children) = {};
	DTO_FIELD_INFO(children) {
		info->description = ZH_WORDS_GETTER("org.field.children");
	}
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<OrgTreeDTO>(child), Wrapper::Class::getType()));
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ORGTREE_DTO_