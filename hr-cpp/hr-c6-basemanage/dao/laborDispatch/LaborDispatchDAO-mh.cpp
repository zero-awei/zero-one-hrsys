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
#include "SnowFlake.h"
#include <string>

//定义条件解析宏，减少重复代码
#define LABORDISPATCH_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `PIMLABOURCAMPANYNAME` LIKE CONCAT(?, '%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->lxfs) { \
	sql << " AND `LXFS` LIKE CONCAT(?, '%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->lxfs.getValue("")); \
} \
//if (query->unit) { \
//	sql << " AND `ORGNAME`=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->unit.getValue("")); \
//} \

//if (query->lxr) { \
//	sql << " AND `LXR`=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->lxr.getValue("")); \
//} \
//if (query->lxdz) { \
//	sql << " AND `LXDZ`=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->lxdz.getValue("")); \
//} \
//if (query->regcapital) { \
//	sql << " AND `REGCAPITAL`=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->regcapital.getValue("")); \
//} \
//if (query->legalperson) { \
//	sql << " AND `LEGALPEROSN`=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->legalperson.getValue("")); \
//} \
//if (query->updatedate) { \
//	sql << " AND `UPDATEDATE`=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->updatedate.getValue("")); \
//} 

uint64_t LaborDispatchDAO::count_ld(const LaborDispatchQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimlabourcampany";
	LABORDISPATCH_TERAM_PARSE(query,sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr,params);
}

std::list<LaborDispatchDO> LaborDispatchDAO::selectWrithPage_Query(const LaborDispatchQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT PIMLABOURCAMPANYID,PIMLABOURCAMPANYNAME,t_srforg.ORGNAME,LXDZ,LXR,LXFS,REGCAPITAL,LEGALPEROSN,t_pimlabourcampany.UPDATEDATE FROM `t_pimlabourcampany` ";
	sql << " JOIN t_srforg ON t_pimlabourcampany.ORMORGID = t_srforg.ORGID ";
	LABORDISPATCH_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LaborDispatchMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<LaborDispatchDO, LaborDispatchMapper>(sqlStr, mapper,params);
}

std::list<LaborDispatchDO> LaborDispatchDAO::selectWrithPage_Export(const LaborDispatchQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT 	PIMLABOURCAMPANYNAME,t_srforg.ORGNAME,LXFS,LXR,LXDZ,REGCAPITAL,LEGALPEROSN,t_pimlabourcampany.UPDATEDATE FROM `t_pimlabourcampany` ";
	sql << " JOIN t_srforg ON t_pimlabourcampany.ORMORGID = t_srforg.ORGID ";
	LABORDISPATCH_TERAM_PARSE(query, sql);
	sql << " LIMIT 50000";
	LaborDispatchMapper_export mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<LaborDispatchDO, LaborDispatchMapper_export>(sqlStr, mapper,params);
}

static std::string attain_curTime() {
	std::time_t currentTime = std::time(nullptr);
	std::tm* localTime = std::localtime(&currentTime);
	char timeString[100];
	std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);
	return timeString;
}

uint64_t LaborDispatchDAO::insert_ld(const LaborDispatchDO& iobj)
{
	string curTime = attain_curTime();
	uint64_t oid = SnowFlake(1, 6).nextId();
	string str_oid = to_string(oid);
	uint64_t pid = SnowFlake(1, 6).nextId();
	string str_pid = to_string(pid);
	string sql1 = "INSERT INTO `t_srforg` (`ORGID`,`ORGNAME`) VALUES (?,?);";
	string sql2 = " INSERT INTO `t_pimlabourcampany` (`PIMLABOURCAMPANYNAME`,`PIMLABOURCAMPANYID`,`ORMORGID`,`LXDZ`,`LXR`,`LXFS`,`LEGALPEROSN`,`REGCAPITAL`,`GSJJ`,`UPDATEDATE`) VALUES (?,?,?,?,?,?,?,?,?,?)";
	sqlSession->executeUpdate(sql1, "%s%s", str_oid,iobj.getUnit());
	return sqlSession->executeUpdate(sql2, "%s%s%s%s%s%s%s%s%s%s", iobj.getName(),str_pid,str_oid ,iobj.getLxdz(), iobj.getLxr(), iobj.getLxfs(), iobj.getRegcapital(), iobj.getLegalperson(), iobj.getGsjj(),curTime);
}

int LaborDispatchDAO::deleteById_ld(string id)
{
	string sql1 = "DELETE FROM t_pimcontract WHERE PIMLABOURCAMPANYID = ?";
	string sql2 = "DELETE FROM t_pimlabourcampany WHERE PIMLABOURCAMPANYID = ?";
	sqlSession->executeUpdate(sql1, "%s", id);
	return sqlSession->executeUpdate(sql2, "%s", id);
}

