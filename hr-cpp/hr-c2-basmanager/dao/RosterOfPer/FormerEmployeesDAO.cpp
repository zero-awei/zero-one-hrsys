#include "stdafx.h"
#include "FormerEmployeesDAO.h"
#include "FormerEmployeesMapper.h"
#include <sstream>
/**
 * 人员花名册 - 离职人员 - 楚孟献
 */

//定义条件解析宏
#define FORMER_EMPLOYEES_PARSE(query,sql)\
SqlParams params; \
sql<<" WHERE 1=1 "; \
if(query->id_or_name){ \
	sql << " AND (`YGBH` LIKE ? OR `PIMPERSONNAME` LIKE ?)";\
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->id_or_name.getValue("") + "%");\
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->id_or_name.getValue("") + "%");\
}\

uint64_t FormerEmployeesDAO::count(const FormerEmployeesQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimperson INNER JOIN t_pcmydlzmx \
		ON t_pimperson.PIMPERSONID = t_pcmydlzmx.lzmtrId";

	FORMER_EMPLOYEES_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<FormerEmployeesDO> FormerEmployeesDAO::selectWithPage(const FormerEmployeesQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT PIMPERSONID, ygbh, PIMPERSONNAME, XB, lxdh, csrq, ORMORGNAME, ORMORGSECTORNAME, POSTALADDRESS, jtlxr, jtlxrdh, 'rank', lzmtrid \
		FROM t_pimperson INNER JOIN t_pcmydlzmx \
		ON t_pimperson.PIMPERSONID = t_pcmydlzmx.lzmtrId";
	FORMER_EMPLOYEES_PARSE(query, sql);

	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	string sqlStr = sql.str();

	FormerEmployeesMapper mapper;

	return sqlSession->executeQuery<FormerEmployeesDO, FormerEmployeesMapper>(sqlStr, mapper, params);
}

list<FormerEmployeesDO> FormerEmployeesDAO::selectAll(const FormerEmployeesQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t_pimperson.PIMPERSONID, ygbh, PIMPERSONNAME, XB, lxdh, csrq, ORMORGNAME, ORMORGSECTORNAME, POSTALADDRESS, jtlxr, jtlxrdh, 'rank' \
		FROM t_pimperson INNER JOIN t_pcmydlzmx \
		ON t_pimperson.PIMPERSONID = t_pcmydlzmx.lzmtrId";
	FORMER_EMPLOYEES_PARSE(query, sql);

	sql << " LIMIT 5000 ";// 设置输出上限条数
	string sqlStr = sql.str();

	FormerEmployeesMapper mapper;

	return sqlSession->executeQuery<FormerEmployeesDO, FormerEmployeesMapper>(sqlStr, mapper, params);
}