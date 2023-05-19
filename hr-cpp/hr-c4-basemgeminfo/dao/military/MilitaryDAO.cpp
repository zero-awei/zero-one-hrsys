#include "stdafx.h"
#include "MilitaryDAO.h"
#include "MilitaryMapper.h"

list<MilitaryDO> MilitaryDAO::selectDetail(const MilitaryDetailQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM `t_pimarmycadres` WHERE `PIMARMYCADRESID`=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->PIMARMYCADRESID.getValue(""));
	MilitaryMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MilitaryDO, MilitaryMapper>(sqlStr, mapper, params);
}

int MilitaryDAO::update(const MilitaryDO& uObj)
{
	string sql = "UPDATE `t_pimarmycadres` SET `UPDATEDATE`=?, `PIMARMYCADRESNAME`=?, `FJ`=? ,`CREATEDATE`=? ,`UPDATEMAN`=? ,`ENABLE`=? ,`CREATEMAN`=? ,`FSSJ`=? ,`JLSS`=? ,`JLSPZT`=? ,`JLGLBH`=? ,`JLCZZ`=? ,`TROOPTYPE`=? ,`LEVELTYPE`=? ,`REASON`=? WHERE `PIMARMYCADRESID`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", uObj.get_UPDATEDATE(), uObj.get_PIMARMYCADRESNAME(), uObj.get_FJ(), uObj.get_CREATEDATE(), uObj.get_UPDATEMAN(), uObj.get_ENABLE(), uObj.get_CREATEMAN(), uObj.get_FSSJ(), uObj.get_JLSS(), uObj.get_JLSPZT(), uObj.get_JLGLBH(), uObj.get_JLCZZ(), uObj.get_TROOPTYPE(), uObj.get_LEVELTYPE(), uObj.get_REASON(), uObj.get_PIMARMYCADRESID());
}

list<MilitaryDO> MilitaryDAO::selectWithPage(const MilitaryDownloadQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM `t_pimarmycadres` WHERE `PIMPERSONID`=? LIMIT 5000";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->PIMPERSONID.getValue(""));
	MilitaryMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MilitaryDO, MilitaryMapper>(sqlStr, mapper, params);
}
