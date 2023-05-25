#include "stdafx.h"
#include "WorkHistoryDAO.h"
#include "WorkHistoryMapper.h"

//
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->rzkssj) { \
	sql << " AND `RZKSSJ`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->rzkssj.getValue("")); \
} \
if (query->rzjssj) { \
	sql << " AND RZJSSJ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->rzjssj.getValue("")); \
} \
if (query->ormorgname) { \
	sql << " AND ORMORGNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ormorgname.getValue("")); \
} \
if (query->ormorgsectorname) { \
		sql << " AND ORMORGSECTORNAME=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->ormorgsectorname.getValue("")); \
}\
if (query->ormdutyname) { \
		sql << " AND ORMDUTYNAME=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->ormdutyname.getValue("")); \
}\
if (query->ormpostname) { \
		sql << " AND ORMPOSTNAME=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->ormpostname.getValue("")); \
}\
if (query->cfplx) { \
		sql << " AND CFPLX=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->cfplx.getValue("")); \
}\
if (query->experience) { \
		sql << " AND EXPERIENCE=?"; \
		SQLPARAMS_PUSH(params, "i", int, query->experience.getValue(0)); \
}\
if (query->pimpersonid) { \
		sql << " AND PIMPERSONID=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonid.getValue("")); \
}
/*
if (query->pimworkhistoryid) {
	\
		sql << " AND PIMWORKHISTORYID=?"; \
		SQLPARAMS_PUSH(params, "i", std::string, query->pimworkhistoryid.getValue(0)); \
}\*/









std::list<WorkHistoryFindDO> WorkHistoryDAO::selectWithPage(const WorkHistoryPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select RZKSSJ, RZJSSJ, ORMORGNAME, ORMORGSECTORNAME, \
		ORMDUTYNAME, ORMPOSTNAME, CFPLX, EXPERIENCE, PIMWORKHISTORYID, PIMPERSONID from `t_pimworkhistory`";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	WorkHistoryPageMapper mapper;
	std::string sqlStr = sql.str();
	return sqlSession->executeQuery<WorkHistoryFindDO, WorkHistoryPageMapper>(sqlStr, mapper, params);
}

uint64_t WorkHistoryDAO::count(const WorkHistoryPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimworkhistory";
	SAMPLE_TERAM_PARSE(query, sql);
	std::string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<WorkHistoryDO> WorkHistoryDAO::selectDetail(const WorkHistoryQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select rzkssj,rzjssj,ormorgname,ormorgsectorname,ormdutyname,ormpostname,cfplx,experience,enable from t_pimdistirbution ";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->ormorgname.getValue(""));
	WorkHistoryMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<WorkHistoryDO, WorkHistoryMapper>(sqlStr, mapper, params);
}

int WorkHistoryDAO::update(const WorkHistoryDO& uObj)
{
	string sql = "UPDATE `t_pimdistirbution` SET `rzkssj`=?, `rzjssj`=?, `ormorgname`=? ,`ormdutyname`=? ,`ormpostname`=? ,`cfplx`=? ,`enable`=? WHERE `ormorgname`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", uObj.getRzkssj(), uObj.getRzjssj(), uObj.getOrmorgname(), uObj.getOrmdutyname(), uObj.getOrmpostname(), uObj.getCfplx(), uObj.getEnable());
}