#include "stdafx.h"
#include "PaperinfoDAO.h"
#include "PaperinfoMapper.h"
#include <sstream>



// 查看指定员工论文信息（指定论文信息详情）
std::list<t_pimpaperDO> PaperinfoDAO::selectBypimpaperid(const string& st)
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
		FROM t_pimpaper WHERE 1 = 1 AND PIMPAPERID LIKE CONCAT('%', ? , '%')";
	PatentinfoMapper mapper;
	return sqlSession->executeQuery<t_pimpaperDO, PaperinfoMapper>(sql, mapper, "%s", st);
}


// 修改数据
int PaperinfoDAO::update(const t_pimpaperDO& uObj)
{
	int CountReturn = 0;//确定是否返回正确
	int CountMark = 0;//标识修改语句使“，”位置正确
	stringstream sql;
	sql << "UPDATE t_pimpaper SET ";
	SqlParams params;
	if (uObj.getGRZLWZZZDPM() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " GRZLWZZZDPM= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getGRZLWZZZDPM());
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
	if (uObj.getCREATEDATE() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " CREATEDATE= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getCREATEDATE());
		CountMark++;
	}
	if (uObj.getUPDATEDATE() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " UPDATEDATE= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getUPDATEDATE());
		CountMark++;
	}
	if (uObj.getCREATEMAN() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " CREATEMAN= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getCREATEMAN());
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
	if (uObj.getPIMPAPERNAME() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " PIMPAPERNAME= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getPIMPAPERNAME());
		CountMark++;
	}
	if (uObj.getCBSHKWMC() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " CBSHKWMC= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getCBSHKWMC());
		CountMark++;
	}
	if (uObj.getPIMPERSONID() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " PIMPERSONID= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getPIMPERSONID());
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
	if (uObj.getJLSPZT() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " JLSPZT= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getJLSPZT());
		CountMark++;
	}
	if (uObj.getJLGLBH() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " JLGLBH= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getJLGLBH());
		CountMark++;
	}
	if (uObj.getJLCZZ() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " JLCZZ= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getJLCZZ());
		CountMark++;
	}
	if (uObj.getJLSS() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " JLSS= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getJLSS());
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
	if (uObj.getREASON() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " REASON= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getREASON());
		CountMark++;
	}

	if (uObj.getPIMPAPERID() != "string") {
		sql << "WHERE PIMPAPERID = ?";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getPIMPAPERID());
	}
	string sqlStr = sql.str();
	CountReturn += sqlSession->executeUpdate(sqlStr, params);

	if (CountReturn != 0)
		return 1;
	else
		return 0;
}

