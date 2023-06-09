#include "stdafx.h"
#include "J_PatentinfoDAO.h"
#include "J_PatentinfoMapper.h"
#include <sstream>



// 查看指定员工专利信息（指定专利信息详情）
std::list<J_PatentinfoDO> PatentinfoDAO::selectByPIMPATENTID(const string& pimpatentid)
{

	//string sql = "SELECT ZLH,UPDATEDATE,PIMPATENTID,ZLHQSJ,PIMPATENTNAME,\
	//				UPDATEMAN,CREATEMAN,CREATEDATE,ZLPZGB,PIMPERSONID,\
	//				JLSS,JLSPZT,JLGLBH,JLCZZ,ENCLOLURE,\
	//				REASON\
	//	FROM t_pimpatent WHERE 1 = 1 AND PIMPATENTID = ? ";


	string sql = "SELECT CREATEDATE,CREATEMAN,ENABLE,ENCLOLURE,JLCZZ,\
		JLGLBH,JLSPZT,JLSS,ORMORGID AS ORGID,ORMORGSECTORID AS ORGSECTORID,\
		ORMORGID,ORMORGSECTORID,PIMPATENTID,PIMPATENTNAME,PIMPERSONID,\
		PIMPERSONNAME,REASON,UPDATEDATE,UPDATEMAN,YGBH,\
		ZLH,ZLHQSJ,ZLPZGB\
		FROM(SELECT b.ENABLE, b.ZLH, b.UPDATEDATE, b.PIMPATENTID, b.ZLHQSJ, \
			b.PIMPATENTNAME,b.UPDATEMAN,b.CREATEMAN,b.CREATEDATE,b.ZLPZGB,\
			b.PIMPERSONID,b.JLSS,b.JLSPZT,b.JLGLBH,b.JLCZZ,\
			b.ENCLOLURE,b.REASON,a.ORMORGID,a.ORMORGSECTORID,a.PIMPERSONNAME,\
			a.YGBH FROM t_pimperson a INNER JOIN t_pimpatent b WHERE a.PIMPERSONID = b.PIMPERSONID) e\
		WHERE e.PIMPATENTID = ?";




	PatentinfoMapper mapper;
	return sqlSession->executeQuery<J_PatentinfoDO, PatentinfoMapper>(sql, mapper, "%s", pimpatentid);
}


// 修改数据
int PatentinfoDAO::update(const J_PatentinfoDO& uObj)
{
	//int CountReturn = 0;//确定是否返回正确
	//int CountMark = 0;//标识修改语句使“，”位置正确
	//stringstream sql;
	//sql << "UPDATE t_pimpatent SET ";
	//SqlParams params; 
	//if (uObj.getZLH() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " ZLH= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getZLH()); 
	//	CountMark++;
	//}
	//if (uObj.getUPDATEDATE() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " UPDATEDATE= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getUPDATEDATE());
	//	CountMark++;
	//}
	//if (uObj.getZLHQSJ() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " ZLHQSJ= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getZLHQSJ());
	//	CountMark++;
	//}
	//if (uObj.getPIMPATENTNAME() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " PIMPATENTNAME= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getPIMPATENTNAME());
	//	CountMark++;
	//}
	//if (uObj.getUPDATEMAN() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " UPDATEMAN= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getUPDATEMAN());
	//	CountMark++;
	//}
	//if (uObj.getCREATEMAN() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " CREATEMAN= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getCREATEMAN());
	//	CountMark++;
	//}
	//if (uObj.getCREATEDATE() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " CREATEDATE= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getCREATEDATE());
	//	CountMark++;
	//}
	//if (uObj.getZLPZGB() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " ZLPZGB= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getZLPZGB());
	//	CountMark++;
	//}
	//if (uObj.getPIMPERSONID() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " PIMPERSONID= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getPIMPERSONID());
	//	CountMark++;
	//}
	//if (uObj.getJLSS() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " JLSS= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getJLSS());
	//	CountMark++;
	//}
	//if (uObj.getJLSPZT() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " JLSPZT= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getJLSPZT());
	//	CountMark++;
	//}
	//if (uObj.getJLGLBH() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " JLGLBH= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getJLGLBH());
	//	CountMark++;
	//}
	//if (uObj.getJLCZZ() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " JLCZZ= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getJLCZZ());
	//	CountMark++;
	//}
	//if (uObj.getENCLOLURE() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " ENCLOLURE= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getENCLOLURE());
	//	CountMark++;
	//}
	//if (uObj.getREASON() != "string") {
	//	if (CountMark != 0) {
	//		sql << ",";
	//	}
	//	sql << " REASON= ? ";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getREASON());
	//	CountMark++;
	//}
	//if (uObj.getPIMPATENTID() != "string") {
	//	sql << "WHERE PIMPATENTID = ?";
	//	SQLPARAMS_PUSH(params, "s", std::string, uObj.getPIMPATENTID());
	//}
	//string sqlStr = sql.str();
	//CountReturn += sqlSession->executeUpdate(sqlStr, params);
	//if (CountReturn != 0)
	//	return 1;
	//else
	//	return 0;

	int CountMark = 0;//标识修改语句使“，”位置正确
	stringstream sql;
	sql << "UPDATE t_pimpatent SET ";
	SqlParams params; 
	if (uObj.getZLH() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " ZLH= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getZLH());
		CountMark++;
	}
	if (uObj.getPIMPATENTNAME() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " PIMPATENTNAME= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getPIMPATENTNAME());
		CountMark++;
	}
	if (uObj.getZLHQSJ() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " ZLHQSJ= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getZLHQSJ());
		CountMark++;
	}
	if (uObj.getZLPZGB() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " ZLPZGB= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getZLPZGB());
		CountMark++;
	}
	if (uObj.getENCLOLURE() != "string") {
		if (CountMark != 0) {
			sql << ",";
		}
		sql << " ENCLOLURE= ? ";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getENCLOLURE());
		CountMark++;
	}

	if (uObj.getPIMPATENTID() != "string") {
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

	if (uObj.getPIMPATENTID() != "string") {
		sql << " WHERE PIMPATENTID = ?";
		SQLPARAMS_PUSH(params, "s", std::string, uObj.getPIMPATENTID());
	}
	string sqlStr = sql.str();
	return sqlSession->executeUpdate(sqlStr, params);


	//string sql = "UPDATE `t_pimpatent` SET `ZLH`=?, `PIMPATENTNAME`=?, `ZLHQSJ`=? ,`ZLPZGB`=? ,`ENCLOLURE`=?  WHERE `PIMPATENTID`=?";
	//return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s", uObj.getZLH(), uObj.getPIMPATENTNAME(), uObj.getZLHQSJ(), uObj.getZLPZGB(), uObj.getENCLOLURE(), uObj.getPIMPATENTID());

}

