#include "stdafx.h"
#include "contractManagerDAO.h"
#include <sstream>
#include "contractManagerMapper.h"

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) {  /*查询过滤字段传递的query是否有员工姓名*/ \
	sql << " AND t_pimperson.PIMPERSONNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->id) { \
	sql << " AND t_pimperson.YGBH=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->Employee_status) { \
	sql << " AND t_pimperson.YGZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->Employee_status.getValue("")); \
} \
if (query->contract_id) { \
	sql << " AND t_pimcontract.HTBH=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contract_id.getValue("")); \
} \
if (query->contract_class) { \
	sql << " AND t_pimcontract.HTLX=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contract_class.getValue("")); \
} \
if (query->contract_state) { \
	sql << " AND t_pimcontract.HTZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contract_state.getValue("")); \
} \
if (query->start_date) { \
	sql << " AND t_pimcontract.QSRQ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->start_date.getValue("")); \
} \
if (query->stop_date) { \
	sql << " AND t_pimcontract.JSRQ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->stop_date.getValue("")); \
} \
if (query->contract_type) { \
	sql << " AND t_pimcontract.CZ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contract_type.getValue("")); \
} \

uint64_t ContractManagerDAO::count(const contractManagerQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select * from t_pimcontract join t_pimperson on t_pimperson.PIMPERSONID = t_pimcontract.PIMPERSONID";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
list<contractManagerDO> ContractManagerDAO::selectWithPage(const contractManagerQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select t_pimperson.YGBH,t_pimperson.PIMPERSONNAME,";
	sql << "t_pimperson.ORMORGNAME,t_pimperson.YGZT,t_pimperson.DBDWSJ,";
	sql << "t_pimcontract.HTBH,t_pimcontract.LEGALORG,t_pimcontract.HTLX,";
	sql << "t_pimcontract.CONTRACTTYPE,t_pimcontract.QSRQ,t_pimcontract.JSRQ,";
	sql << "t_pimcontract.CZ from t_pimcontract join t_pimperson ";
	sql << "on t_pimperson.PIMPERSONID = t_pimcontract.PIMPERSONID  ";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	contractManagerMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<contractManagerDO, contractManagerMapper>(sqlStr, mapper, params);
}