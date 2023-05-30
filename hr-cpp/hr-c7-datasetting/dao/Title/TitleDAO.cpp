#include "stdafx.h"
#include "TitleDAO.h"
#include "TitleMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define Title_TERAM_PARSE(query, sql) \
SqlParams params; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
}\


uint64_t TitleDAO::count(const TitleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM title";
	Title_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<TitleDO> TitleDAO::selectWithPage(const TitleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM title";
	Title_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	TitleMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<TitleDO, TitleMapper>(sqlStr, mapper, params);
}

std::list<TitleDO> TitleDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM title WHERE `name` LIKE CONCAT('%',?,'%')";
	TitleMapper mapper;
	return sqlSession->executeQuery<TitleDO, TitleMapper>(sql, mapper, "%s", name);
}

uint64_t TitleDAO::insert(const TitleDO& iObj)
{
	string sql = "INSERT INTO `title` (`id`, `num`, `name`,`dtype`,`Ttype`) VALUES (?, ?, ?,?,?)";
	return sqlSession->executeUpdate(sql, "%i%s%s%s%s", iObj.getId(), iObj.getNum(), iObj.getName(), iObj.getDtype(), iObj.getTTtype());
}

int TitleDAO::update(const TitleDO& uObj)
{
	string sql = "UPDATE `title` SET  `num`=?, `name`=? ,`dtype`=?,`Ttype`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%i", uObj.getNum(), uObj.getName(), uObj.getDtype(), uObj.getTTtype(), uObj.getId());
}

int TitleDAO::deleteById(uint32_t id)
{
	string sql = "DELETE FROM `title` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%i", id);
}