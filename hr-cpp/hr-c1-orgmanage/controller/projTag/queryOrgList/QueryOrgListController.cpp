/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/24 17:58:45

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
#include "QueryOrgListController.h"
#include "service/projTag/ProjTagService.h"

OrgListVO::Wrapper QueryOrgListController::execQueryOrgList(const OrgListQuery::Wrapper& query)
{
	// 创建返回对象
	auto vo = OrgListVO::createShared();

	// 样例生成
	/*auto dto = OrgListPageDTO::createShared();
	for (int i = 0; i < 3; i++)
	{
		auto item = OrgListDTO::createShared();
		dto->rows->push_back(item);
	}*/

	// 调用service
	ProjTagService service;
	auto dto = service.listOrgList(query);
	vo->success(dto);
	return vo;
}
