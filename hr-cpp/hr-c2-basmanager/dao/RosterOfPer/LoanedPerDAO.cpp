#include "stdafx.h"
#include "LoanedPerDAO.h"
#include "LoanedPerDAO.h"
#include "LoanedPerMapper.h"
#include <sstream>

#define LOANEDPER_TERAM_PARSE(query,sql)\
SqlParams params; \
sql<<" WHERE 1=1"; \
if(query->idAndName){ \
	sql << " AND `distir.YGBH`=？"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if(query->name){ \
	sql << " OR `person.PIMPERSONNAME`=？"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if(query->id){ \
	sql << " OR `person.PIMPERSONNAME`=？"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if(query->zz){ \
	sql << " OR `person.PIMPERSONNAME`=？"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if(query->bm){ \
	sql << " OR `person.PIMPERSONNAME`=？"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if(query->zw){ \
	sql << " OR `person.PIMPERSONNAME`=？"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if(query->gw){ \
	sql << " OR `person.PIMPERSONNAME`=？"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if(query->fp){ \
	sql << " OR `person.PIMPERSONNAME`=？"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if(query->lx){ \
	sql << " OR `person.PIMPERSONNAME`=？"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if(query->fpzt){ \
	sql << " OR `person.PIMPERSONNAME`=？"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \

uint64_t LoanedPerDAO::count(const LoanedPerPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimdistirbution";

	LOANEDPER_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//查询语句有问题
list<SecondedPersonnelDO> LoanedPerDAO::selectWithPage(const LoanedPerPageQuery::Wrapper& query)
{
	//stringstream sql;
	//sql<< "	SELECT"
	//	<< "person.PIMPERSONNAME,distir.YGBH,distir.YZZ,distir.YBM,duty.ORMDUTYNAME,gw.ORMPOSTNAME,distir.ORMORGNAME,"
	//	<< "distir.ORMORGSECTORNAME,distir.ORMPOSTNAME,distir.YDZT,jdmx.JDJSRQ,jdmx.JDKSRQ"
	//	<< "FROM"
	//	<< "t_pimperson AS person"
	//	<< "INNER JOIN t_pimdistirbution AS distir ON person.PIMPERSONID = distir.PIMPERSONID"
	//	<< "INNER JOIN t_pcmydjdmx AS jdmx ON distir.PIMDISTIRBUTIONID = jdmx.PIMDISTIRBUTIONID"
	//	<< "INNER JOIN t_ormpost AS gw ON distir.ORMPOSTID = gw.ORMPOSTID"
	//	<< "INNER JOIN t_ormduty AS duty ON distir.ORMDUTYID = duty.ORMDUTYID"

	//LOANEDPER_TERAM_PARSE(query, sql);
	//sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	//LoanedPerMapper mapper;
	//string sqlStr = sql.str();
	//return sqlSession->executeQuery<SecondedPersonnelDO, LoanedPerMapper>(sqlStr, mapper, params);
	//list<SecondedPersonnelDO> temp;
	return list<SecondedPersonnelDO>();
}

