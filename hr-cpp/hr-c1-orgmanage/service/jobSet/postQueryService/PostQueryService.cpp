/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/24 15:50:11

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
#include "PostQueryService.h"
#include "../../../dao/jobSet/postQueryDAO/PostQueryDAO.h"

PostDetailPageDTO::Wrapper PostQueryService::listAll(const PostDetailQuery::Wrapper& query)
{
	// 构建返回对象
	auto postDetailPageDTO = PostDetailPageDTO::createShared();
	postDetailPageDTO->pageIndex = query->pageIndex;
	postDetailPageDTO->pageSize = query->pageSize;

	// 查询数据总条数
	PostQueryDAO postQueryDAO;
	uint64_t count = postQueryDAO.count(query);
	if (count <= 0)
	{
		return postDetailPageDTO;
	}

	// 分页查询数据
	postDetailPageDTO->total = count;
	postDetailPageDTO->calcPages();
	list<PostDetailDO> result = postQueryDAO.selectWithPage(query);
	// 将DO转换成DTO
	for (PostDetailDO postDetailDO : result)
	{
		auto postDetailDTO = PostDetailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(postDetailDTO, postDetailDO, xh, Xh, gwfl, Gwfl, isConfidential, IsConfidential, ormPostName, OrmPostName
			, nx, Nx, bxjlnx, Bxjlnx, isKeyPostion, IsKeyPostion, postNature, PostNature
			, startStopSign, StartStopSign, ormPostId, OrmPostId, createMan, CreateMan, updateDate, UpdateDate
			, updateMan, UpdateMan, createDate, CreateDate, orgId, OrgId, gwType, GwType
			, isTemp, IsTemp, ormOrgId, OrmOrgId, ormOrgName, OrmOrgName)
		postDetailPageDTO->addData(postDetailDTO);

	}
	return postDetailPageDTO;
}


