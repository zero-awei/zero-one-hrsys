#include "stdafx.h"
#include "WorkHistoryDAO.h"
#include "WorkHistoryMapper.h"
#include "domain/do/work-history/DelWorkHistoryDO.h"
#include"domain/do/work-history/WorkHistoryDO.h"


//
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->rzkssj) { \
	sql << " AND `RZKSSJ`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->rzkssj.getValue("")); \
} \
if (query->rzjssj) { \
	sql << " AND RZJSSJ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->rzjssj.getValue("")); \
} \
if (query->ormorgname) { \
	sql << " AND ORMORGNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ormorgname.getValue("")); \
} \
if (query->ormorgsectorname) { \
		sql << " AND ORMORGSECTORNAME=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->ormorgsectorname.getValue("")); \
}\
if (query->ormdutyname) { \
		sql << " AND ORMDUTYNAME=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->ormdutyname.getValue("")); \
}\
if (query->ormpostname) { \
		sql << " AND ORMPOSTNAME=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->ormpostname.getValue("")); \
}\
if (query->cfplx) { \
		sql << " AND CFPLX=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->cfplx.getValue("")); \
}\
if (query->experience) { \
		sql << " AND EXPERIENCE=?"; \
		SQLPARAMS_PUSH(params, "i", uint64_t, query->experience.getValue(0)); \
}\
if (query->pimpersonid) { \
		sql << " AND PIMPERSONID=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonid.getValue("")); \
}\
if (query->pimworkhistoryid) {\
		sql << " AND PIMWORKHISTORYID=?"; \
		SQLPARAMS_PUSH(params, "i", std::string, query->pimworkhistoryid.getValue(0)); \
}\









std::list<WorkHistoryFindDO> WorkHistoryDAO::selectWithPage(const WorkHistoryPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select RZKSSJ, RZJSSJ, ORMORGNAME, ORMORGSECTORNAME, \
		ORMDUTYNAME, ORMPOSTNAME, CFPLX, EXPERIENCE, PIMWORKHISTORYID, PIMPERSONID from `t_pimworkhistory`";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	WorkHistoryPageMapper mapper;
	std::string sqlStr = sql.str();	
	return sqlSession->executeQuery<WorkHistoryFindDO, WorkHistoryPageMapper>(sqlStr, mapper, params);
}

uint64_t WorkHistoryDAO::count(const WorkHistoryPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimworkhistory";
	SAMPLE_TERAM_PARSE(query, sql);
	std::string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

uint64_t WorkHistoryDAO::insert(const AddWorkHistoryDO& iObj)
{
	std::string sql = "INSERT INTO `t_pimworkhistory` \
		(`RZKSSJ`, `RZJSSJ`, `ORMORGNAME`, ORMORGSECTORNAME,\
		ORMDUTYNAME, ORMPOSTNAME, CFPLX, EXPERIENCE,PIMWORKHISTORYID,\
		PIMPERSONID,CREATEDATE,UPDATEDATE, CREATEMAN, UPDATEMAN) VALUES \
		(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%s%s%s%s%s%s", iObj.getrZKSSJ(), iObj.getrZJSSJ() \
		, iObj.getoRMORGNAME(), iObj.getoRMORGSECTORNAME(), iObj.getoRMDUTYNAME(), iObj.getoRMPOSTNAME(), \
		iObj.getcFPLX(), iObj.geteXPERIENCE(), iObj.getpIMWORKHISTORYID(), iObj.getpIMPERSONID(), \
	    iObj.getcREATEDATE(), iObj.getuPDATEDATE(), iObj.getcREATEMAN(), iObj.getuPDATEMAN() );
}

int WorkHistoryDAO::deleteById(std::string pimpersonid, std::string pimworkhistoryid)
{
	std::string sql = "delete from t_pimworkhistory where PIMPERSONID=? and PIMWORKHISTORYID=?";
	return sqlSession->executeUpdate(sql, "%s%s", pimpersonid, pimworkhistoryid);
}

std::list<WorkHistoryFindDO> WorkHistoryDAO::selectAllData(const WorkHistoryExportQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select RZKSSJ, RZJSSJ, ORMORGNAME, ORMORGSECTORNAME, \
		ORMDUTYNAME, ORMPOSTNAME, CFPLX, EXPERIENCE, PIMWORKHISTORYID, PIMPERSONID from `t_pimworkhistory`";
	SAMPLE_TERAM_PARSE(query, sql);
	WorkHistoryPageMapper mapper;
	std::string sqlStr = sql.str();
	return sqlSession->executeQuery<WorkHistoryFindDO, WorkHistoryPageMapper>(sqlStr, mapper, params);
}









list<WorkHistoryDO> WorkHistoryDAO::selectDetail(const WorkHistoryQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select rzkssj,rzjssj,ormorgname,ormorgsectorname,ormdutyname,ormpostname,cfplx,experience,pimpersonid,updatedate,updateman,pimworkhistoryid from `t_pimworkhistory` WHERE `pimworkhistoryid`=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->pimworkhistoryid.getValue(""));
	
	WorkHistoryMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<WorkHistoryDO, WorkHistoryMapper>(sqlStr, mapper, params);
}

int WorkHistoryDAO::update(const ModWorkHistoryDO& uObj)
{
	string sql = "UPDATE `t_pimworkhistory` SET rzkssj=?,rzjssj=?,ormorgname=?,ormorgsectorname=?,ormdutyname=?,ormpostname=?,cfplx=?,experience=?,updatedate=?,updateman=? WHERE pimworkhistoryid=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%s%s%s", uObj.getRzkssj(), uObj.getRzjssj(), uObj.getOrmorgname(), uObj.getOrmorgsectorname(), uObj.getOrmdutyname(), uObj.getOrmpostname(), uObj.getCfplx(), uObj.getExperience(),uObj.getUpdatedate(),uObj.getUpdateman(), uObj.getPimworkhistoryid());
}