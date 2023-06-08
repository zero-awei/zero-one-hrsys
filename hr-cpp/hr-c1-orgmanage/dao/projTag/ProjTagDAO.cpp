/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 17:06:40

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
#include "ProjTagDAO.h"
#include "OrgListMapper.h"
#include "ProjTagMapper.h"
#include "ProjTagListMapper.h"

/**
 * 组织列表查询条件匹配宏
 */
#define ORGLIST_TERAM_PARSE(__QUERY__, __SQL__) \
SqlParams params; \
__SQL__ << " WHERE 1=1"; \
if (__QUERY__->orgCode) { \
	__SQL__ << " AND t1.`ORGCODE` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, __QUERY__->orgCode.getValue("")); \
} \
if (__QUERY__->orgName) { \
	__SQL__ << " AND t1.`ORGNAME` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, __QUERY__->orgName.getValue("")); \
} \
if (__QUERY__->shortname) { \
	__SQL__ << " AND t1.`SHORTNAME` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, __QUERY__->shortname.getValue("")); \
} \
if (__QUERY__->order == "ASC") { \
	__SQL__ << " ORDER BY t1.`PX` ASC"; \
} \
if (__QUERY__->order == "DESC") { \
		__SQL__ << " ORDER BY t1.`PX` DESC"; \
}

 /**
  * 项目标签列表查询条件匹配宏
  */
#define PROJTAGLIST_TERAM_PARSE(__QUERY__, __SQL__) \
SqlParams params; \
__SQL__ << " WHERE 1=1"; \
if (__QUERY__->tagName) { \
	__SQL__ << " AND `ORMXMBQNAME` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, __QUERY__->tagName.getValue("")); \
} \
if (__QUERY__->order == "ASC") { \
	__SQL__ << " ORDER BY `XH` ASC"; \
} \
if (__QUERY__->order == "DESC") { \
		__SQL__ << " ORDER BY `XH` DESC"; \
}

/**
 * 项目标签更新条件匹配宏
 */
#define UPDATE_TERAM_PARSE(__DO__, __SQL__) \
SqlParams params; \
if (__DO__.getTagName() != "") { \
	__SQL__ << " `ORMXMBQNAME`=?,"; \
	SQLPARAMS_PUSH(params, "s", std::string, __DO__.getTagName()); \
} \
if (__DO__.getOrgId() != "") { \
	__SQL__ << " `ORMORGID`=?,"; \
	SQLPARAMS_PUSH(params, "s", std::string, __DO__.getOrgId()); \
}

bool ProjTagDAO::insert(const ProjTagDO& iObj)
{
	// ORMXMBQID CREATEMAN ORMXMBQNAME UPDATEMAN CREATEDATE UPDATEDATE ORMORGID
	string sql = "INSERT INTO `t_ormxmbq` \
				(`ORMXMBQID`, `CREATEMAN`, `ORMXMBQNAME`, `UPDATEMAN`, `CREATEDATE`, `UPDATEDATE`, `ORMORGID`)\
				 VALUES (?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", \
				iObj.getId(), iObj.getCreator(), iObj.getTagName(), \
				iObj.getUpdater(), iObj.getCreateTime(), iObj.getUpdateTime(), iObj.getOrgId());
	
}

uint64_t ProjTagDAO::count(const OrgListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(t1.`ORGID`) FROM `t_srforg` AS t1";
	ORGLIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<OrgListDO> ProjTagDAO::selectOrgList(const OrgListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t1.`CREATEDATE`, t1.`CREATEMAN`, t1.`LEVELCODE`, t1.`ORGCODE`, t1.`ORGID`, "
		<< "t1.`ORGNAME`, t1.`PORGID`, t2.`ORGNAME`, t1.`SHORTNAME`, t1.`UPDATEDATE`, t1.`UPDATEMAN`, "
		<< "t1.`ZZLX`, t1.`SSOU`, t1.`GSSS`, t1.`ZZDZBM`, t1.`ZZDZY`, t1.`ZZDZE`, t1.`ZZCJSJ`, t1.`ZZDZS`, "
		<< "t1.`BTQY`, t1.`ERPORGID`, t1.`STARTSTOPSIGN`, t1.`LEGALENTITY`, t1.`CORRESPONDINGORG`, t1.`COMPANYFLAG` "
		<< "FROM `t_srforg` AS t1 LEFT JOIN `t_srforg` AS t2 ON t1.`PORGID`=t2.`ORGID`";
	ORGLIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	OrgListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<OrgListDO, OrgListMapper>(sqlStr, mapper, params);
}

bool ProjTagDAO::updateProjTag(const ProjTagDO& data)
{
	stringstream ss;
	ss << "UPDATE `t_ormxmbq` SET ";
	UPDATE_TERAM_PARSE(data, ss);
	ss << " `UPDATEDATE`=?, `UPDATEMAN`=? WHERE `ORMXMBQID` = ? ";
	SQLPARAMS_PUSH(params, "s", std::string, data.getUpdateTime());
	SQLPARAMS_PUSH(params, "s", std::string, data.getUpdater());
	SQLPARAMS_PUSH(params, "s", std::string, data.getId());

	string sql = ss.str();
	return sqlSession->executeUpdate(sql, params);
}

std::list<std::string> ProjTagDAO::insertMultiTag(const std::list<ProjTagDO>& data)
{
	// 构建返回对象
	std::list<std::string> res;

	// 开启事务处理
	sqlSession->beginTransaction();

	// 调用新增岗位设置
	for (auto item : data)
	{
		// 调用单个新增
		string sql = "INSERT INTO `t_ormxmbq` \
		(`ORMXMBQID`, `CREATEMAN`, `ORMXMBQNAME`, `UPDATEMAN`, \
		`CREATEDATE`, `UPDATEDATE`, `ORMORGID`) \
		VALUES (?, ?, ?, ?, ?, ?, ?)";

		int row = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s",
			item.getId(), item.getCreator(), item.getTagName(), item.getUpdater(),
			item.getCreateTime(), item.getUpdateTime(), item.getOrgId());

		// 新增成功将id加入返回列表中
		if (row == 1)
		{
			res.push_back(item.getId());
		}
		// 否则则回滚并返回失败
		else
		{
			sqlSession->rollbackTransaction();
			res.clear();
			return res;
		}
	}

	// 全部新增成功则提交并返回成功
	sqlSession->commitTransaction();
	return res;
}

std::list<ProjTagDO> ProjTagDAO::exportProjTag(const ExportProjTagQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT `ORMXMBQID`, `ORMXMBQNAME`, `CREATEMAN`, `UPDATEMAN`, `CREATEDATE`, `UPDATEDATE`, `ORMORGID` FROM `t_ormxmbq`";
	
	SqlParams params;
	if (query->order == "DESC")
		sql << " ORDER BY `XH` DESC";
	if (query->order == "ASC")
		sql << " ORDER BY `XH` ASC";
	if (query->line) {
		sql << " LIMIT ?";
		SQLPARAMS_PUSH(params, "ui", uint32_t, query->line.getValue(1));
	}

	string str = sql.str();
	ProjTagMapper mapper;
	return sqlSession->executeQuery<ProjTagDO, ProjTagMapper>(str, mapper, params);
}

uint64_t ProjTagDAO::count(const PageProjTagQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(`ORMXMBQID`) FROM `t_ormxmbq`";
	PROJTAGLIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ProjTagDO> ProjTagDAO::selectProjTag(const PageProjTagQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT `ORMXMBQID`, `CREATEMAN`, `ORMXMBQNAME`, `UPDATEMAN`, `CREATEDATE`, `UPDATEDATE`,"
		<< "`ORMORGID` FROM `t_ormxmbq`";
	PROJTAGLIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProjTagListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProjTagDO, ProjTagListMapper>(sqlStr, mapper, params);
}

std::vector<std::string> ProjTagDAO::getHead()
{
	// 构建返回对象
	vector<std::string> head;

	string sql = "SELECT COLUMN_NAME FROM information_schema.COLUMNS WHERE TABLE_NAME = 't_ormxmbq' ORDER BY ORDINAL_POSITION";
	Statement* st = sqlSession->getConnection()->createStatement();
	ResultSet* res;

	res = st->executeQuery(sql);
	while (res->next())
	{
		head.push_back(res->getString(1));
	}

	st->close();
	res->close();
	return head;
}
