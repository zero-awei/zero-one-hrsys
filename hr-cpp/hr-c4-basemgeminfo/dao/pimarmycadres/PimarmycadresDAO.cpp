#include "stdafx.h"
#include "PimarmycadresDAO.h"
#include "PimarmycadresMapper.h"
#include "../hr-c4-basemgeminfo/domain/do/pimarmycadres/PimarmycadresFindDO.h"

#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pimid) { \
	sql << " AND  `PIMPERSONID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimid.getValue("")); \
} \
if (query->form) { \
	sql << " AND `TROOPTYPE`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->form.getValue("")); \
} \
if (query->level) { \
	sql << " AND `LEVELTYPE`=?"; \
	SQLPARAMS_PUSH(params, "i", std::string, query->level.getValue(0)); \
}\
if (query->occurtime) { \
		sql << " AND `FSSJ`=?"; \
		SQLPARAMS_PUSH(params, "i", std::string, query->occurtime.getValue(0)); \
}\
if (query->annexPath) { \
	sql << " AND `FJ`=?"; \
	SQLPARAMS_PUSH(params, "i", std::string, query->annexPath.getValue(0)); \
}
;

std::list<PimarmycadresFindDO> PimarmycadresDAO::selectWithPage(const PimarmycadresPageQuery::Wrapper & query)
{
	stringstream sql;	
	sql << "SELECT * FROM `t_pimarmycadres`";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	PimarmycadresPageMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PimarmycadresFindDO, PimarmycadresPageMapper>(sqlStr, mapper, params);
}

uint64_t PimarmycadresDAO::insert(const AddPimarmycadresDO& iObj)
{
	string sql = "INSERT INTO `t_pimarmycadres` (`PIMPERSONID`, `TROOPTYPE`, `LEVELTYPE`,`FSSJ`,`FJ`,`PIMARMYCADRESID`) VALUES (?, ?, ? ,? ,? ,? )";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s", iObj.getpIMID(), 
		iObj.getfORM(), iObj.getlEVEL(),iObj.getoCCURTIME(),iObj.getaNNEXPATH(),iObj.getpIMARMYCADRESID());
}

uint64_t PimarmycadresDAO::count(const PimarmycadresPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimarmycadres";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	cout << sqlStr << endl;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
	
list<PimarmycadresFindDO> PimarmycadresDAO::selectDetail(const PimarmycadresQuery::Wrapper& query)
{
	return list<PimarmycadresFindDO>();
}

int PimarmycadresDAO::update(const PimarmycadresDO& uObj)
{
	string sql = "UPDATE `t_pimarmycadres` SET `PIMPERSONID`=?, `TROOPTYPE`=?, `LEVELTYPE`=? ,`FSSJ`=?,`FJ`=?, WHERE `PIMARMYCADRESID`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getPimid(),
		uObj.getForm(), uObj.getLevel(), uObj.getOccurtime(), uObj.getAnnexPath(),uObj.getPimarmycadresid());
}

int PimarmycadresDAO::deleteById(std::string pimpersonid, std::string pimarmycadresid)
{
	string sql = "DELETE FROM `t_pimarmycadres` WHERE `PIMARMYCADRESID`=? OR `PIMPERSONID`=?";
	return sqlSession->executeUpdate(sql, "%s%s", pimarmycadresid,pimpersonid);
}



