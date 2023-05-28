/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/24 17:41:08

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
#include "ContractStatusController.h"
#include "uselib/pullListRedis/UseLibRedis.h"

/**
 * 实现合同状态下拉列表
 * 负责人：远翔
 */
PullListVO::Wrapper ConstractStatusController::execQueryContractStatus()
{
	auto dto = PullListDTO::createShared();
	UseLibRedis redisExm;
	std::string tableName = "constract-status-pull-list";
	std::unordered_map<std::string, std::string> constractStatusList;
	std::unordered_map<std::string, std::string> redisResult = redisExm.queryRedis(tableName);
	if (redisResult.empty()) {
		// 列表数据
		dto->pullList->push_back(ItemDTO::createShared(20, ZH_WORDS_GETTER("contractStatus.duration")));
		dto->pullList->push_back(ItemDTO::createShared(30, ZH_WORDS_GETTER("contractStatus.outOfDate")));
		dto->pullList->push_back(ItemDTO::createShared(40, ZH_WORDS_GETTER("contractStatus.haveSigned")));
		dto->pullList->push_back(ItemDTO::createShared(50, ZH_WORDS_GETTER("contractStatus.terminated")));

		// 加入缓存
		for (auto subptr = dto->pullList->begin(); subptr != dto->pullList->end(); subptr++) {
			constractStatusList.insert(std::make_pair(std::to_string(*subptr->get()->key), *subptr->get()->val));
		}
		// 加入缓存
		redisExm.updateRedis(tableName, constractStatusList);
	}
	else { // 缓存有数据
		constractStatusList = redisExm.queryRedis(tableName);
		for (auto sub : constractStatusList) {
			dto->pullList->push_back(ItemDTO::createShared(std::stoi(sub.first), sub.second));
		}
	}
	auto vo = PullListVO::createShared();
	vo->success(dto);
	return vo;
}
