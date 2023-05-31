/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/31 1:09:13

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
#include "PageQueryBzDAO.h"
#include "PageQueryBzMapper.h"
#include <sstream>

#define ORGLIST_TERAM_PARSE(__QUERY__, __SQL__) \
SqlParams params; \
__SQL__ << " WHERE 1=1"; \
if (__QUERY__->orgid) { \
	__SQL__ << " AND `ORGID` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, __QUERY__->orgid.getValue("")); \
} \
if (__QUERY__->orgname) { \
	__SQL__ << " AND `ORGNAME` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, __QUERY__->orgname.getValue("")); \
} \
if (__QUERY__->orgsectorname) { \
	__SQL__ << " AND `ORGSECTORNAME` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, __QUERY__->orgsectorname.getValue("")); \
} 

uint64_t PageQueryBzDAO::count(const PageQueryBzQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(ORGID) FROM t_srforgsector";
	ORGLIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<PageQueryBzDO> PageQueryBzDAO::selectPageQueryBz(const PageQueryBzQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT `ORGID`,`ORGNAME`, `ORGSECTORNAME` FROM 't_srforgsector'";
	ORGLIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	PageQueryBzMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PageQueryBzDO, PageQueryBzMapper>(sqlStr, mapper, params);
}

