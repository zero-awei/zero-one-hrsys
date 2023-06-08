#pragma once

#ifndef _REWARDANDPUNISHMAPPER_H_
#define _REWARDANDPUNISHMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/rewardandpunish/RewardAndPunishDO.h"

class RewardAndPunishMapper : public Mapper<RewardAndPunishDO>
{
public:
	RewardAndPunishDO mapper(ResultSet* resultSet) const override
	{
		RewardAndPunishDO data;

		//奖惩标识
		data.set_PIMREWARDPUNISHMENTID(resultSet->getString(1));
		//奖惩分类
		data.set_LX(resultSet->getString(2));
		//奖惩名称
		data.set_PIMREWARDPUNISHMENTNAME(resultSet->getString(3));
		//奖惩级别
		data.set_JCJB(resultSet->getString(4));
		//奖惩金额
		data.set_JCJE(resultSet->getString(5));
		//奖惩时间
		data.set_JLSJ(resultSet->getString(6));
		//授予单位
		data.set_DEPARTMENT(resultSet->getString(7));
		//奖惩事件
		data.set_JCSJ(resultSet->getString(8));
		//备注
		data.set_BZ(resultSet->getString(9));
		//附件
		data.set_FJ(resultSet->getString(10));

		return data;
	}
};

#endif