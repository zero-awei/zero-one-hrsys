/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/5/26 14:26:52

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
#include "AssignInfoDAO.h"
#include "AssignInfoMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define ASSIGNINFO_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id) { \
	sql << " AND assign=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->assign.getValue("")); \
} \
if (query->assign) { \
	sql << " AND etype=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->etype.getValue("")); \
} \
if (query->etype) { \
	sql << " AND organize=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->organize.getValue("")); \
}\
if (query->organize) { \
	sql << " AND depart=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->depart.getValue("")); \
}\
if (query->depart) { \
	sql << " AND job=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->job.getValue("")); \
}\
if (query->job) { \
	sql << " AND post=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->post.getValue("")); \
}\
if (query->post) { \
	sql << " AND startTime=?"; \
	SQLPARAMS_PUSH(params, "s",std::string , query->startTime.getValue("")); \
}\
if (query->startTime) { \
	sql << " AND endTime=?"; \
	SQLPARAMS_PUSH(params, "s",std::string , query->endTime.getValue("")); \
}

uint64_t AssignInfoDAO::count(const AssignInfoQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM assignInfo";
	ASSIGNINFO_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<AssignInfoDO> AssignInfoDAO::selectWithPage(const AssignInfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM assignInfo";
	ASSIGNINFO_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	AssignInfoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<AssignInfoDO, AssignInfoMapper>(sqlStr, mapper, params);
}

std::list<AssignInfoDO> AssignInfoDAO::selectById(const string& id)
{
	string sql = "SELECT * FROM assignInfo WHERE id LIKE CONCAT('%',?,'%')";
	AssignInfoMapper mapper;
	return sqlSession->executeQuery<AssignInfoDO, AssignInfoMapper>(sql, mapper, "%s", id);
}

uint64_t AssignInfoDAO::insert(const AssignInfoDO& iObj)
{
	string sql = "INSERT INTO assignInfo (id,assign,etype,organize,depart,job,post,startTime,endTime) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%cs%cs", iObj.getId(), iObj.getAssign(), iObj.getEtype(),iObj.getOrganize(),iObj.getDepart(),iObj.getJob(),iObj.getPost(),iObj.getStartTime(),iObj.getEndTime());
}

int AssignInfoDAO::update(const AssignInfoDO& uObj)
{
	string sql = "UPDATE assignInfo SET assign=?, etype=?, organize=?,depart=?,job=?,post=?,startTime=?,endTime=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%cs%cs%s", uObj.getAssign(), uObj.getEtype(), uObj.getOrganize(), uObj.getDepart(), uObj.getJob(), uObj.getPost(), uObj.getStartTime(), uObj.getEndTime(),uObj.getId());
}

int AssignInfoDAO::deleteById(string id)
{
	string sql = "DELETE FROM assignInfo WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}