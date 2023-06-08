#include "stdafx.h"
#include "ScientificDAO.h"
#include "ScientificMapper.h"

list<ScientificDO> ScientificDAO::selectDetail(const ScientificViewQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM `t_pimresearchfindings` WHERE `PIMRESEARCHFINDINGSID`=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->pimresearchfindingsid.getValue(""));
	ScientificMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ScientificDO, ScientificMapper>(sqlStr, mapper, params);
}

int ScientificDAO::update(const ScientificDO& uObj)
{
	string sql = "UPDATE `t_pimresearchfindings` SET `UPDATEMAN`=?, `PIMRESEARCHFINDINGSNAME`=?, `FJ`=? ,`ENABLE`=? ,`CREATEDATE`=? ,`PIMRESEARCHFINDINGSID`=? ,`PIMPERSONID`=? ,`HQSJ`=? ,`JLSS`=? ,`JLSPZT`=? ,`JLGLBH`=? ,`JLCZZ`=? ,`REASON`=? WHERE `PIMRESEARCHFINDINGSID`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", uObj.getUpdateman(), uObj.getPimresearchfindingsname(), uObj.getFj(), uObj.getEnable(), uObj.getCreatedate(), uObj.getUpdatedate(), uObj.getCreateman(), uObj.getPimresearchfindingsid(), uObj.getPimpersonid(), uObj.getHqsj(), uObj.getJlss(), uObj.getJlglbh(), uObj.getJlczz(), uObj.getReason(), uObj.getPimresearchfindingsid());
}

list<ScientificDO> ScientificDAO::selectWithPage(const ScientificDownloadQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM `t_pimresearchfindings` WHERE `PIMPERSONID`=? LIMIT 5000";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonid.getValue(""));
	ScientificMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ScientificDO, ScientificMapper>(sqlStr, mapper, params);
}
