/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/31 0:37:46

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
#include "PageQueryBzService.h"
#include "domain/do/orgbz/PageQueryBzDO.h"
#include "domain/dto/orgbz/PageQueryBzDTO.h"
#include "dao/orgbz/PageQueryBzDAO.h"
#include "domain/vo/orgbz/PageQueryBzVO.h"
#include "Macros.h"

PageQueryBzDTO::Wrapper PageQueryBzService::listPageQueryBz(const PageQueryBzQuery::Wrapper& query)
{
	// 构建返回对象
	auto dto = PageQueryBzDTO::createShared();
	dto->pageIndex = query->pageIndex;
	dto->pageSize = query->pageSize;

	// 获取查询总条数
	PageQueryBzDAO dao;
	uint64_t cnt = dao.count(query);
	if (cnt <= 0)
	{
		return dto;
	}

	// 分页查询数据
	dto->total = cnt;
	dto->calcPages();
	list<PageQueryBzDO> res = dao.selectPageQueryBz(query);
	// 将DO转成DTO
	for (PageQueryBzDO item : res)
	{
		auto to_dto = QueryBzDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(to_dto, item, orgId, OrgId, orgName, OrgName, orgSectorId, OrgSectorId, orgSectorName, OrgSectorName, orgCode, OrgCode, orgType, OrgType, sectorType, SectorType, updateBy, UpdateBy, updateTime, UpdateTime, createBy, CreateBy, createTime, CreateTime, bzrs, Bzrs, sjbzrs, Sjbzrs);
		dto->addData(to_dto);
	}
	return dto;
}
