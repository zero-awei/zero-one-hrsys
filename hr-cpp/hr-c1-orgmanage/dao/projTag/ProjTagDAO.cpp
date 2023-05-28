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

/**
 * 组织列表查询条件匹配宏
 */
#define ORGLIST_TERAM_PARSE(__QUERY__, __SQL__) \
SqlParams params; \
__SQL__ << " WHERE 1=1"; \
if (__QUERY__->orgCode) { \
	__SQL__ << " AND `ORGCODE` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, __QUERY__->orgCode.getValue("")); \
} \
if (__QUERY__->orgName) { \
	__SQL__ << " AND `ORGNAME` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, __QUERY__->orgName.getValue("")); \
} \
if (__QUERY__->shortname) { \
	__SQL__ << " AND `SHORTNAME` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, __QUERY__->shortname.getValue("")); \
} \
if (__QUERY__->order == "ASC") { \
	__SQL__ << " ORDER BY `PX` ASC"; \
} \
if (__QUERY__->order == "DESC") { \
		__SQL__ << " ORDER BY `PX` DESC"; \
}

uint64_t ProjTagDAO::insert(const ProjTagDO& iObj)
{
	// ORMXMBQID CREATEMAN ORMXMBQNAME UPDATEMAN CREATEDATE UPDATEDATE ORMORGID
	string sql = "INSERT INTO `t_ormxmbq` \
				(`ORMXMBQID`, `CREATEMAN`, `ORMXMBQNAME`, `UPDATEMAN`, `CREATEDATE`, `UPDATEDATE`, `ORMORGID`)\
				 VALUES (?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s", \
				iObj.getId(), iObj.getCreator(), iObj.getTagName(), \
				iObj.getUpdater(), iObj.getCreateTime(), iObj.getUpdateTime(), iObj.getOrgId());
}

uint64_t ProjTagDAO::count(const OrgListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(`ORGID`) FROM `t_srforg`";
	ORGLIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<OrgListDO> ProjTagDAO::selectOrgList(const OrgListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT `CREATEDATE`, `CREATEMAN`, `LEVELCODE`, `ORGCODE`, `ORGID`, `ORGNAME`,"
		<< " `PORGID`, `SHORTNAME`, `UPDATEDATE`, `UPDATEMAN`, `ZZLX`, `SSOU`, `GSSS`, `ZZDZBM`,"
		<< " `ZZDZY`, `ZZDZE`, `ZZCJSJ`, `ZZDZS`, `BTQY`, `ERPORGID`, `STARTSTOPSIGN`, `LEGALENTITY`,"
		<< " `CORRESPONDINGORG`, `COMPANYFLAG` FROM `t_srforg`";
	ORGLIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	OrgListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<OrgListDO, OrgListMapper>(sqlStr, mapper, params);
}

bool ProjTagDAO::updateProjTag(const ProjTagDO& data)
{
	string sql = "UPDATE `t_ormxmbq` SET `UPDATEDATE` = ?, `UPDATEMAN` = ?, \
		`ORMXMBQNAME` = ?, `ORMORGID` = ? WHERE `ORMXMBQID` = ?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s", data.getUpdateTime(), data.getUpdater(), \
		data.getTagName(), data.getOrgId(), data.getId());
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
	string sql = "SELECT `ORMXMBQID`, `ORMXMBQNAME`, `CREATEMAN`, `UPDATEMAN`, `CREATEDATE`, `UPDATEDATE`, `ORMORGID` FROM `t_ormxmbq` ORDER BY ? LIMIT ?";
	ProjTagMapper mapper;
	return sqlSession->executeQuery<ProjTagDO, ProjTagMapper>(sql, mapper);
}
