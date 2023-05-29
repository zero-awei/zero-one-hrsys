#include "stdafx.h"
#include "GoshDAO.h"
#include "GoshMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->type) { \
	sql << " AND type=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->type.getValue("")); \
} \
if (query->variety) { \
	sql << " AND variety=?"; \
	SQLPARAMS_PUSH(params, "i", std::string, query->variety.getValue("")); \
}\
if (query->date) { \
	sql << " AND date=?"; \
	SQLPARAMS_PUSH(params, "i", std::string, query->date.getValue("")); \
}\
if (query->condition) { \
	sql << " AND condition=?"; \
	SQLPARAMS_PUSH(params, "i", std::string, query->condition.getValue("")); \
}\
if (query->department_m) { \
	sql << " AND department_m=?"; \
	SQLPARAMS_PUSH(params, "i", std::string, query->department_m.getValue("")); \
}\
if (query->department_c) { \
	sql << " AND department_c=?"; \
	SQLPARAMS_PUSH(params, "i", std::string, query->department_c.getValue("")); \
}\
if (query->date_end) { \
	sql << " AND date_end=?"; \
	SQLPARAMS_PUSH(params, "i", std::string, query->date_end.getValue("")); \
}\
if (query->tip) { \
	sql << " AND tip=?"; \
	SQLPARAMS_PUSH(params, "i", std::string, query->tip.getValue("")); \
}

uint64_t GoshDAO::count(const ContractQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimcontract";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ContractDO> GoshDAO::selectWithPage(const ContractQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t_pimcontract.`PIMCONTRACTID`,t_pimperson.`PIMPERSONNAME`,t_pimcontract.`HTLX`,";
	sql << "t_pimcontract.`CONTRACTTYPE`,t_pimcontract.`QSRQ`,t_pimcontract.`HTZT`,t_pimcontract.`LEGALORG`,t_pimcontract.`SYDQSJ`,t_pimcontract.`DEMO`";
	sql << "FROM `t_pimcontract`,`t_pimperson` ";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GoshMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ContractDO, GoshMapper>(sqlStr, mapper, params);
}

std::list<ContractDO> GoshDAO::selectByName(const string& name)
{
	/*string sql = "SELECT * FROM t_pimcontract inner join t_pimperson on `name` LIKE CONCAT('%',?,'%'*/
	string sql = "SELECT t_pimcontract.`PIMCONTRACTID`,t_pimperson.`PIMPERSONNAME`,t_pimcontract.`HTLX`,\
	t_pimcontract.`CONTRACTTYPE`,t_pimcontract.`QSRQ`,t_pimcontract.`HTZT`,t_pimcontract.`LEGALORG`,t_pimcontract.`SYDQSJ`,t_pimcontract.`DEMO`\
	FROM `t_pimcontract` inner join `t_pimperson` where t_pimperson on `name` like CONCAT('%',?,'%')";
	GoshMapper mapper;
	return sqlSession->executeQuery<ContractDO, GoshMapper>(sql, mapper, "%s", name);
}

uint64_t GoshDAO::insert(const ContractDO& iObj)
{
	string sql = "INSERT INTO `t_pimcontract` (`name`, `type`, `variety`,`date`,`condition`,`department_m`,`department_c`,`date_end`,`tip`) VALUES (?, ?, ?,?,?,?,?,?,?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s", iObj.getName(), iObj.getType(), iObj.getVariety(), iObj.getDate(), iObj.getCondition(), iObj.getDepartment_m(), iObj.getDepartment_c(), iObj.getDate_end(), iObj.getTip());
}

int GoshDAO::deleteById(std::string id)
{
	string sql = "DELETE FROM `t_pimcontract` WHERE `PIMCONTRACTID`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}