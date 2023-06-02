#include "stdafx.h"
#include "organizationDepartmentTreeStructure.h"
#include "tree/TreeUtil.h"
#include "service/org/TreeOrgMapper.h"

// ²éÑ¯¸ù×é
OrgTreeVO::Wrapper organizationDepartmentTreeStructure::execOrgTreeQuery(const std::shared_ptr<CustomerAuthorizeObject> &authObject) {
	OrgService service;
	auto res = service.getOrgTree(authObject->getPayload().getId());
	// auto res = service.getOrgTree("jisen");
	auto vo = OrgTreeVO::createShared();
	for (const auto &one : res)
	{
		vo->data->push_back(OrgTreeDTO::Wrapper(one, OrgTreeDTO::Wrapper::Class::getType()));
	}
	return vo;
}