/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanchen
 @Date: 2023/05/31 21:06:11

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
#include "domain/do/projTag/ProjTagDO.h"
#include "dao/projTag/itemLabel/ItemLabelDAO.h"
#include "domain/dto/itemLabel/ItemLabelDTO.h"
#include "ItemLabelService.h"

ItemLabelPageDTO::Wrapper ItemLabeService::listItemLabel(const ItemLabelQuery::Wrapper& query)
{
	// 构建返回对象
	auto dto = ItemLabelPageDTO::createShared();
	dto->pageIndex = query->pageIndex;
	dto->pageSize = query->pageSize;

	ItemLabelDAO dao;
	list<ProjTagDO> res = dao.selectItemLabelList(query);
	for (ProjTagDO item : res)
	{
		auto to_dto = ItemLabelDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(to_dto, item, ormxbqId, Id, name, Creator, itemLabel, TagName, updataman, Updater, createTime, CreateTime, updataTime, UpdateTime, ormorgId, OrgId);
		dto->addData(to_dto);
	}
	return dto;
}