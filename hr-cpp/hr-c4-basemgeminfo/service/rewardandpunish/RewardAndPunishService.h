#pragma once

#ifndef _REWARDANDPUNISHSERVICE_H_
#define _REWARDANDPUNISHSERVICE_H_
#include "../../domain/vo/rewardandpunish/RewardAndPunishVO.h"
#include "../../domain/query/rewardandpunish/RewardAndPunishQuery.h"
#include "../../domain/dto/rewardandpunish/RewardAndPunishDTO.h"

class RewardAndPunishService
{
public:
	
	RewardAndPunishDTO::Wrapper listDetail(const RewardAndPunishDetailQuery::Wrapper& query);
	
	bool updateData(const RewardAndPunishDTO::Wrapper& dto);
	
	string download(const RewardAndPunishDownloadQuery::Wrapper& query);
};

#endif
