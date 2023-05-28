#include "stdafx.h"
#include "ProbationaryEmployeeDAO.h"
#include "ProbationaryEmployeeMapper.h"
#include <sstream>

//定义条件解析宏
#define PROBATIONARY_EMPLOYEE_PARSE(query,sql)\
SqlParams params; \
sql<<" WHERE 1 = 1"; \
if(query->id){ \
	sql << " AND `YGBH`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue(""));\
}\
if(query->name){ \
	sql << " AND `PIMPERSONNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue(""));\
} 

uint64_t ProbationaryEmployeeDAO::count(const ProbationaryEmployeeQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pcmsgqmgr";

	PROBATIONARY_EMPLOYEE_PARSE(query, sql);

	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ProbationaryEmployeeDO> ProbationaryEmployeeDAO::selectWithPage(const ProbationaryEmployeeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t_pimperson.YGBH,PIMPERSONNAME,ORMORGNAME,ORMORGSECTORNAME,ZW,ORMPOSTNAME,RZSJ,SYDQ \
		FROM t_pcmsgqmgr INNER JOIN t_pimperson \
		ON t_pcmsgqmgr.PIMPERSONID = t_pimperson.PIMPERSONID";
	PROBATIONARY_EMPLOYEE_PARSE(query, sql);

	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	string sqlStr = sql.str();


	ProbationaryEmployeeMapper mapper;

	return sqlSession->executeQuery<ProbationaryEmployeeDO>(sqlStr, mapper, params);
}

list<ProbationaryEmployeeDO> ProbationaryEmployeeDAO::selectAll(const ProbationaryEmployeeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t_pimperson.YGBH,PIMPERSONNAME,ORMORGNAME,ORMORGSECTORNAME,ZW,ORMPOSTNAME,RZSJ,SYDQ \
		FROM t_pcmsgqmgr INNER JOIN t_pimperson \
		ON t_pcmsgqmgr.PIMPERSONID = t_pimperson.PIMPERSONID";
	PROBATIONARY_EMPLOYEE_PARSE(query, sql);

	string sqlStr = sql.str();

	ProbationaryEmployeeMapper mapper;

	return sqlSession->executeQuery<ProbationaryEmployeeDO>(sqlStr, mapper, params);
}
