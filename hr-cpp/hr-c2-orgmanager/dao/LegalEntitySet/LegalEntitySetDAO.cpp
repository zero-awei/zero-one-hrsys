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
if (query->ormsignorgname) { \
	sql << " AND `ORMSIGNORGNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ormsignorgname.getValue("")); \
} \
if (query->contractsignorgname) { \
	sql << " AND CONTRACTSIGNORGNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contractsignorgname.getValue("")); \
} \
if (query->isdefaultsignorg) { \
	sql << " AND ISDEFAULTSIGNORG=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->isdefaultsignorg.getValue("")); \
}

std::list<LegalEntitySetDO> LegalEntitySetDAO::legalerNamePullDownList() {
	string sql = "SELECT `ormsignorgname` FROM `t_ormsignorg`";
	LegalEntitySetPullDownListMapper mapper;
	return sqlSession->executeQuery<LegalEntitySetDO, LegalEntitySetPullDownListMapper>(sql, mapper);
}

uint64_t LegalEntitySetDAO::insert1(const LegalEntitySetDO& iObj) {
	string sql = "INSERT IGNORE INTO `t_ormsignorg` (`ORMSIGNORGNAME`) VALUES ( ?)";
	return sqlSession->executeInsert(sql, "%s", iObj.getORMSIGNORGNAME());
}

uint64_t LegalEntitySetDAO::insert2(const LegalEntitySetDO& iObj) {
	string sql = "INSERT INTO `t_contractsignorg` ( `CONTRACTSIGNORGNAME`, `ISDEFAULTSIGNORG`) VALUES ( ?,?)";
	return sqlSession->executeInsert(sql, "%s%i",iObj.getCONTRACTSIGNORGNAME(),iObj.getISDEFAULTSIGNORG());
}


int LegalEntitySetDAO::update1(const LegalEntitySetDO& uObj) {
	string sql = "UPDATE t_contractsignorg SET CONTRACTSIGNORGNAME=?, ISDEFAULTSIGNORG=? WHERE CONTRACTSIGNORGID=?";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getCONTRACTSIGNORGNAME(), uObj.getISDEFAULTSIGNORG(), uObj.getCONTRACTSIGNORGID());
}

int LegalEntitySetDAO::update2(const LegalEntitySetDO& uObj) {
	string sql = "UPDATE t_ormsignorg SET  ORMSIGNORGNAME=? WHERE ORMSIGNORGID=?";
	return sqlSession->executeUpdate(sql, "%s%s", uObj.getORMSIGNORGNAME(), uObj.getORMSIGNORGID());
}


/* -------------------------------------------法人主体设置查询功能--TripleGold ----------------------------------------------------------*/
uint64_t LegalEntitySetDAO::count(const LegalEntitySetQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*)"
		<< " FROM t_contractsignorg"
		<< " INNER JOIN t_ormsignorg ON t_contractsignorg.ORMSIGNORGID = t_ormsignorg.ORMSIGNORGID";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<LegalEntitySetDO> LegalEntitySetDAO::selectWithPage(const LegalEntitySetQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t_contractsignorg.ORMSIGNORGID, t_contractsignorg.CONTRACTSIGNORGNAME, t_ormsignorg.ORMSIGNORGNAME, t_contractsignorg.ISDEFAULTSIGNORG"
		<< " FROM t_contractsignorg "
		<< " INNER JOIN t_ormsignorg ON t_contractsignorg.ORMSIGNORGID = t_ormsignorg.ORMSIGNORGID";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LegalEntitySetMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<LegalEntitySetDO, LegalEntitySetMapper>(sqlStr, mapper, params);
}
