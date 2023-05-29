#include "stdafx.h"
#include "JobLevelTypeListDAO.h"
#include "JobLevelMapper.h"

std::list<JobLevelTypeDO> JobLevelTypeListDAO::listAll()
{
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