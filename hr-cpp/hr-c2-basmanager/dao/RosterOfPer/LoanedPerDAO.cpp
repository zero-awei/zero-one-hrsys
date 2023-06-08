#include "stdafx.h"
#include "LoanedPerDAO.h"
#include "LoanedPerDAO.h"
#include "LoanedPerMapper.h"
#include <sstream>
/**
 * 借调人员数据库操作实现--(人员花名册-借调人员-分页查询员工列表)--luoluo
 */
#define LOANEDPER_TERAM_PARSE(query,sganql)\
SqlParams params; \
sql<<" WHERE 1=1"; \
if(query->idAndName){ \
	sql << " AND person.PIMPERSONNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->idAndName.getValue("")); \
} \
if(query->idAndName){ \
	sql << " OR distir.YGBH=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->idAndName.getValue("")); \
} \
if(query->pimPersonName){ \
	sql << " AND person.PIMPERSONNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimPersonName.getValue("")); \
} \
if(query->ygbh){ \
	sql << " AND distir.YGBH=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ygbh.getValue("")); \
} \
if(query->zz){ \
	sql << " AND distir.YZZ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->zz.getValue("")); \
} \
if(query->bm){ \
	sql << " AND distir.YBM=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->bm.getValue("")); \
} \
if(query->zw){ \
	sql << " AND duty.ORMDUTYNAME YZW=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->zw.getValue("")); \
} \
if(query->gw){ \
	sql << " AND gw.ORMPOSTNAME YGW=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->gw.getValue("")); \
} \
if(query->fp){ \
	sql << " AND distir.FPLX=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->fp.getValue("")); \
} \
if(query->lx){ \
	sql << " AND distir.CFPLX=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->lx.getValue("")); \
} \
if(query->fpzt){ \
	sql << " AND distir.FPZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->fpzt.getValue("")); \
} \


uint64_t LoanedPerDAO::count(const LoanedPerPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*)\
		FROM\
		t_pimperson AS person\
		INNER JOIN t_pimdistirbution AS distir ON person.PIMPERSONID = distir.PIMPERSONID\
		INNER JOIN t_pcmydjdmx AS jdmx ON distir.PIMDISTIRBUTIONID = jdmx.PIMDISTIRBUTIONID\
		INNER JOIN t_ormpost AS gw ON distir.ORMPOSTID = gw.ORMPOSTID\
		INNER JOIN t_ormduty AS duty ON distir.ORMDUTYID = duty.ORMDUTYID";

	LOANEDPER_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}


list<SecondedPersonnelDO> LoanedPerDAO::selectWithPage(const LoanedPerPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT\
		distir.PIMDISTIRBUTIONID,\
		person.PIMPERSONNAME,\
		distir.YGBH,\
		distir.YZZ,\
		distir.YBM,\
		duty.ORMDUTYNAME YZW,\
		gw.ORMPOSTNAME YGW,\
		distir.ORMORGNAME XZZ,\
		distir.ORMORGSECTORNAME XBM,\
		distir.ORMDUTYNAME XZW,\
		distir.ORMPOSTNAME XGW,\
		distir.YDZT,\
		jdmx.JDJSRQ,\
		jdmx.JDKSRQ \
		FROM\
		t_pimperson AS person\
		INNER JOIN t_pimdistirbution AS distir ON person.PIMPERSONID = distir.PIMPERSONID\
		INNER JOIN t_pcmydjdmx AS jdmx ON distir.PIMDISTIRBUTIONID = jdmx.PIMDISTIRBUTIONID\
		INNER JOIN t_ormpost AS gw ON distir.ORMPOSTID = gw.ORMPOSTID\
		INNER JOIN t_ormduty AS duty ON distir.ORMDUTYID = duty.ORMDUTYID";

	LOANEDPER_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LoanedPerMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<SecondedPersonnelDO, LoanedPerMapper>(sqlStr, mapper, params);
}

list<SecondedPersonnelDO> LoanedPerDAO::selectExportDatas(const LoanedPerPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT\
		distir.PIMDISTIRBUTIONID,\
		person.PIMPERSONNAME,\
		distir.YGBH,\
		distir.YZZ,\
		distir.YBM,\
		duty.ORMDUTYNAME YZW,\
		gw.ORMPOSTNAME YGW,\
		distir.ORMORGNAME XZZ,\
		distir.ORMORGSECTORNAME XBM,\
		distir.ORMDUTYNAME XZW,\
		distir.ORMPOSTNAME XGW,\
		distir.YDZT,\
		jdmx.JDJSRQ,\
		jdmx.JDKSRQ \
		FROM\
		t_pimperson AS person\
		INNER JOIN t_pimdistirbution AS distir ON person.PIMPERSONID = distir.PIMPERSONID\
		INNER JOIN t_pcmydjdmx AS jdmx ON distir.PIMDISTIRBUTIONID = jdmx.PIMDISTIRBUTIONID\
		INNER JOIN t_ormpost AS gw ON distir.ORMPOSTID = gw.ORMPOSTID\
		INNER JOIN t_ormduty AS duty ON distir.ORMDUTYID = duty.ORMDUTYID";
	LOANEDPER_TERAM_PARSE(query, sql);
	sql << " LIMIT 5000";
	LoanedPerMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<SecondedPersonnelDO, LoanedPerMapper>(sqlStr, mapper, params);
}

