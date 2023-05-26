#include "stdafx.h"
#include "GoshDAO.h"
#include "GoshMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->type) { \
	sql << " AND type=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->type.getValue("")); \
} \
//if (query->variety) { \
//	sql << " AND variety=?"; \
//	SQLPARAMS_PUSH(params, "i", int, query->variety.getValue("")); \
//}\
//if (query->date) { \
//	sql << " AND date=?"; \
//	SQLPARAMS_PUSH(params, "i", int, query->date.getValue("")); \
//}\
//if (query->condition) { \
//	sql << " AND condition=?"; \
//	SQLPARAMS_PUSH(params, "i", int, query->condition.getValue("")); \
//}\
//if (query->department_m) { \
//	sql << " AND department_m=?"; \
//	SQLPARAMS_PUSH(params, "i", int, query->department_m.getValue("")); \
//}\
//if (query->department_c) { \
//	sql << " AND department_c=?"; \
//	SQLPARAMS_PUSH(params, "i", int, query->department_c.getValue("")); \
//}\
//if (query->date_end) { \
//	sql << " AND date_end=?"; \
//	SQLPARAMS_PUSH(params, "i", int, query->date_end.getValue("")); \
//}\
//if (query->tip) { \
//	sql << " AND tip=?"; \
//	SQLPARAMS_PUSH(params, "i", int, query->tip.getValue("")); \
//}

uint64_t GoshDAO::count(const ContractQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM Gosh";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ContractDO> GoshDAO::selectWithPage(const ContractQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM Gosh";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GoshMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ContractDO, GoshMapper>(sqlStr, mapper, params);
}

std::list<ContractDO> GoshDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
	GoshMapper mapper;
	return sqlSession->executeQuery<ContractDO, GoshMapper>(sql, mapper, "%s", name);
}

uint64_t GoshDAO::insert(const ContractDO& iObj)
{
	string sql = "INSERT INTO `Gosh` (`name`, `type`, `variety`,`date`,`condition`,`department_m`,`department_c`,`date_end`,`tip`) VALUES (?, ?, ?,?,?,?,?,?,?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s", iObj.getName(), iObj.getType(), iObj.getVariety(), iObj.getDate(), iObj.getCondition(), iObj.getDepartment_m(), iObj.getDepartment_c(), iObj.getDate_end(), iObj.getTip());
}

int GoshDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `Gosh` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}