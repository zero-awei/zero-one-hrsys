#include "stdafx.h"
#include "LoanedPerDAO.h"
#include "LoanedPerDAO.h"
#include "LoanedPerMapper.h"
#include <sstream>

//定义条件解析宏
#define LOANEDPER_TERAM_PARSE(query,sql)\
SqlParams params; \
sql<<" WHERE 1=1"; \
if(query->id){ \
	sql << " AND `YGBH`LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if(query->name){ \
	sql << " AND `PIMPERSONNAME`LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \

uint64_t LoanedPerDAO::count(const LoanedPerPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimperson";

	LOANEDPER_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//查询语句有问题
list<SecondedPersonnelDO> LoanedPerDAO::selectWithPage(const LoanedPerPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t_pcmydmx.YGBH,t_pimperson.PIMPERSONNAME,t_pcmydmx.ZZ,t_pcmydmx.BM,YZW,YGW,t_srforg.ORGNAME,ORMORGSECTORNAME,ORMDUTYNAME,t_ormpost.ORMPOSTNAME,t_pcmydjdmx.PCMYDJDMXID  \
				,t_pcmydjdmx.JDKSRQ,t_pcmydjdmx.JDJSRQ "
		<<" FROM t_pcmydmx,t_pimperson,t_pcmydjdmx,t_srforg,t_srforgsector,t_ormduty,t_ormpost ";

	SqlParams params; 
	sql << " WHERE t_pcmydmx.YGBH=t_pimperson.YGBH and t_pcmydmx.PCMYDMXID=t_pcmydjdmx.PCMYDJDMXID "
		<< " and t_srforg.ORGID = t_pcmydjdmx.JDORMORGID and t_pcmydjdmx.ORMORGSECTORID = t_srforgsector.ORGSECTORID "
		<< " and t_pcmydjdmx.ORMDUTYID=t_ormduty.ORMDUTYID and t_ormpost.ORMPOSTID=t_pcmydjdmx.ORMPOSTID"; 
	if (query->id) {
				sql << " AND `t_pcmydmx.YGBH`LIKE CONCAT('%',?,'%')";
			SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue(""));
	} 
	if (query->name) {
			sql << " AND `t_pimperson.PIMPERSONNAME`LIKE CONCAT('%',?,'%')"; 
			SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); 
	} 

	//LOANEDPER_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LoanedPerMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<SecondedPersonnelDO, LoanedPerMapper>(sqlStr, mapper, params);
}

