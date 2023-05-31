#include "stdafx.h"
#include "PatentinfoDAO.h"
#include "PatentinfoMapper.h"
#include <sstream>



// 查看指定员工专利信息（指定专利信息详情）
std::list<PatentinfoDO> PatentinfoDAO::selectByPIMPATENTID(const string& pimpatent)
{

	string sql = "SELECT ZLH,UPDATEDATE,PIMPATENTID,ZLHQSJ,PIMPATENTNAME,\
					UPDATEMAN,CREATEMAN,CREATEDATE,ZLPZGB,PIMPERSONID,\
					JLSS,JLSPZT,JLGLBH,JLCZZ,ENCLOLURE,\
					REASON\
		FROM t_pimpatent WHERE 1 = 1 AND PIMPATENTID LIKE CONCAT('%', ?, '%')";
	PatentinfoMapper mapper;
	return sqlSession->executeQuery<PatentinfoDO, PatentinfoMapper>(sql, mapper, "%s", pimpatent);
}


// 修改数据
int PatentinfoDAO::update(const PatentinfoDO& uObj)
{

	//stringstream sql;
	//stringstream fmt;
	//sql << "UPDATE t_pimpatent SET ";
	
	//sql << " WHERE PIMPATENTID = ?";


	//string sqlStr = sql.str();

	//string sqlfmtStr = fmt.str();
	//const char* sfs = (char*)sqlfmtStr.c_str();

	int CountReturn = 0;
	string sql;
	if (uObj.getZLH() != "string") {
		sql = "UPDATE t_pimpatent SET ZLH= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getZLH(), uObj.getPIMPATENTID());
	}
	if (uObj.getUPDATEDATE() != "string") {
		sql = "UPDATE t_pimpatent SET UPDATEDATE= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getUPDATEDATE(), uObj.getPIMPATENTID());
	}

	if (uObj.getZLHQSJ() != "string") {
		sql = "UPDATE t_pimpatent SET ZLHQSJ= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getZLHQSJ(), uObj.getPIMPATENTID());
	}

	if (uObj.getPIMPATENTNAME() != "string") {
		sql = "UPDATE t_pimpatent SET PIMPATENTNAME= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getPIMPATENTNAME(), uObj.getPIMPATENTID());
	}

	if (uObj.getUPDATEMAN() != "string") {
		sql = "UPDATE t_pimpatent SET UPDATEMAN= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getUPDATEMAN(), uObj.getPIMPATENTID());
	}

	if (uObj.getCREATEMAN() != "string") {
		sql = "UPDATE t_pimpatent SET CREATEMAN= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getCREATEMAN(), uObj.getPIMPATENTID());
	}

	if (uObj.getCREATEDATE() != "string") {
		sql = "UPDATE t_pimpatent SET CREATEDATE= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getCREATEDATE(), uObj.getPIMPATENTID());
	}

	if (uObj.getZLPZGB() != "string") {
		sql = "UPDATE t_pimpatent SET ZLPZGB= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getZLPZGB(), uObj.getPIMPATENTID());
	}

	if (uObj.getPIMPERSONID() != "string") {
		sql = "UPDATE t_pimpatent SET PIMPERSONID= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getPIMPERSONID(), uObj.getPIMPATENTID());
	}

	if (uObj.getJLSS() != "string") {
		sql = "UPDATE t_pimpatent SET JLSS= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getJLSS(), uObj.getPIMPATENTID());
	}

	if (uObj.getJLSPZT() != "string") {
		sql = "UPDATE t_pimpatent SET JLSPZT= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getJLSPZT(), uObj.getPIMPATENTID());
	}

	if (uObj.getJLGLBH() != "string") {
		sql = "UPDATE t_pimpatent SET JLGLBH= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getJLGLBH(), uObj.getPIMPATENTID());
	}

	if (uObj.getJLCZZ() != "string") {
		sql = "UPDATE t_pimpatent SET JLCZZ= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getJLCZZ(), uObj.getPIMPATENTID());
	}

	if (uObj.getENCLOLURE() != "string") {
		sql = "UPDATE t_pimpatent SET ENCLOLURE= ? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getENCLOLURE(), uObj.getPIMPATENTID());
	}

	if (uObj.getREASON() != "string") {
		sql = "UPDATE t_pimpatent SET REASON=? WHERE PIMPATENTID = ?";
		CountReturn += sqlSession->executeUpdate(sql, "%s%s", uObj.getREASON(), uObj.getPIMPATENTID());
	}

	if (CountReturn >= 1)
		return 1;
	else
		return 0;
}

