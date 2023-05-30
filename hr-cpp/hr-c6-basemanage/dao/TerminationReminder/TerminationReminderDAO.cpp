#include "stdafx.h"
#include "TerminationReminderDAO.h"
#include "TerminationReminderMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define TERMINATION_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->employee_name) { \
	sql << " AND `CREATEMAN`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->employee_name.getValue("")); \
} \
if (query->employee_id) { \
	sql << " AND PIMCONTRACTID=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->employee_id.getValue("")); \
} \
if (query->employee_status) { \
	sql << " AND PIMPERSONID=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->employee_status.getValue("")); \
}\
if(query->contract_id){\
	sql<<"AND HTBH=?";\
	SQLPARAMS_PUSH(params,"s",std::string,query->contract_id.getValue(""));\
}\
if(query->contract_statu){\
	sql<<"AND HTZT=?";\
	SQLPARAMS_PUSH(params,"s",std::string,query->contract_statu.getValue(""));\
}\
if(query->contract_lb){\
	sql<<"AND CONTRACTTYPE=?";\
	SQLPARAMS_PUSH(params,"s",std::string,query->contract_lb.getValue(""));\
}\
if(query->contract_lx){\
	sql<<"AND HTLX=?";\
	SQLPARAMS_PUSH(params,"s",std::string,query->contract_lx.getValue(""));\
}\
if(query->begin_time){\
	sql<<"AND QSRQ=?";\
	SQLPARAMS_PUSH(params,"s",std::string,query->begin_time.getValue(""));\
}\
if(query->deadline){\
	sql<<"AND JSRQ=?";\
	SQLPARAMS_PUSH(params,"s",std::string,query->deadline.getValue(""));\
}


uint64_t TerminationReminderDAO::count(const TerminationReminderQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimcontract";
	TERMINATION_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<TerminationReminderDO> TerminationReminderDAO::selectWithPage(const TerminationReminderQuery::Wrapper& query)
{
	stringstream sql;
	//            员工id,        员工姓名,员工所属单位，员工状态， 到达时间，合同编号，合同签订单位,合同类别,合同类型，开始日期，结束日期
	sql << "SELECT PIMCONTRACTID,CREATEMAN,ORMORGNAME,PIMPERSONID,CREATEDATE, HTBH, LEGALORG,CONTRACTTYPE,HTLX,QSRQ,JSRQ FROM t_pimcontract";
	TERMINATION_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	TerminationReminderMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<TerminationReminderDO, TerminationReminderMapper>(sqlStr, mapper, params);
}
std::list<TerminationReminderDO> TerminationReminderDAO::selectAll()
{
	stringstream sql;
	//            员工id,        员工姓名,员工所属单位，员工状态， 到达时间，合同编号，合同签订单位,合同类别,合同类型，开始日期，结束日期
	sql << "SELECT PIMCONTRACTID,CREATEMAN,ORMORGNAME,PIMPERSONID,CREATEDATE, HTBH, LEGALORG,CONTRACTTYPE,HTLX,QSRQ,JSRQ FROM t_pimcontract";
	SqlParams params;
	TerminationReminderMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<TerminationReminderDO, TerminationReminderMapper>(sqlStr, mapper, params);
}