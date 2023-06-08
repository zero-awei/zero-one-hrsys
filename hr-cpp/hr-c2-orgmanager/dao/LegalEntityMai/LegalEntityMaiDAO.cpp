#include "stdafx.h"
#include "LegalEntityMaiDAO.h"
#include "LegalEntityMaiMapper.h"
#include <sstream>

/* 法人主体维护DAO定义--（组织管理-数据设置-法人主体维护）--TripleGold */
//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql <<" WHERE 1=1"; \
if (query->ORMSIGNORGNAME) { \
	sql << " AND `ORMSIGNORGNAME`= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ORMSIGNORGNAME.getValue("")); \
} \

uint64_t LegalEntityMaiDAO::count(const LegalEntityMaiQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_ormsignorg";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<OrmsignorgDO> LegalEntityMaiDAO::selectWithPage(const LegalEntityMaiQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT ORMSIGNORGID, ORMSIGNORGNAME, ORGCODE FROM t_ormsignorg";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LegalEntityMaiMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<OrmsignorgDO, LegalEntityMaiMapper>(sqlStr, mapper, params);
}

int LegalEntityMaiDAO::update(const OrmsignorgDO& uObj)
{
	string sql = "UPDATE t_ormsignorg SET ORMSIGNORGNAME=?, ORGCODE=? WHERE ORMSIGNORGID=?";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getName(), uObj.getCode(), uObj.getId());
}

uint64_t LegalEntityMaiDAO::insert(const OrmsignorgDO& iObj)
{
	string sql = "INSERT INTO t_ormsignorg (ORMSIGNORGID, ORMSIGNORGNAME, ORGCODE, CREATEMAN, CREATEDATE, UPDATEMAN, UPDATEDATE) VALUES (?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", iObj.getId(), iObj.getName(), iObj.getCode(), iObj.getCreateman(), iObj.getCreateDate(), iObj.getUpdateman(), iObj.getUpdatedate());
}

int LegalEntityMaiDAO::deleteById(string id)
{
	string sql = "DELETE FROM t_ormsignorg WHERE ORMSIGNORGID=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}