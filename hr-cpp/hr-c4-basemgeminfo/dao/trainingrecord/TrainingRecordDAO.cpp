#include "stdafx.h"
#include "TrainingRecordDAO.h"
#include "TrainingRecordMapper.h"
#include <sstream>
//定义条件解析宏，减少重复代码
#define TRAININGRECORD_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->trmtrianpersonid) { \
	sql << " AND `TRMTRIANPERSONID`=? "; \
	SQLPARAMS_PUSH(params, "s", std::string, query->trmtrianpersonid.getValue("")); \
}
//统计培训的记录数
uint64_t TrainingRecordDAO::count(const TrainingRecordPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `t_trmtrianperson`  ";
	TRAININGRECORD_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
//培训记录分页查询函数
list<TrainingRecordDO> TrainingRecordDAO::selectWithPage(const TrainingRecordPageQuery::Wrapper& query)
{
	stringstream sql;

	sql << "SELECT TRMTRIANPERSONID,PXBJ,TRAINBEGIN,TRAINEND,PXKC,TRMTRAINAGENCYNAME,TRAINRES,FS FROM t_trmtrianperson ";
	TRAININGRECORD_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	TrainingRecordMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<TrainingRecordDO, TrainingRecordMapper>(sqlStr, mapper, params);
}