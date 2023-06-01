#include "stdafx.h"
#include "PaperinfoDAO.h"
#include "PaperinfoMapper.h"
#include <sstream>



// 查看指定员工论文信息（指定论文信息详情）
std::list<PaperinfoDO> PaperinfoDAO::selectBypimpaperid(const string& st)
{
	string sql = "SELECT \
		GRZLWZZZDPM,\
		UPDATEMAN,\
		PIMPAPERID,\
		CREATEDATE,\
		UPDATEDATE,\
		CREATEMAN,\
		FBSJ,\
		PIMPAPERNAME,\
		CBSHKWMC,\
		PIMPERSONID,\
		FJ,\
		JLSPZT,\
		JLGLBH,\
		JLCZZ,\
		JLSS,\
		CBS,\
		KWMC,\
		KWQS,\
		REASON\
		FROM t_pimpaper WHERE 1 = 1 AND PIMPAPERID = ? ";
	PaperinfoMapper mapper;
	return sqlSession->executeQuery<PaperinfoDO, PaperinfoMapper>(sql, mapper, "%s", st);
}


// 修改数据
int PaperinfoDAO::update(const PaperinfoDO& uObj)
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
		sql << "WHERE PIMPAPERID = ?";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getPIMPAPERID());
	}
	string sqlStr = sql.str();
	return sqlSession->executeUpdate(sqlStr, params);
}

