#include "stdafx.h"
#include "organizationDepartmentTreeStructure.h"

// 查询根组织
OrgJsonVO::Wrapper organizationDepartmentTreeStructure::execRootOrgQuery(const RootOrgQuery::Wrapper& rootQuery, const std::shared_ptr<CustomerAuthorizeObject> &authObject)
{
	// 定义一个MemberJsonVO对象
	auto jvo = OrgJsonVO::createShared();

	OrgService service;
	auto result = service.getRootOrg(rootQuery, authObject->getPayload().getId());
	jvo->success(result);
	return jvo;
}
//查询有效组织
OrgJsonVO::Wrapper organizationDepartmentTreeStructure::execValidOrgQuery(const ValidOrgQuery::Wrapper& validOrg)
{
	auto jvo = OrgJsonVO::createShared();

	OrgService service;
	auto result = service.getValidOrg(validOrg);
	jvo->success(result);
	return jvo;
}
//查询部门
OrgSectorVO::Wrapper organizationDepartmentTreeStructure::execSectorOrgQuery(const SectorQuery::Wrapper& sectorOrg)
{
	auto jvo = OrgSectorVO::createShared();

	OrgService service;
	auto result = service.getSector(sectorOrg);
	jvo->success(result);
	return jvo;
}