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
if(query->id){ \
	sql << " AND `YGBH`LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->name) { \
	sql << " AND `PIMPERSONNAME` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
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
	sql << "SELECT YGBH,PIMPERSONNAME,YGZT,GZZT,GZZZ,GZBM,GZKSSJ,GZJSSJ FROM t_pimperson";
	TEMPSTAFF_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	TempStaffMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<TemporaryStaffDO, TempStaffMapper>(sqlStr, mapper, params);
}

list<TemporaryStaffDO> TemporaryStaffDAO::selectByName(const string& name)
{
	string sql = "SELECT YGBH,PIMPERSONNAME,YGZT,GZZT,GZZZ,GZBM,GZKSSJ,GZJSSJ FROM t_pimperson WHERE `PIMPERSONNAME` LIKE CONCAT('%',?,'%')";
	TempStaffMapper mapper;
	return sqlSession->executeQuery<TemporaryStaffDO, TempStaffMapper>(sql, mapper, "%s", name);
}

list<TemporaryStaffDO> TemporaryStaffDAO::selectById(const string& id)
{
	string sql = "SELECT YGBH,PIMPERSONNAME,YGZT,GZZT,GZZZ,GZBM,GZKSSJ,GZJSSJ FROM t_pimperson WHERE `PIMPERSONNAME` LIKE CONCAT(?,'%')";
	TempStaffMapper mapper;
	return sqlSession->executeQuery<TemporaryStaffDO, TempStaffMapper>(sql, mapper, "%s", id);
}
