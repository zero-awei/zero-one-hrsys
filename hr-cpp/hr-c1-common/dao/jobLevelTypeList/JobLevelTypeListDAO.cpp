#include "stdafx.h"
#include "JobLevelTypeListDAO.h"
#include "JobLevelMapper.h"

std::list<JobLevelTypeDO> JobLevelTypeListDAO::listAll()
{
	/*list<JobLevelTypeDO> res;
	for (auto item : jobLevel)
	{
		JobLevelTypeDO tmp(item.first, item.second);
		res.push_back(tmp);
	}*/

	string sql = "SELECT `CODEITEMVALUE`, `CODEITEMNAME` FROM `t_srfcodeitem` WHERE `CODELISTID`=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "cs", std::string, "A794C86F-0433-4620-90B7-32CEB0764120");
	JobLevelMapper mapper;
	return sqlSession->executeQuery<JobLevelTypeDO, JobLevelMapper>(sql, mapper, params);
}