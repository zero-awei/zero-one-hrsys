#include "stdafx.h"
#include "ContractTypeDAO.h"
#include "ContractTypeMapper.h"
#include "../../../lib-common/include/SnowFlake.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define CONTRACTTYPE_TERAM_PARSE(query, sql) \
SqlParams params; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
//sql<<" WHERE 1=1"; \
//if (query->id) { \
//	sql << " AND id=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \

uint64_t ContractTypeDAO::count(const ContractTypeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimtypecontract";
	CONTRACTTYPE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ContractTypeDO> ContractTypeDAO::selectWithPage(const ContractTypeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM t_pimtypecontract";
	CONTRACTTYPE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ContractTypeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ContractTypeDO, ContractTypeMapper>(sqlStr, mapper, params);
}

std::list<ContractTypeDO> ContractTypeDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM t_pimtypecontract WHERE `pimtypecontractname` LIKE CONCAT('%',?,'%')";
	ContractTypeMapper mapper;
	return sqlSession->executeQuery<ContractTypeDO, ContractTypeMapper>(sql, mapper, "%s", name);
}

uint64_t ContractTypeDAO::insert(const ContractTypeDO& iObj)
{
	SnowFlake sf(1, 1);
	stringstream ss;
	ss << sf.nextId();
	string PIMID = ss.str();
	string sql = "INSERT INTO `t_pimtypecontract` (`PIMTYPECONTRACTID`, `typecode`, `pimtypecontractname`) VALUES (?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s", PIMID, iObj.getId(), iObj.getName());
}

int ContractTypeDAO::update(const ContractTypeDO& uObj)
{
	string sql = "UPDATE `t_pimtypecontract` SET `pimtypecontractname`=? WHERE `typecode`=?";
	return sqlSession->executeUpdate(sql, "%s%s", uObj.getName(),uObj.getId());
}

int ContractTypeDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `t_pimtypecontract` WHERE `typecode`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}