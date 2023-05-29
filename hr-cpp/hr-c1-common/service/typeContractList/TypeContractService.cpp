/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/26 21:48:28

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
#include "TypeContractService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/typeContract/TypeContractDAO.h"

PullListDTO::Wrapper TypeContractService::listAll()
{
	// 构建返回对象
	auto dto = PullListDTO::createShared();

	// TODO: 从缓存中查询下拉列表
	auto hash = UseLibRedis::queryRedis("type-contract");

	// 如果缓存中没有数据
	if (hash.empty())
	{
		// TODO: 调用DAO查询数据库
		TypeContractDAO dao;
		auto res = dao.selectAll();

		// 将DO转换为DTO，组装哈希表
		for (auto item : res)
		{
			string code = item.getTypeCode();
			dto->pullList->push_back(ItemDTO::createShared(atoi(code.c_str()), item.getTypeContract()));
			hash[code] = item.getTypeContract();
		}

		if (res.size())
			// TODO: 将获取的数据更新到Redis缓存
			UseLibRedis::updateRedis("type-contract", hash);
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
