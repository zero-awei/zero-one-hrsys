#include "stdafx.h"
#include "JobLevelTypeListDAO.h"
#include "JobLevelMapper.h"

std::list<JobLevelTypeDO> JobLevelTypeListDAO::listAll()
{
	/*string str = "SELECT `LEVELTYPE` FROM `t_pimarmycadres` GROUP BY `LEVELTYPE`";
	ArmyLevelMapper mapper;
	return sqlSession->executeQuery<ArmyLevelTypeDO, ArmyLevelMapper>(str, mapper);*/

	list<JobLevelTypeDO> res;
	for (auto item : jobLevel)
	{
		JobLevelTypeDO tmp(item.first, item.second);
		res.push_back(tmp);
	}
	return res;
}

unordered_map<string, string> JobLevelTypeListDAO::getMapList()
{
	return jobLevel;
}