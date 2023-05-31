/**
 * 人员信息分页查询DAO--(证书管理-分页查询员工信息列表)--weixiaoman
 */
#include "stdafx.h"
#include "EmployeeInfoDAO.h"
#include "EmployeeInfoMapper.h"
#include <sstream>
 
 //定义条件解析宏
#define EMPINFO_TERAM_PARSE(query,sql)\
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `PIMPERSONNAME` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} 

uint64_t EmployeeInfoDAO::count(const EmployeeInfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimperson";

	EMPINFO_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<EmployeeInfoDO> EmployeeInfoDAO::selectWithPage(const EmployeeInfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT PIMPERSONNAME,PIMPERSONID FROM t_pimperson";
	EMPINFO_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	EmployeeInfoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<EmployeeInfoDO, EmployeeInfoMapper>(sqlStr, mapper, params);
}

list<EmployeeInfoDO> EmployeeInfoDAO::selectByName(const string& name)
{
	string sql = "SELECT PIMPERSONNAME,YGBH FROM t_pimperson WHERE `PIMPERSONNAME` LIKE CONCAT('%',?,'%')";
	EmployeeInfoMapper mapper;
	return sqlSession->executeQuery<EmployeeInfoDO, EmployeeInfoMapper>(sql, mapper, "%s", name);
}
