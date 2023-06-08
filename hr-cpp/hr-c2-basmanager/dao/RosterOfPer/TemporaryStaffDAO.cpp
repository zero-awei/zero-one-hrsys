#include "stdafx.h"
#include "TemporaryStaffDAO.h"
#include "TemporaryStaffMapper.h"
#include <sstream>
/**
 * 挂职人员数据库操作实现--(人员花名册-挂职人员-分页查询员工列表)--weixiaoman
 */

//定义条件解析宏
#define TEMPSTAFF_TERAM_PARSE(query,sql)\
SqlParams params; \
sql<<" WHERE 1=1"; \
if(query->idandname){ \
	sql << " AND `YGBH`LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->idandname.getValue("")); \
} \
if (query->idandname) { \
	sql << " OR `PIMPERSONNAME` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->idandname.getValue("")); \
} 

//sql << "SELECT YGBH,PIMPERSONNAME,YGZT,GZZT,GZZZ,GZBM,GZKSSJ,GZJSSJ FROM t_pimperson";

uint64_t TemporaryStaffDAO::count(const TempStaffQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimperson";
	
	TEMPSTAFF_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<TemporaryStaffDO> TemporaryStaffDAO::selectWithPage(const TempStaffQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT YGBH,PIMPERSONNAME,YGZT,GZZT,GZZZ,GZBM,GZKSSJ,GZJSSJ,PIMPERSONID FROM t_pimperson";
	TEMPSTAFF_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	TempStaffMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<TemporaryStaffDO, TempStaffMapper>(sqlStr, mapper, params);
}

list<TemporaryStaffDO> TemporaryStaffDAO::selectExportDatas(const TempStaffQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT YGBH,PIMPERSONNAME,YGZT,GZZT,GZZZ,GZBM,GZKSSJ,GZJSSJ,PIMPERSONID FROM t_pimperson";
	TEMPSTAFF_TERAM_PARSE(query, sql);
	sql << " LIMIT 5000";
	TempStaffMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<TemporaryStaffDO, TempStaffMapper>(sqlStr, mapper, params);
}
