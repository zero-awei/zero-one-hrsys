#include "stdafx.h"
#include "ContractCategoryDAO.h"
#include "ContractCategoryMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define CONTRACT_CATEGORY_TERM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
    sql << " AND PIMCONTRACTTYPENAME=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
}

uint64_t ContractCategoryDAO::count(const ContractCategoryQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimcontracttype";
	CONTRACT_CATEGORY_TERM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ContractCategoryDO> ContractCategoryDAO::selectWithPage(const ContractCategoryQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT PIMCONTRACTTYPEID, PIMCONTRACTTYPENAME FROM t_pimcontracttype";
	CONTRACT_CATEGORY_TERM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ContractCategoryMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ContractCategoryDO, ContractCategoryMapper>(sqlStr, mapper, params);
}

ContractCategoryDO ContractCategoryDAO::selectById(const std::string& id)
{
	stringstream sql;
	sql << "SELECT PIMCONTRACTTYPEID, PIMCONTRACTTYPENAME FROM t_pimcontracttype WHERE PIMCONTRACTTYPEID=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, id);
	string sqlStr = sql.str();
	ContractCategoryMapper mapper;
	return sqlSession->executeQuery<ContractCategoryDO, ContractCategoryMapper>(sqlStr, mapper, params).front();
}
uint64_t ContractCategoryDAO::insert(const ContractCategoryDO& data)
{
	stringstream sql;
	sql << "INSERT INTO t_pimcontracttype(PIMCONTRACTTYPEID, PIMCONTRACTTYPENAME) VALUES (?, ?)";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, data.getId());
	SQLPARAMS_PUSH(params, "s", std::string, data.getName());
	string sqlStr = sql.str();
	return sqlSession->executeUpdate(sqlStr, params);
}

int ContractCategoryDAO::update(const ContractCategoryDO& data)
{
	stringstream sql;
	sql << "UPDATE t_pimcontracttype SET PIMCONTRACTTYPENAME=? WHERE PIMCONTRACTTYPEID=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, data.getName());
	SQLPARAMS_PUSH(params, "s", std::string, data.getId());
	string sqlStr = sql.str();
	return sqlSession->executeUpdate(sqlStr, params);
}

int ContractCategoryDAO::deleteById(const std::string& id)
{
	stringstream sql;
	sql << "DELETE FROM t_pimcontracttype WHERE PIMCONTRACTTYPEID=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, id);
	string sqlStr = sql.str();
	return sqlSession->executeUpdate(sqlStr, params);
}