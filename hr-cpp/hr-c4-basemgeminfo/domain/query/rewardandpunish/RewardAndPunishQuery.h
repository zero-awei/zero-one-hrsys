#pragma once

#ifndef _REWARDANDPUNISHQUERY_H_
#define _REWARDANDPUNISHQUERY_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class RewardAndPunishDetailQuery : public oatpp::DTO
{
	DTO_INIT(RewardAndPunishDetailQuery, DTO);

	// 奖惩记录主键标识
	DTO_FIELD(String, pimrewardpunishmentid);
	DTO_FIELD_INFO(pimrewardpunishmentid) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.pimrewardpunishmentid");
	}
};

class RewardAndPunishDownloadQuery : public oatpp::DTO
{
	DTO_INIT(RewardAndPunishDownloadQuery, DTO);

	// 奖惩记录 人员信息标识
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.pimpersonid");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif