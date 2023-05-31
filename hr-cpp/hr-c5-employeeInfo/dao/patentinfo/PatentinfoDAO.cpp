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
	//if (uObj.getZLH() != "string") {
	//	sql << "ZLH = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getUPDATEDATE() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getZLHQSJ() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getPIMPATENTNAME() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getUPDATEMAN() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getCREATEMAN() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getCREATEDATE() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getZLPZGB() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getPIMPERSONID() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getJLSS() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getJLSPZT() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getJLGLBH() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getJLCZZ() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getENCLOLURE() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//if (uObj.getREASON() != "string") {
	//	sql << "UPDATEDATE = ?";
	//	fmt << "%s";
	//}
	//sql << " WHERE PIMPATENTID = ?";


	//string sqlStr = sql.str();





	//string sqlfmtStr = fmt.str();
	//const char* sfs = (char*)sqlfmtStr.c_str();
	string sql = "UPDATE t_pimpatent SET ZLH= ?, REASON=? WHERE PIMPATENTID = ?";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getZLH(), uObj.getREASON(), uObj.getPIMPATENTID());
}

