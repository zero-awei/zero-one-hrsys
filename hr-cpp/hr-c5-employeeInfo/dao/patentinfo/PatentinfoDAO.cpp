#include "stdafx.h"
#include "PatentinfoDAO.h"
#include "PatentinfoMapper.h"
#include <sstream>



// 查看指定员工专利信息（指定专利信息详情）
std::list<PatentinfoDO> PatentinfoDAO::selectByPIMPATENTID(const PatentinfoQuery::Wrapper& query)
{


	//string sql = "SELECT * FROM t_pimpatent WHERE `PIMPATENTID` LIKE CONCAT('%',?,'%')";
	//PatentinfoMapper mapper;
	//return sqlSession->executeQuery<PatentinfoDO, PatentinfoMapper>(sql, mapper, "%s", PIMPATENTID);


	stringstream sql;
	sql << "SELECT * FROM t_pimpatent";
	//sql << " WHERE PIMPATENTID = ?";
	sql << " WHERE 1=1";
	sql << " AND `pimpatentid` LIKE CONCAT('%',?,'%')";
	//FROM `t_pimvocational` INNER JOIN  t_pimperson ON t_pimvocational.PIMPERSONID = t_pimperson.PIMPERSONID  WHERE PIMVOCATIONALID = ? ";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->pimpatentid.getValue(""));
	PatentinfoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PatentinfoDO, PatentinfoMapper>(sqlStr, mapper, params);



}


// 修改数据
int PatentinfoDAO::update(const PatentinfoDO& uObj)
{
	string sql = "UPDATE `t_pimpatent` SET `zlh`=?, `updatedate`=?, `zlhqsj`=?, `pimpatentname`=?,\
											 `updateman`=?, `createman`=?, `createdate`=?, `zlpzgb`=?,\
											 `pimpersonid`=?, `jlss`=?, `jlspzt`=?, `jlglbh`=?,\
											 `jlczz`=?, `enclolure`=?, `reason`=? WHERE `PIMPATENTID`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", 
		uObj.getZLH(), 
		uObj.getUPDATEDATE(), 
		uObj.getZLHQSJ(), 
		uObj.getPIMPATENTNAME(),
		uObj.getUPDATEMAN(),
		uObj.getCREATEMAN(),
		uObj.getCREATEDATE(),
		uObj.getZLPZGB(),
		uObj.getPIMPERSONID(),
		uObj.getJLSS(),
		uObj.getJLSPZT(),
		uObj.getJLGLBH(),
		uObj.getJLCZZ(),
		uObj.getENCLOLURE(),
		uObj.getREASON() );
}

