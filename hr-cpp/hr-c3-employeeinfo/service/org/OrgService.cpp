/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
 @Date: 2022/10/25 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "OrgService.h"

OrgPageDTO::Wrapper OrgService::getRootOrg(const RootOrgQuery::Wrapper &query, const string &userID)
{
	auto pages = OrgPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	OrgDAO dao;
	list<OrgDO> result = dao.selectRootOrg(query, userID);
	if (!result.empty())
	{
		for (auto org : result)
		{
			auto dto = OrgDTO::createShared();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, org,
									companyflag, CompanyFlag,
									orgname, OrgName,
									orgid, OrgID, 
									porgname, Porgname,
									porgid, PorgID);
			pages->addData(dto);
		}
	}
	return pages;
}

OrgPageDTO::Wrapper OrgService::getValidOrg(const ValidOrgQuery::Wrapper &query)
{
	auto pages = OrgPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	OrgDAO dao;
	list<OrgDO> result = dao.selectValidOrg(query);
	if (!result.empty())
	{
		for (auto org : result)
		{
			auto dto = OrgDTO::createShared();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, org,
									companyflag, CompanyFlag,
									orgname, OrgName,
									orgid, OrgID, 
									porgname, Porgname,
									porgid, PorgID);
			pages->addData(dto);
		}
	}
	return pages;
}

OrgSectorPageDTO::Wrapper OrgService::getSector(const SectorQuery::Wrapper &query)
{
	auto pages = OrgSectorPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	OrgSectorDAO dao;
	list<OrgSectorDO> result = dao.selectOrgSector(query);
	if (!result.empty())
	{
		for (auto org : result)
		{
			auto dto = OrgSectorDTO::createShared();
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, org,
									orgsectorname, OrgSectorName,
									orgsectorid, OrgSectorID,
									orgid, OrgID,
									orgname, OrgName);
			pages->addData(dto);
		}
	}
	return pages;
}