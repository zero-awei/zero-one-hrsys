#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/24 15:24:41

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
#ifndef _POSTQUERY_DAO_
#define _POSTQUERY_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/postSet/PostDetailDO.h"
#include "../../../domain/query/postSet/PostDetailQuery.h"

/**
 * 岗位设置 - 查询指定岗位详情DAO
 * 负责人 : rice
 */
class PostQueryDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const PostDetailQuery::Wrapper& query);
	// 分页查询数据
	list<PostDetailDO> selectWithPage(const PostDetailQuery::Wrapper& query);
};
#endif // !_POSTQUERY_DAO_
