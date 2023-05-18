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
if (query->bm) { \
		sql << " AND BM=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->bm.getValue("")); \
}\
if (query->zw) { \
		sql << " AND ZW=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->zw.getValue("")); \
}\
if (query->gw) { \
		sql << " AND GW=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->gw.getValue("")); \
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
	sql << "select RZKSSJ, RZJSSJ, ORMORGNAME, BM,ZW, GW, CFPLX, EXPERIENCE, PIMWORKHISTORYID from `t_pimworkhistory`";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	WorkHistoryMapper mapper;
	std::string sqlStr = sql.str();
	return sqlSession->executeQuery<WorkHistoryFindDO, WorkHistoryMapper>(sqlStr, mapper, params);
}

uint64_t WorkHistoryDAO::count(const WorkHistoryPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimworkhistory";
	SAMPLE_TERAM_PARSE(query, sql);
	std::string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
