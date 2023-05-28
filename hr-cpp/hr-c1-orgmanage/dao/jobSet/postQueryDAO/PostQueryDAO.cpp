/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/24 15:26:52

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
#include "PostQueryDAO.h"
#include "PostQueryMapper.h"
#include <sstream>

uint64_t PostQueryDAO::count(const PostDetailQuery::Wrapper& query)
{
	//组织sql语句
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_ormpost";
	string queryType = query->queryPostName;
	//模糊查询
	sql << " WHERE ORMPOSTNAME LIKE \'%" + queryType + "%\'";
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr);
}

std::list<PostDetailDO> PostQueryDAO::selectWithPage(const PostDetailQuery::Wrapper& query)
{
	//组织sql语句
	stringstream sql;
	sql << " SELECT t1.*, IFNULL(t2.ORGNAME, NULL) FROM t_ormpost t1 ";
	sql << " LEFT JOIN t_srforg t2 ON t1.ORMORGID = t2.ORGID ";
	//SAMPLE_TERAM_PARSE(query, sql);
	string queryType = query->queryPostName;
	sql << " WHERE ORMPOSTNAME LIKE \'%" + queryType + "%\'";
	//(xh,ASC)
	if (query->sortTypeAndMethod)
	{
		string orderBy = query->sortTypeAndMethod->substr(0, query->sortTypeAndMethod->find(","));
		string direction = query->sortTypeAndMethod->substr(query->sortTypeAndMethod->find(",") + 1);
		sql << " ORDER BY " + orderBy + " " + direction;
	}
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	PostQueryMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PostDetailDO, PostQueryMapper>(sqlStr, mapper);
}
