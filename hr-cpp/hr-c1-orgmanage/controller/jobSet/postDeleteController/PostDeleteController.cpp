/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 18:55:41

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
#include "PostDeleteController.h"
#include "../../../service/jobSet/postDeleteService/PostDeleteService.h"

StringJsonVO::Wrapper PostDeleteController::execDeleteByOrmPostId(const PostDeleteDTO::Wrapper& postDeleteDTO, const PayloadDTO& payload)
{

	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!postDeleteDTO->ormPostId)
	{
		jvo->init(String(""), RS_PARAMS_INVALID);
		return jvo;
	}
	PostDeleteService postDeleteService;

	// 执行数据删除
	if (postDeleteService.removeData(postDeleteDTO->ormPostId)) {
		jvo->success(postDeleteDTO->ormPostId);
	}
	else
	{
		jvo->fail(postDeleteDTO->ormPostId);
	}
	return jvo;
}

PostDeleteBatchJsonVO::Wrapper PostDeleteController::exeDeleteBatchByOrmPostId(const PostDeleteBatchDTO::Wrapper& postDeleteBatchDTO, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = PostDeleteBatchJsonVO::createShared();
	// 参数校验
	if (!postDeleteBatchDTO->ormPostIds)
	{
		jvo->init(postDeleteBatchDTO, RS_PARAMS_INVALID);
		return jvo;
	}
	PostDeleteService postDeleteService;

	// 执行数据删除
	if (postDeleteService.removeBatchData(postDeleteBatchDTO)) {
		jvo->success(postDeleteBatchDTO);
	}
	else
	{
		jvo->fail(postDeleteBatchDTO);
	}
	return jvo;
}
