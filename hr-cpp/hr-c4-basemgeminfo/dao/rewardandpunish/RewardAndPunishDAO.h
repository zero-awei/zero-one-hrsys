#pragma once

#ifndef _REWARDANDPUNISHDAO_H_
#define _REWARDANDPUNISHDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/rewardandpunish/RewardAndPunishDO.h"
#include "../../domain/query/rewardandpunish/RewardAndPunishQuery.h"

class RewardAndPunishDAO : public BaseDAO
{
public:
	// 查询详情数据
	list<RewardAndPunishDO> selectDetail(const RewardAndPunishDetailQuery::Wrapper& query);
	// 修改数据
	int update(const RewardAndPunishDO& uObj);
	// 分页查询数据
	list<RewardAndPunishDO> selectWithPage(const RewardAndPunishDownloadQuery::Wrapper& query);

};

#endif