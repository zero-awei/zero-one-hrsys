#include "stdafx.h"
#include "TitleDAO.h"
#include "TitleMapper.h"
#include <sstream>
#include "../../lib-common/include/SnowFlake.h"
//定义条件解析宏，减少重复代码
#define Title_TERAM_PARSE(query, sql) \
SqlParams params; \
if (query->name) { \
	sql << " WHERE s.PIMTITLECATALOGUENAME = ?"; \
	SQLPARAMS_PUSH(params,"s", std::string, query->name.getValue("")); \
}\


uint64_t TitleDAO::count(const TitleQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimtitlecatalogue s";
	Title_TERAM_PARSE(query, sql)
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<TitleDO> TitleDAO::selectWithPage(const TitleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT s.PXH,s.DH,s.PIMTITLECATALOGUENAME,e.PIMTITLECATALOGUENAME AS t_pimtitlecatalogue,s.ZCLC\
		FROM t_pimtitlecatalogue s\
		JOIN t_pimtitlecatalogue e ON e.DH = s.PIMTITLECATALOGUEID2";
	Title_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	TitleMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<TitleDO, TitleMapper>(sqlStr, mapper, params);
}

std::list<TitleDO> TitleDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM t_pimtitlecatalogue WHERE `PIMTITLECATALOGUENAME` LIKE CONCAT('%',?,'%')";
	TitleMapper mapper;
	return sqlSession->executeQuery<TitleDO, TitleMapper>(sql, mapper, "%s", name);
}

uint64_t TitleDAO::insert(const TitleDO& iObj)
{
	
	string sql = "INSERT INTO `t_pimtitlecatalogue` (`PXH`, `PIMTITLECATALOGUEID`, `PIMTITLECATALOGUENAME`,`PIMTITLECATALOGUEID2`,`ZCLC`,`CREATEDATE`,`CREATEMAN`) VALUES (?, ?, ?,?,?,NOW(),UUID())";
	return sqlSession->executeUpdate(sql, "%i%s%s%s%s", iObj.getId(), iObj.getNum(), iObj.getName(), iObj.getDtype(), iObj.getTTtype());
}

int TitleDAO::update(const TitleDO& uObj)
{

	string sql = "UPDATE `t_pimtitlecatalogue` SET  `DH`=?, `PIMTITLECATALOGUENAME`=? ,`PIMTITLECATALOGUEID2`=?,`ZCLC`=?,`UPDATEDATE`=NOW(),`UPDATEMAN`=UUID() WHERE `PXH`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%i", uObj.getNum(), uObj.getName(), uObj.getDtype(), uObj.getTTtype(),uObj.getId());
}

int TitleDAO::deleteById(uint32_t id)
{
	string sql = "DELETE FROM `t_pimtitlecatalogue` WHERE `PXH`=?";
	return sqlSession->executeUpdate(sql, "%i", id);
}