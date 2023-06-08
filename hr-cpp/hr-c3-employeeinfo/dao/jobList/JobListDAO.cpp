/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/29 21:41:08

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
#include "JobListDAO.h"
#include "JobListMapper.h"

#define JOB_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->jobName) { \
	sql << " AND `GW`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->jobName.getValue("")); \
}
uint64_t JobListDAO::count(const JobListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `t_pimperson`";
	JOB_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<JobListDO> JobListDAO::selectJobList(const JobListQuery::Wrapper& query)
{
	stringstream sql;
	SqlParams par;
	sql << "SELECT `GW` FROM `t_pimperson` ";
	sql << " LIMIT " << ((query->pageIndex - 1)*query->pageSize)<<","<<query->pageSize;
	JobListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<JobListDO, JobListMapper>(sqlStr, mapper, par);
}