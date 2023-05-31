#include "stdafx.h"
#include "EducationDAO.h"
#include "EducationMapper.h"
#include "SqlSession.h"

/**
 * 分页查询教育信息条件匹配宏
 */
#define EDUCATIONPAGE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
//if (query->pimpersonid) { \
//	sql << " AND `pimpersonid`=?"; \
//	SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonid.getValue("")); \
//} \
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
	sql << "SELECT `PIMEDUCATIONID`, `XL`, `QSSJ`, `JSSJ`, `BYYX`, `XKML`, `SXZY`, `XLLX`, `XXXZ`, `SFDYXL`, `SFZGXL`, `BTZ`, `XWZ`, `XLCX`, `FJ` FROM t_pimeducation";
	//sql << "SELECT * FROM t_pimeducation";
	EDUCATIONPAGE_TERAM_PARSE(query, sql);
	
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	EducationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<EducationDO, EducationMapper>(sqlStr, mapper, params);
}

uint64_t EducationDAO::count(const EducationPageQuery::Wrapper& query)
{
	stringstream sql;
	//sql << "SELECT COUNT(`PIMPERSONID`) FROM `t_pimeducation`";
	sql << "SELECT COUNT(*) FROM `t_pimeducation`";
	EDUCATIONPAGE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<EducationDO> EducationDAO::selectEducationSingle(const EducationSingleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM `t_pimeducation` WHERE `PIMEDUCATIONID`=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->PIMEDUCATIONID.getValue(""));
	EducationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<EducationDO, EducationMapper>(sqlStr, mapper, params);
}

uint64_t EducationDAO::insertEducation(const EducationDO& iObj)//新增数据
{
	string sql = "INSERT INTO `t_pimeducation` \
		(`PIMEDUCATIONID`, `XL`, `QSSJ`, `JSSJ`, `BYYX`,\
		 `XKML`, `SXZY`, `XLLX`, `XXXZ`, `SFDYXL`, \
		`SFZGXL`, `BTZ`, `XWZ`, `XLCX`, `FJ`)\
		 VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s%i%i%s%s%s%s", iObj.getFunPIMEDUCATIONID(), iObj.getFunXL(), iObj.getFunQSSJ(),
		iObj.getFunJSSJ(), iObj.getFunBYYX(), iObj.getFunXKML(), iObj.getFunSXZY(), iObj.getFunXLLX(), iObj.getFunXXXZ(), iObj.getFunSFDYXL(),
		iObj.getFunSFZGXL(), iObj.getFunBTZ(), iObj.getFunXWZ(), iObj.getFunXLCX(), iObj.getFunFJ());// %s%s&i：字符串、字符串、int
	//return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%i%i%s%s%s%s", iObj.getFunPIMEDUCATIONID(), iObj.getFunXL(), iObj.getFunQSSJ(),
	//	iObj.getFunJSSJ(), iObj.getFunBYYX(), iObj.getFunXKML(), iObj.getFunSXZY(), iObj.getFunXLLX(), iObj.getFunXXXZ(), iObj.getFunSFDYXL(),
	//	iObj.getFunSFZGXL(), iObj.getFunBTZ(), iObj.getFunXWZ(), iObj.getFunXLCX(), iObj.getFunFJ());// %s%s&i：字符串、字符串、int
}

bool EducationDAO::updateEducaiton(const EducationDO& data)
{
	string sql = "UPDATE `t_pimeducation` SET  `XL` = ?, `QSSJ` = ?, `JSSJ` = ? ,   `BYYX` = ?, `XKML` = ?, `SXZY` = ?, `XLLX` = ?, `XXXZ` = ?, `SFDYXL` = ?, `SFZGXL` = ?, `BTZ` = ?, `XWZ` = ?, `XLCX` = ?,  `FJ` = ? WHERE `PIMEDUCATIONID` = ?";                                              
	return sqlSession->executeUpdate(sql, "%s%i%i%s%s%s%s%s%i%i%s%s%s", data.getFunXL(), data.getFunQSSJ(),
		data.getFunJSSJ(), data.getFunBYYX(), data.getFunXKML(), data.getFunSXZY(), data.getFunXLLX(), data.getFunXXXZ(), data.getFunSFDYXL(),
		data.getFunSFZGXL(), data.getFunBTZ(), data.getFunXWZ(), data.getFunXLCX(), data.getFunFJ());
}

int EducationDAO::deleteEducaiton(string id)
{
	string sql = "SET FOREIGN_KEY_CHECKS = 0";
	sqlSession->execute(sql);
	sql = "DELETE FROM `t_pimeducation` WHERE `PIMEDUCATIONID`= '" + id + "'";
	return sqlSession->executeUpdate(sql);
}

