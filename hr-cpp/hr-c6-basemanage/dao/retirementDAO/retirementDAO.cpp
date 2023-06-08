#include "stdafx.h"
#include "retirementDAO.h"
#include <sstream>
#include "retirementMapper.h"

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
if (query->idcard) { \
	sql << " AND t_pimperson.ZJHM=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->idcard.getValue("")); \
} \
if (query->organization) { \
	sql << " AND t_pimperson.ORMORGNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->organization.getValue("")); \
} \
if (query->department) { \
	sql << " AND t_pimperson.ORMORGSECTORNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->department.getValue("")); \
} \
if (query->employee_state) { \
	sql << " AND t_pimperson.YGZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->employee_state.getValue("")); \
} \
if (query->work_state) { \
	sql << " AND t_pimperson.ZGZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->work_state.getValue("")); \
} \
/*
if (query->sex) { \
	sql << " AND CZRID=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND PCMTXFPSQNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->age.getValue("")); \
} \
if (query->mailing_address) { \
	sql << " AND POSTALADDRESS=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->mailing_address.getValue("")); \
} \
if (query->retire_address) { \
	sql << " AND BZ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->retire_address.getValue("")); \
} \
if (query->Family_contact) { \
	sql << " AND CHECKSTATUS=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->Family_contact.getValue("")); \
} \
if (query->organization) { \
	sql << " AND ZZ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->organization.getValue("")); \
} \
if (query->department) { \
	sql << " AND BM=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->department.getValue("")); \
} \
if (query->rank) { \
	sql << " AND RANK=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->rank.getValue("")); \
} \
if (query->before_retire_rank) { \
	sql << " AND YZW=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->before_retire_rank.getValue("")); \
} \
if (query->before_retire_post) { \
	sql << " AND YGW=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->before_retire_post.getValue("")); \
} \
if (query->retire_time) { \
	sql << " AND TXDQ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->retire_time.getValue("")); \
} \
if (query->read_retire_time) { \
	sql << " AND FPSXSJ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->read_retire_time.getValue("")); \
} \
if (query->tel) { \
	sql << " AND LXDH=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->tel.getValue("")); \
} \
if (query->Approved_pension_amount) { \
	sql << " AND CHECKSTATUS=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->Approved_pension_amount.getValue("")); \
} \
*/

uint64_t RetirementDAO::count(const RetirementQuery_gan::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) from t_pcmtxfpsq join t_pimperson  on t_pcmtxfpsq.PIMPERSONID = t_pimperson.PIMPERSONID";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
list<retirementDO> RetirementDAO::selectWithPage(const RetirementQuery_gan::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t_pimperson.YGBH,t_pimperson.PIMPERSONNAME,";
	sql << "CASE WHEN t_pimperson.XB = 1 THEN '男' WHEN t_pimperson.XB = 2 THEN '女' ELSE 'null' ";
	sql << "END AS sex,";
	sql << "YEAR (CURDATE()) - YEAR ( `CSRQ` ) - CASE WHEN (MONTH (CURDATE()) < MONTH ( `CSRQ` )) ";
	sql << "OR (MONTH (CURDATE()) = MONTH ( `CSRQ` ) ";
	sql << "AND DAY (CURDATE()) < DAY ( `CSRQ` )) THEN 1 ELSE 0 ";
	sql << "END AS age,";	
	sql << "t_pimperson.POSTALADDRESS,t_pimperson.RETIPLACE,t_pimperson.JTLXR,t_pimperson.JTLXRDH,";
	sql << "t_pimperson.ORMORGNAME,t_pimperson.ORMORGSECTORNAME,t_pimperson.RANK,t_pcmtxfpsq.YZW,";
	sql << "t_pcmtxfpsq.YGW,t_pcmtxfpsq.TXDQ,t_pimperson.SJTXRQ,t_pcmtxfpsq.LXDH,t_pimperson.SPDYLJE ";
	sql << "FROM t_pcmtxfpsq JOIN t_pimperson ON t_pcmtxfpsq.PIMPERSONID = t_pimperson.PIMPERSONID ";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	RetirementMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<retirementDO, RetirementMapper>(sqlStr, mapper, params);
}