#include "stdafx.h"
#include "ContractDAO.h"
#include "ContractMapper.h"

uint64_t ContractDAO::count(const ContractQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `t_pimcontract` WHERE `PIMPERSONID`=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->PIMPERSONID.getValue(""));
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ContractDO> ContractDAO::selectWithPage(const ContractQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT HTBH,HTLX,CONTRACTTYPE,QSRQ,JSRQ,HTZT,SYDQSJ FROM `t_pimcontract` WHERE `PIMPERSONID`=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->PIMPERSONID.getValue(""));
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ContractMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ContractDO, ContractMapper>(sqlStr, mapper, params);
}
