/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 17:01:55

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
#include "ProjTagService.h"
#include "domain/do/projTag/ProjTagDO.h"
#include "dao/projTag/ProjTagDAO.h"

uint64_t ProjTagService::saveData(const ProjTagDTO::Wrapper& dto)
{
	// 组装DO数据
	ProjTagDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, 
		Id, ormxmbqid,
		TagName, ormxmbqname,
		Creator, createman,
		CreateTime, createdate,
		Updater, updateman,
		UpdateTime, updatedate,
		OrgId, ormorgid
	);
	
	// 执行插入操作
	ProjTagDAO dao;
	return dao.insert(data);

}

OrgListPageDTO::Wrapper ProjTagService::listOrgList(const OrgListQuery::Wrapper& query)
{
	// 构建返回对象
	auto dto = OrgListPageDTO::createShared();
	dto->pageIndex = query->pageIndex;
	dto->pageSize = query->pageSize;

	// 获取查询总条数
	OrgListDAO dao;
}
