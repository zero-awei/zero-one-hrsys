/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/25 21:27:54

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
#include <sstream>
#include "LaborDispatchDAO-mh.h"
#include "LaborDispatchMapper-mh.h"


#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->enable) { \
	sql << " AND `ENABLE`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->enable.getValue("")); \
} \
if (query->name) { \
	sql << " AND `PIMLABOURCAMPANYNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if(query->id) { \
	sql << " AND `PIMLABOURCAMPANYID`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->id.getValue("")); \
} \
if(query->createdate) { \
	sql << " AND `CREATEDATE`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->createdate.getValue("")); \
} \
if(query->createman) { \
	sql << " AND `CREATEMAN`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->createman.getValue("")); \
} \
if(query->updateman) { \
	sql << " AND `UPDATEMAN`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->updateman.getValue("")); \
} \
if(query->updatedate) { \
	sql << " AND `UPDATEDATE`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->updatedate.getValue("")); \
} \
if(query->jyfw) { \
	sql << " AND `JYFW`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->jyfw.getValue("")); \
} \
if(query->lxdz) { \
	sql << " AND `LXDZ`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->lxdz.getValue("")); \
} \
if(query->lxfs) { \
	sql << " AND `LXFS`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->lxfs.getValue("")); \
} \
if(query->lxr) { \
	sql << " AND `LXR`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->lxr.getValue("")); \
} \
if(query->gsjj) { \
	sql << " AND `GSJJ`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->gsjj.getValue("")); \
} \
if(query->pimpersonid) { \
	sql << " AND `PIMPERSONID`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->pimpersonid.getValue("")); \
} \
if(query->ormorgid) { \
	sql << " AND `ORMORGID`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->ormorgid.getValue("")); \
} \
if(query->regcapital) { \
	sql << " AND `LEGALPEROSN`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->regcapital.getValue("")); \
} \
if(query->legalperson) { \
	sql << " AND `REGCAPITAL`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->legalperson.getValue("")); \
} \

uint64_t LaborDispatchDAO::count_ld(const LaborDispatchQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimlabourcampany";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<LaborDispatchDO> LaborDispatchDAO::selectWrithPage_Query(const LaborDispatchQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM `t_pimlabourcampany`";
	SAMPLE_TERAM_PARSE(query, sql);

	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LaborDispatchMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<LaborDispatchDO, LaborDispatchMapper>(sqlStr, mapper, params);
}

std::list<LaborDispatchDO> LaborDispatchDAO::selectWrithPage_Export(const LaborDispatchQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM `t_pimlabourcampany`";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT 50000";
	LaborDispatchMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<LaborDispatchDO, LaborDispatchMapper>(sqlStr, mapper, params);
}

uint64_t LaborDispatchDAO::insert_ld(const LaborDispatchDO& iobj)
{
	string sql = "INSERT INTO `t_pimlabourcampany` (`ENABLE`,`PIMLABOURCAMPANYNAME`,`PIMLABOURCAMPANYID`,`CREATEDATE`,`CREATEMAN`,`UPDATEMAN`,`UPDATEDATE`,`JYFW`,`LXDZ`,`LXR`,`LXFS`,`GSJJ`,`PIMPERSONID`,`ORMORGID`,`LEGALPEROSN`,`REGCAPITAL`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";

	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", iobj.get_Enable(), iobj.getName(), iobj.getId(), iobj.getCreatedate(), iobj.getCreateman(), iobj.getUpdateman(), iobj.getUpdatedate(), iobj.getJyfw(), iobj.getLxdz(), iobj.getLxr(), iobj.getLxfs(), iobj.getGsjj(), iobj.getPimpersonid(), iobj.getOrmorgid(), iobj.getRegcapital(), iobj.getLegalperson());
}

int LaborDispatchDAO::deleteById_ld(string id)
{
	string sql = "DELETE FROM `t_pimlabourcampany` WHERE `PIMLABOURCAMPANYID`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}

