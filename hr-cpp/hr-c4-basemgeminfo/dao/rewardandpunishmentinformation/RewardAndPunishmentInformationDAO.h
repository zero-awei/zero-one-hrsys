#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: arui
 @Date: 2023/05/25 0:12:31

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
#ifndef _REWARDANDPUNISHMENTINFORMATIONDAO_H_
#define _REWARDANDPUNISHMENTINFORMATIONDAO_H_
#include "BaseDAO.h"
#include "domain/do/rewardandpunishmentinformation/RewardAndPunishmentInformationDO.h"
#include "domain/query/rewardandpunishmentinformation/RewardAndPunishmentInformationPageQuery.h"
class RewardAndPunishmentInformationDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const RewardAndPunishmentInformationPageQuery::Wrapper& query);
	// 分页查询数据
	list<RewardAndPunishmentInformationDO> selectWithPage(const RewardAndPunishmentInformationPageQuery::Wrapper& query);
	// 插入数据
	int insert(const RewardAndPunishmentInformationDO& iObj);
	// 通过ID删除数据
	int deleteById(std::string pimpersonid, std::string pimrewardpunishmentid);
};

#endif // !_REWARDANDPUNISHMENTINFORMATIONDAO_H_