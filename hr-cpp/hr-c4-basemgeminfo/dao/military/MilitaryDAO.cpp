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
