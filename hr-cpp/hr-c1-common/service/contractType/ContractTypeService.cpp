/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/06/02 1:12:53

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
#include "ContractTypeService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/contractType/ContractTypeDAO.h"
#include "domain/dto/contractType/ContractTypeDTO.h"

ContractTypeListDTO::Wrapper ContractTypeService::listAll()
{
	// 构建返回对象
	auto dto = ContractTypeListDTO::createShared();

	// TODO: 查询缓存
	// 从缓存中获取合同类别
	auto hash = UseLibRedis::queryRedis("contract-type");

	// 如果为空则调用dao查询数据库
	if (hash.empty())
	{
		// TODO: 调用dao查询数据库
		ContractTypeDAO dao;
		auto res = dao.selectAll();

		// 组装成DTO返回
		for (auto item : res)
		{
			string code = item.getSbm();
			dto->pullList->push_back(ContractTypeDTO::createShared(code, item.getPimcontracttypename()));
			hash[code] = item.getPimcontracttypename();
		}

		if (res.size())
			// TODO: 将获取的数据更新到Redis缓存
			UseLibRedis::updateRedis("contract-type", hash);
	}
	// 否则组装缓存数据到DTO
	else
	{
		for (auto item : hash)
		{
			string code = item.first;
			dto->pullList->push_back(ContractTypeDTO::createShared(code, item.second));
		}
	}
	return dto;
}
