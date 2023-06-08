#include "stdafx.h"
#include "ContractInfoDAO.h"
#include "ContractInfoMapper.h"
#include "SnowFlake.h"
#include <sstream>
//定义条件解析宏，减少重复代码
#define DOWNLOAD_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE t_pimcontract.PIMPERSONID = t_pimperson.PIMPERSONID"; \
if (query->id) { \
	sql << " AND t_pimperson.YGBH=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->name) { \
	sql << " AND t_pimperson.PIMPERSONNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->emp_condition) { \
	sql << " AND t_pimperson.YGZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->emp_condition.getValue("")); \
} \
if (query->contract_num) { \
	sql << " AND t_pimcontract.HTBH=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contract_num.getValue("")); \
} \
if (query->type) { \
	sql << " AND t_pimcontract.HTLX=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->type.getValue("")); \
} \
if (query->variety) { \
	sql << " AND t_pimcontract.CONTRACTTYPE=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->variety.getValue("")); \
} \
if (query->condition) { \
	sql << " AND t_pimcontract.HTZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->condition.getValue("")); \
} \
if (query->date) { \
	sql << " AND t_pimcontract.QSRQ>=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->date.getValue("")); \
} \
if (query->date_end) { \
	sql << " AND t_pimcontract.JSRQ<=? "; \
	SQLPARAMS_PUSH(params, "s", std::string, query->date_end.getValue("")); \
}

std::list<ContractInfoDO> ContractInfoDAO::selectByInfoid(const string& infoid)
{	
	stringstream sql;

	sql << "SELECT t_pimperson.YGBH, t_pimperson.PIMPERSONNAME, t_pimcontract.HTLX, t_pimcontract.CONTRACTTYPE, t_pimcontract.QSRQ, t_pimcontract.HTZT, t_pimcontract.ORMORGNAME, t_pimcontract.LEGALORG, t_pimcontract.SYDQSJ, t_pimcontract.DEMO, t_pimcontract.PIMCONTRACTID, t_pimcontract.JSRQ ,t_pimcontract.HTBH, t_pimperson.YGZT ";
	sql << "FROM t_pimperson,t_pimcontract ";
	sql << "WHERE t_pimcontract.PIMPERSONID = t_pimperson.PIMPERSONID AND t_pimcontract.PIMCONTRACTID = '" << infoid << "'";
	
	ContractInfoMapper mapper;
	string sqlStr = sql.str();

	return sqlSession->executeQuery<ContractInfoDO, ContractInfoMapper>(sqlStr, mapper);
}

int ContractInfoDAO::update(const ContractInfoDO& uObj)
{
	stringstream sql;
	sql << "UPDATE `t_pimcontract`, `t_pimperson` ";
	sql << "SET t_pimperson.YGBH = '" << uObj.getId() << "', t_pimperson.PIMPERSONNAME = '" << uObj.getName() << "', ";
	sql << "t_pimcontract.HTLX = '" << uObj.getType() << "', t_pimcontract.CONTRACTTYPE = '"<< uObj.getVariety() << "', ";
	sql << "t_pimcontract.QSRQ = '" << uObj.getDate() << "', t_pimcontract.HTZT = '" << uObj.getCondition() << "', ";
	sql << "t_pimcontract.ORMORGNAME = '" << uObj.getDepartment_m() << "', t_pimcontract.LEGALORG = '" << uObj.getDepartment_c() << "', ";
	sql << "t_pimcontract.SYDQSJ = '" << uObj.getTry_end() << "', t_pimcontract.DEMO = '" << uObj.getTip() << "', ";
	sql << "t_pimcontract.JSRQ = '" << uObj.getDate_end() << "', t_pimcontract.HTBH = '" << uObj.getContract_num() << "', ";
	sql << "t_pimperson.YGZT = '" << uObj.getEmp_condition() << "'";
	sql << "WHERE t_pimcontract.PIMCONTRACTID = '" << uObj.getInfoid() << "' AND t_pimcontract.PIMPERSONID = t_pimperson.PIMPERSONID";

	string sqlStr = sql.str();
	//std::cout << sqlStr;
	return sqlSession->executeUpdate(sqlStr);
}


std::list<ContractInfoDO> ContractInfoDAO::downloadByFiltration(const ContractDownloadQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t_pimperson.YGBH,t_pimperson.PIMPERSONNAME,t_pimcontract.HTLX, t_pimcontract.CONTRACTTYPE,t_pimcontract.QSRQ,t_pimcontract.HTZT,t_pimcontract.ORMORGNAME,t_pimcontract.LEGALORG,t_pimcontract.SYDQSJ,t_pimcontract.DEMO,t_pimcontract.PIMCONTRACTID,t_pimcontract.JSRQ,t_pimcontract.HTBH,t_pimperson.YGZT ";
	sql << "FROM `t_pimcontract`,`t_pimperson` ";
	DOWNLOAD_TERAM_PARSE(query, sql);
	sql <<  " ORDER BY t_pimperson.YGBH LIMIT " << query->rows.getValue(1);
	ContractInfoMapper mapper;
	string sqlStr = sql.str();

	return sqlSession->executeQuery<ContractInfoDO, ContractInfoMapper>(sqlStr, mapper, params);
}



uint64_t ContractInfoDAO::insert(const ContractInfoDO& iObj)
{
	SnowFlake sf(1, 6);
	//合同信息标识生成
	string sf1 = std::to_string(sf.nextId());
	//std::cout << "合同信息标识: " << sf1 << endl;
	//员工信息标识生成
	string sf2 = std::to_string(sf.nextId());
	//std::cout << "员工信息标识: " << sf2 << endl;

	string sql1 = "INSERT INTO `t_pimperson` (`YGBH`, `PIMPERSONNAME`, `PIMPERSONID`, `YGZT`) VALUES (?, ?, ?, ?)";
	uint64_t res1 = sqlSession->executeInsert(sql1, "%s%s%s%s", iObj.getId(), iObj.getName(), sf2, iObj.getEmp_condition());

	string sql2 = "INSERT INTO `t_pimcontract` (`HTLX`, `CONTRACTTYPE`, `QSRQ`,`HTZT`,`ORMORGNAME`,`LEGALORG`,`SYDQSJ`,`DEMO`,`JSRQ`, `PIMCONTRACTID`, `HTBH`, `PIMPERSONID`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	uint64_t res2 = sqlSession->executeInsert(sql2, "%s%s%s%s%s%s%s%s%s%s%s%s", iObj.getType(), iObj.getVariety(), iObj.getDate(), iObj.getCondition(), iObj.getDepartment_m(),iObj.getDepartment_c(), iObj.getTry_end(), iObj.getTip(), iObj.getDate_end(), sf1, iObj.getContract_num(), sf2);


	return res2;
}