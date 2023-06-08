/*
人员花名册-离退休人员-分页查询员工列表--pine
*/
#include "stdafx.h"
#include "CheckRetiresListDAO.h"
#include "CheckRetiresListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define CERLIST_TERAM_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->idAndName) { \
    sql << " AND t2.ygbh=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->idAndName.getValue("")); \
} \
if (query->idAndName) { \
    sql << " OR t2.pimpersonname=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->idAndName.getValue("")); \
} \
if (query->ygbh) { \
    sql << " AND t2.ygbh = ?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->ygbh.getValue("")); \
} \
if (query->pimpersonname) { \
    sql << " AND t2.pimpersonname = ?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonname.getValue("")); \
}

uint64_t CheckRetiresListDAO::count(const CheckRetiresListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) \
			FROM t_pcmydmx t1\
			LEFT JOIN t_pimperson t2\
			ON t1.PIMPERSONID = t2.PIMPERSONID";

	CERLIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<RetiredEmployeesDO> CheckRetiresListDAO::selectWithPage(const CheckRetiresListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT \
			t2.ygbh,\
			t2.pimpersonname,\
			t2.xb,\
			t3.nj,\
			t2.postaladdress,\
			t2.retiPlace,\
			t2.jtlxr,\
			t2.jtlxrdh,\
			t2.zz,\
			t2.bm,\
			t2.`RANK`,\
			t1.yzw,\
			t1.ygw,\
			t2.txdq,\
			t2.sjtxrq,\
			t2.lxdh,\
			t2.spdylje,\
			t2.pimpersonid\
			FROM\
			t_pimperson t2\
			LEFT JOIN t_pcmydmx t1 ON t1.PIMPERSONID = t2.PIMPERSONID\
			LEFT JOIN t_trmhmatser t3 ON t3.PIMPERSONID = t2.PIMPERSONID";

	CERLIST_TERAM_PARSE(query, sql);

	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;

	CheckRetiresListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<RetiredEmployeesDO, CheckRetiresListMapper>(sqlStr, mapper, params);
}

/*
 + t_pimperson t2 +t_pcmydmx t1
2人员信息
1退休异动
3 t_trmhmatser引入年龄字段
*/