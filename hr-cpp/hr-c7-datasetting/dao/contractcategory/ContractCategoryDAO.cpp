#include "stdafx.h"
#include "ContractCategoryDAO.h"
#include "ContractCategoryMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define CONTRACT_CATEGORY_TERM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
    sql << " AND `name`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->description) { \
    sql << " AND description=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->description.getValue("")); \
}

uint64_t ContractCategoryDAO::count(const ContractCategoryQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM contract_category";
	CONTRACT_CATEGORY_TERM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ContractCategoryDO> ContractCategoryDAO::selectWithPage(const ContractCategoryQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM contract_category";
	CONTRACT_CATEGORY_TERM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ContractCategoryMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ContractCategoryDO, ContractCategoryMapper>(sqlStr, mapper, params);
}