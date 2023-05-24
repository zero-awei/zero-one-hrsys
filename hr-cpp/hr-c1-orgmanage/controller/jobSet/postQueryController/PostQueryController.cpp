/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 18:44:41

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
#include "PostQueryController.h"
#include "../../../service/jobSet/postQueryService/PostQueryService.h"

PostDetailPageJsonVO::Wrapper PostQueryController::execQueryByQuerySort(const PostDetailQuery::Wrapper& postDetailQuery)
{
	PostQueryService postQueryService;
	// 查询数据
	auto result = postQueryService.listAll(postDetailQuery);
	// 响应结果
	auto jvo = PostDetailPageJsonVO::createShared();
	if (result->rows->size() <= 0) {
		jvo->fail(result);
	}
	else {
		jvo->success(result);
	}
	return jvo;
}
