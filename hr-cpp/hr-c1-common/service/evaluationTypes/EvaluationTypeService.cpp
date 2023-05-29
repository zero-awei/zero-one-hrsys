/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/29 14:18:47

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
#include "EvaluationTypeService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/EvaluationType/EvaluationTypeDAO.h"

PullListDTO::Wrapper EvaluationTypeService::listAll()
{
	// 构建返回对象
	auto dto = PullListDTO::createShared();

	// TODO: 查询缓存
	// 访问Redis查询，返回评价类型哈希表
	auto hash = UseLibRedis::queryRedis("evaluation-type");

	// 如果缓存为空则调用数据库
	if (hash.empty())
	{
		// 调用DAO进行数据库查询
		EvaluationTypeDAO dao;
		auto res = dao.selectAll();

		for (auto item : res)
		{
			auto code = atoi(item.first.c_str());
			dto->pullList->push_back(ItemDTO::createShared(code, item.second));
		}

		if (res.size())
			// 放入缓存
			UseLibRedis::updateRedis("evaluation-type", res);
	}
	// 缓存不为空则查出转换成DTO
	else
	{
		for (auto item : hash)
		{
			int code = atoi(item.first.c_str());
			dto->pullList->push_back(ItemDTO::createShared(code, item.second));
		}
	}

	return dto;
}
