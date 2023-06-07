#include "stdafx.h"
#include "EducationDAO.h"
#include "EducationMapper.h"
#include "SqlSession.h"
#include "SnowFlake.h"
#include "domain/dto/educationAdd/EducationAddDTO.h"

/**
 * 分页查询教育信息条件匹配宏
 */
#define EDUCATIONPAGE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pimpersonid) { \
	sql << " AND `pimpersonid`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonid.getValue("")); \
} \
//if (query->pimpersonname) { \
//	sql << " AND pimpersonname=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonname.getValue("")); \
//} \
//if (query->sort) { \
//	sql << " AND sort=?"; \
//	SQLPARAMS_PUSH(params, "i", std::string, query->sort.getValue("")); \
//}


std::list<EducationDO> EducationDAO::selectEducationPage(const EducationPageQuery::Wrapper& query)
{
	stringstream sql;
	//sql << "SELECT `PIMEDUCATIONID`, `XL`, `QSSJ`, `JSSJ`, `BYYX`, `XKML`, `SXZY`, `XLLX`, `XXXZ`, ";
	//sql << "`SFDYXL`, `SFZGXL`, `BTZ`, `XWZ`, `XLCX`, `FJ` ";
	//sql << " FROM t_pimeducation ";
	sql << "SELECT * FROM `t_pimeducation`";
	//EDUCATIONPAGE_TERAM_PARSE(query, sql);
	SqlParams params; 
	sql << " WHERE 1=1";
	if (query->PIMPERSONID) {
		sql << " AND `pimpersonid` = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->PIMPERSONID.getValue(""));
	}
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;

	EducationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<EducationDO, EducationMapper>(sqlStr, mapper, params);
}

uint64_t EducationDAO::count(const EducationPageQuery::Wrapper& query)
{

	stringstream sql;
	sql << "SELECT COUNT(*) FROM `t_pimeducation`";
	SqlParams params; 
	sql << " WHERE 1=1";
	/*if (query->PIMPERSONID) {
			sql << " AND `PIMPERSONID` = ?";
			SQLPARAMS_PUSH(params, "s", std::string, query->PIMPERSONID.getValue(""));
	} */
	////EDUCATIONPAGE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<EducationDO> EducationDAO::selectEducationSingle(const EducationSingleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM `t_pimeducation` WHERE `PIMPERSONID`=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->PIMPERSONID.getValue(""));
	EducationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<EducationDO, EducationMapper>(sqlStr, mapper, params);
}

int EducationDAO::insertEducation(const EducationDO& iObj)//新增数据
{
	string sql = "INSERT INTO `t_pimeducation` ";
	sql += "(`PIMEDUCATIONID`, `XL`, `QSSJ`, `JSSJ`, `BYYX`,";
	sql += "`XKML`, `SXZY`, `XLLX`, `XXXZ`, `SFDYXL`, `SFZGXL`, `BTZ`, `XWZ`, `XLCX`, `FJ`, `PIMPERSONID`) ";//16
	sql += "VALUES(? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ?)";//16
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%ull%ull%s%s%s%s%s", iObj.getFunPIMEDUCATIONID(), iObj.getFunXL(), iObj.getFunQSSJ(),
		iObj.getFunJSSJ(), iObj.getFunBYYX(), iObj.getFunXKML(), iObj.getFunSXZY(), iObj.getFunXLLX(), iObj.getFunXXXZ(), iObj.getFunSFDYXL(),
		iObj.getFunSFZGXL(), iObj.getFunBTZ(), iObj.getFunXWZ(), iObj.getFunXLCX(), iObj.getFunFJ(), iObj.getFunPIMPERSONID());//16

																				   
																				   
																				   //string sqlStr = sql.str();
	//return sqlSession->executeInsert(sqlStr, "%s%s%s%s%s%s%s%s%s%ull%ull%s%s%s%s%s", pimid, dto->XL, dto->QSSJ,//16
	//	dto->JSSJ, dto->BYYX, dto->XKML, dto->SXZY, dto->XLLX, dto->XXXZ, dto->SFDYXL,
	//	dto->SFZGXL, dto->BTZ, dto->XWZ, dto->XLCX, dto->FJ, dto->PIMPERSONID);//15


	
}

bool EducationDAO::updateEducaiton(const EducationDO& data)
{
	string sql = "UPDATE `t_pimeducation` ";
	sql += "SET  `XL` = ? , `QSSJ` = ? , `JSSJ` = ? , `BYYX` = ? , `XKML` = ? , ";
	sql += "`SXZY` = ? , `XLLX` = ? , `XXXZ` = ? , `SFDYXL` = ? , `SFZGXL` = ? , ";
	sql += "`BTZ` = ? , `XWZ` = ? , `XLCX` = ? , `FJ` = ? ";
	sql += "WHERE `PIMEDUCATIONID` = ? ";                                              
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%ull%ull%s%s%s%s%s", 
		data.getFunXL(), data.getFunQSSJ(),data.getFunJSSJ(), data.getFunBYYX(), data.getFunXKML(), 
		data.getFunSXZY(), data.getFunXLLX(), data.getFunXXXZ(), data.getFunSFDYXL(), data.getFunSFZGXL(), 
		data.getFunBTZ(), data.getFunXWZ(), data.getFunXLCX(), data.getFunFJ(), data.getFunPIMEDUCATIONID());
}

int EducationDAO::deleteEducaiton(std::string id)
{
	//数据库删除语句
	//string sql = "DELETE FROM `t_pimeducation` WHERE `PIMPERSONID`=? AND `PIMEDUCATIONID`=?";
	string sql = "DELETE FROM `t_pimeducation` WHERE `PIMEDUCATIONID` = ?";
	return sqlSession->executeUpdate(sql, "%s", id);
}

