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
		data.set_CREATEDATE(resultSet->getString(1));
		data.set_UPDATEDATE(resultSet->getString(2));
		data.set_PIMREWARDPUNISHMENTNAME(resultSet->getString(3));
		data.set_UPDATEMAN(resultSet->getString(4));
		data.set_CREATEMAN(resultSet->getString(5));
		data.set_FJ(resultSet->getString(6));
		data.set_LX(resultSet->getString(7));
		data.set_CSRQ(resultSet->getString(8));
		data.set_PIMREWARDPUNISHMENTID(resultSet->getString(9));
		data.set_PIMPERSONID(resultSet->getString(10));
		data.set_JCJB(resultSet->getString(11));
		data.set_JCLX(resultSet->getString(12));
		data.set_JLSJ(resultSet->getString(13));
		data.set_CFSJ(resultSet->getString(14));
		data.set_JCJE(resultSet->getString(15));
		data.set_JCSJ(resultSet->getString(16));
		data.set_BZ(resultSet->getString(17));
		data.set_CFLX(resultSet->getString(18));
		data.set_JLSS(resultSet->getString(19));
		data.set_JLGLBH(resultSet->getString(20));
		data.set_JLSPZT(resultSet->getString(21));
		data.set_JLCZZ(resultSet->getString(22));
		data.set_YXQJSRQ(resultSet->getString(23));
		data.set_DEPARTMENT(resultSet->getString(24));
		data.set_REASON(resultSet->getString(25));
	}
};

#endif