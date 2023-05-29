#include "stdafx.h"
#include "ContractTypeDAO.h"
#include "ContractTypeMapper.h"

//定义条件解析宏，减少重复代码
#define CONTRACT_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `PIMPERSONNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
}

uint64_t ContractTypeDAO::count(const ContractTypeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `t_pimcontract` a INNER JOIN `t_pimperson` b ON a.PIMPERSONID=b.PIMPERSONID ";
	CONTRACT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ContractTypeDO> ContractTypeDAO::selectWithPage(const ContractTypeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT YGBH,PIMPERSONNAME,a.ORMORGNAME,YGZT,DBDWSJ,HTBH,LEGALORG,HTLX,CONTRACTTYPE,QSRQ,JSRQ,HTZT,IF(JSRQ IS NULL,NULL,IF(DATEDIFF(JSRQ,CURDATE())<0,0,DATEDIFF(JSRQ,CURDATE()))) SYTS,SYDQSJ FROM `t_pimcontract` a INNER JOIN `t_pimperson` b ON a.PIMPERSONID=b.PIMPERSONID ";
	CONTRACT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ContractTypeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ContractTypeDO, ContractTypeMapper>(sqlStr, mapper, params);
}