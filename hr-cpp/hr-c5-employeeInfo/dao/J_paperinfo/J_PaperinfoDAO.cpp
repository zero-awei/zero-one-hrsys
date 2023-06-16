#include "stdafx.h"
#include "J_PaperinfoDAO.h"
#include "J_PaperinfoMapper.h"
#include <sstream>



// 查看指定员工论文信息（指定论文信息详情）
std::list<J_PaperinfoDO> PaperinfoDAO::selectBypimpaperid(const string& st)
{
	//string sql = "SELECT \
	//	GRZLWZZZDPM,\
	//	UPDATEMAN,\
	//	PIMPAPERID,\
	//	CREATEDATE,\
	//	UPDATEDATE,\
	//	CREATEMAN,\
	//	FBSJ,\
	//	PIMPAPERNAME,\
	//	CBSHKWMC,\
	//	PIMPERSONID,\
	//	FJ,\
	//	JLSPZT,\
	//	JLGLBH,\
	//	JLCZZ,\
	//	JLSS,\
	//	CBS,\
	//	KWMC,\
	//	KWQS,\
	//	REASON\
	//	FROM t_pimpaper WHERE 1 = 1 AND PIMPAPERID = ? ";
	string sql = "SELECT CBS,CBSHKWMC,CREATEDATE,CREATEMAN,ENABLE,\
		FBSJ,FJ,GRZLWZZZDPM,JLCZZ,JLGLBH,\
		JLSPZT,JLSS,KWMC,KWQS,ORMORGID AS ORGID,\
		ORMORGSECTORID AS ORGSECTORID,ORMORGID,ORMORGSECTORID,PIMPAPERID,PIMPAPERNAME,\
		PIMPERSONID,PIMPERSONNAME,REASON,UPDATEDATE,UPDATEMAN,\
		YGBH FROM(SELECT b.ENABLE,b.GRZLWZZZDPM,b.UPDATEMAN,b.PIMPAPERID,b.CREATEDATE,\
			b.UPDATEDATE,b.CREATEMAN,b.FBSJ,b.PIMPAPERNAME,b.CBSHKWMC,\
			b.PIMPERSONID,b.FJ,b.JLSPZT,b.JLGLBH,b.JLCZZ,\
			b.JLSS,b.CBS,b.KWMC,b.KWQS,b.REASON,\
			a.ORMORGID,a.ORMORGSECTORID,a.PIMPERSONNAME,a.YGBH\
			FROM t_pimperson a INNER JOIN t_pimpaper b \
			WHERE a.PIMPERSONID = b.PIMPERSONID) e\
		WHERE e.PIMPAPERID = ? ";


	PaperinfoMapper mapper;
	return sqlSession->executeQuery<J_PaperinfoDO, PaperinfoMapper>(sql, mapper, "%s", st);
}


// 修改数据
int PaperinfoDAO::update(const J_PaperinfoDO& uObj)
{
	int CountMark = 0;//标识修改语句使“，”位置正确
	stringstream sql;
	sql << "UPDATE t_pimpaper SET ";
	SqlParams params;

	if (uObj.getPIMPAPERNAME() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " PIMPAPERNAME= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getPIMPAPERNAME());
		CountMark++;
	}
	if (uObj.getCBS() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " CBS= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getCBS());
		CountMark++;
	}
	if (uObj.getKWMC() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " KWMC= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getKWMC());
		CountMark++;
	}
	if (uObj.getKWQS() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " KWQS= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getKWQS());
		CountMark++;
	}
	if (uObj.getFBSJ() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " FBSJ= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getFBSJ());
		CountMark++;
	}
	if (uObj.getGRZLWZZZDPM() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " GRZLWZZZDPM= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getGRZLWZZZDPM());
		CountMark++;
	}
	if (uObj.getFJ() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " FJ= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getFJ());
		CountMark++;
	}
	if (uObj.getPIMPAPERID() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		//获取当前时间
		time_t timep;
		time(&timep);
		char tmp[256];
		strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
		sql << " UPDATEDATE= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, tmp);
		CountMark++;
	}
	if (uObj.getUPDATEMAN() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " UPDATEMAN= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getUPDATEMAN());
		CountMark++;
	}

	if (uObj.getPIMPAPERID() != "string") {
		sql << "WHERE PIMPAPERID = ?";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getPIMPAPERID());
	}
	string sqlStr = sql.str();
	return sqlSession->executeUpdate(sqlStr, params);
}

