/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/05/23 19:26:11

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
#include "Macros.h"
#include "CostTypeListService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/costTypeList/CostTypeListDAO.h"

PullListDTO::Wrapper CostTypeListService::listAll()
{
	// 构建返回对象
	auto res = PullListDTO::createShared();

	// TODO: 查询缓存
	// 从缓存中获取费用类别列表
	auto hash = UseLibRedis::queryRedis("cost-type");

	auto dto = PullListDTO::createShared();
	// 如果为空则调用dao查询数据库
	if (hash.empty())
	{
		// TODO: 调用dao查询数据库
		CostTypeListDAO dao;
		auto res = dao.listAll();

		// 组装成DTO返回
		for (auto item : res)
		{
			string code = item.getCode();
			dto->pullList->push_back(ItemDTO::createShared(atoi(code.c_str()), item.getCostType()));
		}

		if (res.size())
			// TODO: 将获取的数据更新到Redis缓存
			UseLibRedis::updateRedis("cost-type", dao.getMapList());
	}
	// 否则组装缓存数据到DTO
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
