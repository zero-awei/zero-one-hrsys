#include "stdafx.h"
#include "LegalEntitySetDAO.h"
#include "LegalEntitySetMapper.h"
#include <sstream>
/*
组织管理 ——数据设置 —— 法人主体设置  -- cpt

法人主体名称下拉列表 `LegalEntitySetPullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `LegalEntitySet`

新增法人设置（支持批量新增）** `LegalEntitySet`
*/ 

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->contractsignorgname) { \
	sql << " AND (`CONTRACTSIGNORGNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contractsignorgname.getValue("")); \
	sql << " OR ORMORGID=?)"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contractsignorgname.getValue("")); \
} \
if (query->ormorgid) { \
	sql << " AND ORMORGID=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ormorgid.getValue("")); \
} \
if (query->isdefaultsignorg) { \
	sql << " AND ISDEFAULTSIGNORG=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->isdefaultsignorg.getValue("")); \
}

std::list<LegalEntitySetDO> LegalEntitySetDAO::legalerNamePullDownList() {
	string sql = "SELECT `ormsignorgid` FROM `t_contractsignorg`";
	LegalEntitySetPullDownListMapper mapper;
	return sqlSession->executeQuery<LegalEntitySetDO, LegalEntitySetPullDownListMapper>(sql, mapper);
}

uint64_t LegalEntitySetDAO::insert(const LegalEntitySetDO& iObj) {
	string sql = "INSERT IGNORE INTO t_contractsignorg (CREATEDATE, CREATEMAN, UPDATEDATE, UPDATEMAN, CONTRACTSIGNORGNAME, CONTRACTSIGNORGID, ORMORGID, ORMSIGNORGID, ISDEFAULTSIGNORG) VALUES (?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s",iObj.getCREATEDATE(), iObj.getCREATEMAN(), iObj.getUPDATEDATE(), iObj.getUPDATEMAN(),  iObj.getCONTRACTSIGNORGNAME(), iObj.getCONTRACTSIGNORGID(), iObj.getORMORGID(), iObj.getORMSIGNORGID(), iObj.getISDEFAULTSIGNORG());
}

int LegalEntitySetDAO::update(const LegalEntitySetDO& uObj) {
	string sql = "UPDATE t_contractsignorg SET CONTRACTSIGNORGNAME=?, ORMORGID=?, ORMSIGNORGID=?, ISDEFAULTSIGNORG=? WHERE CONTRACTSIGNORGID=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s", uObj.getCONTRACTSIGNORGNAME(),
		uObj.getORMORGID(),  uObj.getSIGNORGID(), atoi(uObj.getISDEFAULTSIGNORG().c_str()), uObj.getCONTRACTSIGNORGID());
}
/* -------------------------------------------法人主体设置查询功能--TripleGold ----------------------------------------------------------*/
uint64_t LegalEntitySetDAO::count(const LegalEntitySetQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_contractsignorg";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<LegalEntitySetDO> LegalEntitySetDAO::selectWithPage(const LegalEntitySetQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT CONTRACTSIGNORGID, CONTRACTSIGNORGNAME, ORMSIGNORGID, ORMORGID, ISDEFAULTSIGNORG FROM t_contractsignorg";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LegalEntitySetMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<LegalEntitySetDO, LegalEntitySetMapper>(sqlStr, mapper, params);
}
