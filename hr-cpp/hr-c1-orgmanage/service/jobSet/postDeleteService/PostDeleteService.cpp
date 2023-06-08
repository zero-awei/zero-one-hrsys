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
#include "PostDeleteService.h"
#include "../../../dao/jobSet/postDeleteDAO/PostDeleteDAO.h"

bool PostDeleteService::removeData(string id)
{
	PostDeleteDAO postDeleteDAO;
	return postDeleteDAO.deleteById(id) == 1;
}

bool PostDeleteService::removeBatchData(const PostDeleteBatchDTO::Wrapper& postDeleteBatchDTO)
{
	PostDeleteDAO postDeleteDAO;
	auto sqlSession = postDeleteDAO.getSqlSession();
	//开启事务
	sqlSession->beginTransaction();
	bool isSuccess = true;
	for (const auto& item : *postDeleteBatchDTO->ormPostIds) {
		if (postDeleteDAO.deleteById(item->c_str()) != 1)
		{
			//回滚
			sqlSession->rollbackTransaction();
			isSuccess = false;
			return isSuccess;
		}
	}
	sqlSession->commitTransaction();
	return isSuccess;
}