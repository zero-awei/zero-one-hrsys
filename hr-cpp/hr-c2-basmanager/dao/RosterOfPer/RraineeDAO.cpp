#include "stdafx.h"
#include "RraineeDAO.h"
#include "RraineeMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->ygbh) { \
	sql << " AND ygbh=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ygbh.getValue("")); \
} \
if (query->pcmjxszzkhjgjlname) { \
	sql << " AND pcmjxszzkhjgjlname=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pcmjxszzkhjgjlname.getValue("")); \
} \
if (query->zz) { \
	sql << " AND zz=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->zz.getValue("")); \
} \
if (query->bm) { \
	sql << " AND bm=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->bm.getValue("")); \
} \
if (query->zw) { \
	sql << " AND zw=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->zw.getValue("")); \
} \
if (query->gw) { \
	sql << " AND gw=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->gw.getValue("")); \
} \
if (query->duration) { \
	sql << " AND duration=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->duration.getValue("")); \
} \
if (query->ksrq) { \
	sql << " AND ksrq=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ksrq.getValue("")); \
} \
if (query->jsrq) { \
	sql << " AND jsrq=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->jsrq.getValue("")); \
} \

uint64_t RraineeDAO::count(const RraineeQuery::Wrapper& query) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pcmjxsbdjl";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<RraineeDO> RraineeDAO::selectWithPage(const RraineeQuery::Wrapper& query) {
	stringstream sql;
	//sql << "SELECT ygbh, Pcmjxszzkhjgjlname, Zz, Bm, Zw, Gw, Duration, Ksrq, Jsrq From t_pcmjxszzkhjgjl, t_pcmjxsbdjl, t_pcmjxsgz, t_pcmjxsygzzsqmx";
	sql << "SELECT * From t_pcmjxsbdjl";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	RraineeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<RraineeDO, RraineeMapper>(sqlStr, mapper, params);
}
