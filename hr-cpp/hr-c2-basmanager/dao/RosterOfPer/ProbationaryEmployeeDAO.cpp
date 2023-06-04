#include "stdafx.h"
#include "ProbationaryEmployeeDAO.h"
#include "ProbationaryEmployeeMapper.h"
#include <sstream>
/**
 * 人员花名册 - 试用人员 - 楚孟献
 */

//定义条件解析宏
#define PROBATIONARY_EMPLOYEE_PARSE(query,sql)\
SqlParams params; \
sql<<" WHERE 1 = 1"; \
if(query->id_or_name){ \
	sql << " AND (`t_pimperson`.YGBH LIKE ? OR `PIMPERSONNAME` LIKE ?)";\
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->id_or_name.getValue("") + "%");\
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->id_or_name.getValue("") + "%");\
}\
else{\
	if(query->id){ \
		sql << " AND `t_pimperson`.YGBH LIKE ?"; \
		SQLPARAMS_PUSH(params, "s", std::string, "%" + query->id.getValue("") + "%");\
	}\
	if(query->name){ \
		sql << " AND `PIMPERSONNAME` LIKE ?"; \
		SQLPARAMS_PUSH(params, "s", std::string, "%" + query->name.getValue("") + "%");\
	}\
	if(query->zjhm){ \
		sql << " AND `ZJHM` LIKE ?"; \
		SQLPARAMS_PUSH(params, "s", std::string, "%" + query->zjhm.getValue("") + "%");\
	}\
	if(query->organization){ \
		sql << " AND `ORMORGNAME` LIKE ?"; \
		SQLPARAMS_PUSH(params, "s", std::string, "%" + query->organization.getValue("") + "%");\
	} \
	if(query->bm){ \
		sql << " AND `BM` LIKE ?"; \
		SQLPARAMS_PUSH(params, "s", std::string, "%" + query->bm.getValue("") + "%");\
	}\
	if(query->ygzt){ \
		sql << " AND `YGZT` LIKE ?"; \
		SQLPARAMS_PUSH(params, "s", std::string, "%" + query->ygzt.getValue("") + "%");\
	}\
	if(query->zgzt){ \
		sql << " AND `ZGZT` LIKE ?"; \
		SQLPARAMS_PUSH(params, "s", std::string, "%" + query->zgzt.getValue("") + "%");\
	}\
}\


uint64_t ProbationaryEmployeeDAO::count(const ProbationaryEmployeeQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pcmsgqmgr INNER JOIN t_pimperson \
		ON t_pcmsgqmgr.PIMPERSONID = t_pimperson.PIMPERSONID";

	PROBATIONARY_EMPLOYEE_PARSE(query, sql);

	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ProbationaryEmployeeDO> ProbationaryEmployeeDAO::selectWithPage(const ProbationaryEmployeeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t_pimperson.YGBH,PIMPERSONNAME,ORMORGNAME,ORMORGSECTORNAME,ZW,ORMPOSTNAME,RZSJ,SYDQ, t_pimperson.PIMPERSONID \
		FROM t_pcmsgqmgr INNER JOIN t_pimperson \
		ON t_pcmsgqmgr.PIMPERSONID = t_pimperson.PIMPERSONID ";
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

	sql << " LIMIT 5000 ";// 设置输出上限条数
	string sqlStr = sql.str();

	ProbationaryEmployeeMapper mapper;

	return sqlSession->executeQuery<ProbationaryEmployeeDO>(sqlStr, mapper, params);
}
