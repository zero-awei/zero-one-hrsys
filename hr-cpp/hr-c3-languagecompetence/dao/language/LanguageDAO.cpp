/**
 * 语言模块数据库操作实现
 * 负责人： 君
 */
#include "stdafx.h"
#include "LanguageDAO.h"
#include "LanguageMapper.h"
#include <sstream>
#include <ctime>

 //定义条件解析宏，减少重复代码
#define LANGUAGE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->languageAbilityID) { \
	sql << " AND `PIMLANGUAGEABILITYID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->languageAbilityID.getValue("")); \
} \
if (query->permission) { \
	sql << " AND ENABLE=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->permission.getValue(0)); \
} \
if (query->languageType)  { \
	sql << " AND WYYZ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->languageType.getValue("")); \
} \
if (query->createMan) { \
	sql << " AND CREATEMAN=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->createMan.getValue("")); \
} \
if (query->updateMan) { \
	sql << " AND UPDATEMAN=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->updateMan.getValue("")); \
} \
if (query->languageLevel) { \
	sql << " AND WYDJ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->languageLevel.getValue("")); \
} \
if (query->personID) { \
	sql << " AND PIMPERSONID=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->personID.getValue("")); \
} \
if (query->jlss) { \
	sql << " AND JLSS=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->jlss.getValue("")); \
} \
if (query->jlglbh) { \
	sql << " AND JLGLBH=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->jlglbh.getValue("")); \
} \
if (query->jlspzt) { \
	sql << " AND JLSPZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->jlspzt.getValue("")); \
} \
if (query->jlczz) { \
	sql << " AND JLCZZ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->jlczz.getValue("")); \
} \

uint64_t LanguageDAO::count(const LanguageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimlanguageability";
	LANGUAGE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

uint64_t LanguageDAO::countPage(const LanguagePageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimlanguageability";
	LANGUAGE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<LanguageDO> LanguageDAO::selectWithPage(const LanguagePageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT `PIMLANGUAGEABILITYID`, `ENABLE`, `WYDJHQSJ`, `FJ`, `WYYZ`, `CREATEMAN`, `UPDATEMAN`, `WYDJ`, ";
	sql << "`PIMPERSONID`, `JLSS`, `JLGLBH`, `JLSPZT`, `JLCZZ`";
	sql << "FROM t_pimlanguageability";
	LANGUAGE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LanguageMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<LanguageDO, LanguageMapper>(sqlStr, mapper, params);
}

std::list<LanguageDO> LanguageDAO::selectOneById(const string& id)
{
	string sql = "SELECT `PIMLANGUAGEABILITYID`, `ENABLE`, `WYDJHQSJ`, `FJ`, `WYYZ`, `CREATEMAN`, `UPDATEMAN`, ";
	sql += "`WYDJ`, `PIMPERSONID`, `JLSS`, `JLGLBH`, `JLSPZT`, `JLCZZ`";
	sql += "FROM t_pimlanguageability WHERE `PIMLANGUAGEABILITYID` = ?";
	LanguageMapper mapper;
	return sqlSession->executeQuery<LanguageDO, LanguageMapper>(sql, mapper, "%s", id);
}

int LanguageDAO::insert(const LanguageDO& iObj)
{
	//数据库插入语句
	string sql = "INSERT INTO `t_pimlanguageability` ";
	sql += "(`PIMLANGUAGEABILITYID`, `UPDATEDATE`, `ENABLE`, `WYDJHQSJ`, `FJ`, ";
	sql += "`WYYZ`, `CREATEMAN`, `UPDATEMAN`, `WYDJ`, `CREATEDATE`, `PIMPERSONID`) ";
	sql += "VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%i%s%s%s%s%s%s%s%s",iObj.getLanguageAbilityID(), iObj.getCreateDate(), 0, iObj.getGainTime(), 
		iObj.getAttachment(), iObj.getLanguageType(), iObj.getCreateMan(), iObj.getCreateMan(), 
		iObj.getLanguageLevel(), iObj.getCreateDate(), iObj.getPersonID());
}

int LanguageDAO::update(const LanguageDO& uObj)
{
	//数据库修改语句
	string sql = "UPDATE `t_pimlanguageability` ";
	sql += "SET `UPDATEDATE` = ?, `ENABLE` = ?, `WYDJHQSJ` = ?, `FJ` = ?, `WYYZ` = ?, `UPDATEMAN` = ?, `WYDJ` = ? ";
	sql += "WHERE `PIMLANGUAGEABILITYID` = ?";
	return sqlSession->executeUpdate(sql, "%s%i%s%s%s%s%s%s", uObj.getUpdateDate(), uObj.getPermission(), uObj.getGainTime(), 
		uObj.getAttachment(), uObj.getLanguageType(), uObj.getUpdateMan(), uObj.getLanguageLevel(), uObj.getLanguageAbilityID());
}

int LanguageDAO::deleteById(std::string id)
{
	//数据库删除语句
	string sql = "DELETE FROM `t_pimlanguageability` WHERE `PIMLANGUAGEABILITYID` = ?";
	return sqlSession->executeUpdate(sql, "%s", id);
}
