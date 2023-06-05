#include "stdafx.h"
#include "GoshDAO.h"
#include "GoshMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->personid) { \
	sql << " AND t_pimcontract.`PIMPERSONID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->personid.getValue("")); \
} \
if (query->name) { \
	sql << " AND t_pimperson.`PIMPERSONNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->person_condition) { \
	sql << " AND t_pimperson.YGZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->person_condition.getValue("")); \
}\
if (query->id) { \
	sql << " AND t_pimcontract.PIMCONTRACTID=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
}\
if (query->type) { \
	sql << " AND t_pimcontract.HTLX=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->type.getValue("")); \
}\
if (query->condition) { \
	sql << " AND t_pimcontract.HTZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->condition.getValue("")); \
}\
if (query->date) { \
	sql << " AND t_pimcontract.QSRQ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->date.getValue("")); \
}\
if (query->date_over) { \
	sql << " AND t_pimcontract.JSRQ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->date_over.getValue("")); \
}\
if (query->variety) { \
	sql << " AND t_pimcontract.CONTRACTTYPE=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->variety.getValue("")); \
}


uint64_t GoshDAO::count(const ContractQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimcontract join t_pimperson on t_pimcontract.`PIMPERSONID`=t_pimperson.`PIMPERSONID`";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ContractDO> GoshDAO::selectWithPage(const ContractQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t_pimcontract.`PIMPERSONID`,t_pimcontract.`PIMCONTRACTID`,t_pimperson.`PIMPERSONNAME`,t_pimcontract.`HTLX`,";
	sql << "t_pimcontract.`CONTRACTTYPE`,t_pimcontract.`QSRQ`,t_pimcontract.`HTZT`,t_pimcontract.`LEGALORG`,t_pimcontract.`SYDQSJ`,t_pimcontract.`ORMORGNAME`,";
	sql << "t_pimperson.`YGZT`,t_pimperson.`DBDWSJ`,t_pimcontract.`JSRQ`,DATEDIFF(t_pimcontract.`QSRQ`,t_pimcontract.`JSRQ`) as rest ";
	sql << "FROM `t_pimcontract` inner join `t_pimperson` on t_pimcontract.`PIMPERSONID`=t_pimperson.`PIMPERSONID`";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GoshMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ContractDO, GoshMapper>(sqlStr, mapper, params);
}

std::list<ContractDO> GoshDAO::selectByName(const string& name)
{
	//1、员工编号2、合同编号3、员工姓名4、合同类别5、合同类型6、起始日期7、合同状态8、合同签订单位9、试用到期时间10、员工所属单位
	//11、员工状态12、到本单位时间13、结束日期14、合同剩余天数——均为前端页面要显示字段
	string sql = "SELECT t_pimcontract.`PIMPERSONID`,t_pimcontract.`PIMCONTRACTID`,t_pimperson.`PIMPERSONNAME`,t_pimcontract.`HTLX`,\
	t_pimcontract.`CONTRACTTYPE`,t_pimcontract.`QSRQ`,t_pimcontract.`HTZT`,t_pimcontract.`LEGALORG`,t_pimcontract.`SYDQSJ`,t_pimcontract.`ORMORGNAME`,\
	t_pimperson.`YGZT`,t_pimperson.`DBDWSJ`,t_pimcontract.`JSRQ`,DATEDIFF(t_pimcontract.`QSRQ`,t_pimcontract.`JSRQ`) as rest\
	FROM `t_pimcontract` inner join `t_pimperson` on t_pimperson.`PIMPERSONNAME` like CONCAT('%',?,'%')\
	limit 5;";
	GoshMapper mapper;
	return sqlSession->executeQuery<ContractDO, GoshMapper>(sql, mapper, "%s",name);
}

uint64_t GoshDAO::insert(const ContractDO& iObj)
{
	//设置t_srforg表中的主键，因为t_pimcontract与其有外键关联
	string sll = "INSERT INTO t_srforg(ORGID)VALUES(?);";
	sqlSession->executeInsert(sll, "%s", iObj.getDepartment_m());
	//设置t_pimperson中的主键，因为t_pimcontract与其有外键关联
	string sml = "INSERT INTO t_pimperson(`PIMPERSONID`) VALUES(?)";
	sqlSession->executeInsert(sml, "%s", iObj.getPersonid());
	//向t_pimcontract中插入从前端读取的值
	int a=3;
	string sql = "INSERT INTO t_pimcontract(`PIMPERSONID`,`PIMCONTRACTID`,`HTLX`,`CONTRACTTYPE`,`QSRQ`,`HTZT`,`ORMORGID`,`SYDQSJ`,`DEMO`) VALUES ( ?,?,?,?,?,?,?,?,?);";
	a = 3;
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s", iObj.getPersonid(),iObj.getId(), iObj.getType(), iObj.getVariety(), iObj.getDate(), iObj.getCondition(), iObj.getDepartment_m(), iObj.getDate_end(), iObj.getTip());
}

int GoshDAO::deleteById(std::string id)
{
	string sql = "DELETE FROM `t_pimcontract` WHERE `PIMCONTRACTID`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}