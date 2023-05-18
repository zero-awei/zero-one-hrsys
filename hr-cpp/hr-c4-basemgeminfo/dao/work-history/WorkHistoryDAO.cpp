#include "stdafx.h"
#include "WorkHistoryDAO.h"
#include "WorkHistoryMapper.h"

list<WorkHistoryDO> WorkHistoryDAO::selectDetail(const WorkHistoryQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM `t_pimdistirbution` ";
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