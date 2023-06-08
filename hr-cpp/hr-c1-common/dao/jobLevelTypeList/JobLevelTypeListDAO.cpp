/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/05/26 22:37:53

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

	// 构建SQL查询语句
	string sql = "SELECT `CODEITEMVALUE`, `CODEITEMNAME` FROM `t_srfcodeitem` WHERE `CODELISTID`=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "cs", std::string, "A794C86F-0433-4620-90B7-32CEB0764120");
	JobLevelMapper mapper;
	return sqlSession->executeQuery<JobLevelTypeDO, JobLevelMapper>(sql, mapper, params);
}