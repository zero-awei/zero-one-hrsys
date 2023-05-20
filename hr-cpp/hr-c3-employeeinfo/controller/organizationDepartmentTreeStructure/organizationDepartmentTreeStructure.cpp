#include "stdafx.h"
#include "organizationDepartmentTreeStructure.h"

//查询所有部门结构树
MemberJsonVO::Wrapper organizationDepartmentTreeStructure::execRootOrgQuery(const RootOrgQuery::Wrapper& rootQuery)
{
	// 定义一个MemberJsonVO对象
	auto vo = MemberJsonVO::createShared();
	return vo;
}
//查询有效组织
MemberJsonVO::Wrapper organizationDepartmentTreeStructure::execValidOrgQuery(const ValidOrgQuery::Wrapper& validOrg)
{
	// 定义一个MemberJsonVO对象
	auto vo = MemberJsonVO::createShared();
	return vo;
}
//查询部门
OrgSectorVO::Wrapper organizationDepartmentTreeStructure::execSectorOrgQuery(const SectorQuery::Wrapper& sectorOrg)
{
	// 定义一个OrgSectorVO对象
	auto vo = OrgSectorVO::createShared();
	return vo;
}




