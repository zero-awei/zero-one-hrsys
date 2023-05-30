#include "stdafx.h"
#include "ContractInfoDAO.h"
#include "ContractInfoMapper.h"
#include "SnowFlake.h"
#include <sstream>


std::list<ContractInfoDO> ContractInfoDAO::selectByInfoid(const string& infoid)
{	
	stringstream sql;

	sql << "SELECT t_pimperson.YGBH, t_pimperson.PIMPERSONNAME, t_pimcontract.HTLX, t_pimcontract.CONTRACTTYPE, t_pimcontract.QSRQ, t_pimcontract.HTZT, t_pimcontract.ORMORGNAME, t_pimcontract.LEGALORG, t_pimcontract.SYDQSJ, t_pimcontract.DEMO, t_pimcontract.PIMCONTRACTID, t_pimcontract.JSRQ ";
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
	sql << "t_pimcontract.JSRQ = '" << uObj.getDate_end() << "'";
	sql << "WHERE t_pimcontract.PIMCONTRACTID = '" << uObj.getInfoid() << "' AND t_pimcontract.PIMPERSONID = t_pimperson.PIMPERSONID";

	string sqlStr = sql.str();
	//std::cout << sqlStr;
	return sqlSession->executeUpdate(sqlStr);
}


std::list<ContractInfoDO> ContractInfoDAO::downloadByRows(oatpp::String sequence, UInt64 rows)
{
	stringstream sql;
	sql << "SELECT t_pimperson.YGBH,t_pimperson.PIMPERSONNAME,t_pimcontract.HTLX, t_pimcontract.CONTRACTTYPE,t_pimcontract.QSRQ,t_pimcontract.HTZT,t_pimcontract.ORMORGNAME,t_pimcontract.LEGALORG,t_pimcontract.SYDQSJ,t_pimcontract.DEMO,t_pimcontract.PIMCONTRACTID,t_pimcontract.JSRQ ";
	sql << "FROM `t_pimcontract`,`t_pimperson` ";
	sql << "WHERE t_pimcontract.PIMPERSONID = t_pimperson.PIMPERSONID ";
	sql << "ORDER BY t_pimcontract.PIMCONTRACTID " << (string)sequence << " LIMIT " << rows;
	ContractInfoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ContractInfoDO, ContractInfoMapper>(sqlStr, mapper);
}



uint64_t ContractInfoDAO::insert(const ContractInfoDO& iObj)
{
	SnowFlake sf(1, 6);
	UInt64 sf1 = sf.nextId();
	UInt64 sf2 = sf.nextId();

	string sql1 = "INSERT INTO `t_pimcontract` (`HTLX`, `CONTRACTTYPE`, `QSRQ`,`HTZT`,`ORMORGNAME`,`LEGALORG`,`SYDQSJ`,`DEMO`,`JSRQ`, `PIMCONTRACTID`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	uint64_t res1 = sqlSession->executeInsert(sql1, "%s%s%s%s%s%s%s%s%s%ull", iObj.getType(), iObj.getVariety(), iObj.getDate(), iObj.getCondition(), iObj.getDepartment_m(),iObj.getDepartment_c(), iObj.getTry_end(), iObj.getTip(), iObj.getDate_end(), sf1);

	string sql2 = "INSERT INTO `t_pimperson` (`YGBH`, `PIMPERSONNAME`, `PIMPERSONID`) VALUES (?, ?, ?)";
	uint64_t res2 = sqlSession->executeInsert(sql2, "%s%s%ull", iObj.getId(), iObj.getName(), sf2);

	return res2;
}