#include "stdafx.h"
#include "SciResultDAO.h"
#include "SciResultMapper.h"

//定义条件解析宏，减少重复代码
#define SciResult_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pimpersonid) { \
	sql << " AND `PIMPERSONID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonid.getValue("")); \
}

uint64_t SciResultDAO::count(const SciResultQuery::Wrapper& query)
{
	stringstream sql;
	//这里需要修改
	sql << "SELECT COUNT(*) FROM `t_pimresearchfindings`";
	SciResult_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<SciResultDO> SciResultDAO::selectWithPage(const SciResultQuery::Wrapper& query)
{
	stringstream sql;
	//这里需要修改
	sql << "select UPDATEMAN,PIMRESEARCHFINDINGSNAME,FJ,ENABLE,CREATEDATE,UPDATEDATE,CREATEMAN,PIMRESEARCHFINDINGSID,PIMPERSONID,HQSJ,JLSS,JLSPZT,JLGLBH,JLCZZ,REASON from `t_pimresearchfindings`";
	SciResult_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	SciResultMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<SciResultDO, SciResultMapper>(sqlStr, mapper, params);
}
int SciResultDAO::insert(const SciResultDO& iObj)
{
	string sql = "INSERT INTO `t_pimresearchfindings` (`PIMRESEARCHFINDINGSNAME`, `HQSJ`, `FJ`,`PIMRESEARCHFINDINGSID`,`PIMPERSONID`,`UPDATEDATE`,`CREATEDATE`,`CREATEMAN`,`UPDATEMAN`) VALUES (?, ?, ?, ?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s", iObj.get_PIMRESEARCHFINDINGSNAME(),iObj.get_HQSJ(), iObj.get_FJ(),iObj.get_PIMRESEARCHFINDINGSID(),iObj.get_PIMPERSONID(),iObj.get_UPDATEDATE(),iObj.get_CREATEDATE(),iObj.get_CREATEMAN(), iObj.get_UPDATEMAN());
}
int SciResultDAO::deleteById(std::string pimpersonid, std::string pimsciresultid)
{
	std::string sql = "delete from t_pimresearchfindings where PIMPERSONID=? and PIMRESEARCHFINDINGSID=?";
	return sqlSession->executeUpdate(sql, "%s%s", pimpersonid, pimsciresultid);
}