#include "stdafx.h"
#include "FamilysituationDAO.h"
#include "FamilysituationMapper.h"
#include <sstream>

// 定义条件解析宏，减少重复代码
#define FAMILY_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE `PIMPERSONID`=?"; \
SQLPARAMS_PUSH(params, "s", std::string, query->personid.getValue(""));\
if(query->frelationship){ \
	sql<< " AND `YBRGX`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->frelationship.getValue("")); \
} \
if(query->name){ \
	sql<< " AND `PIMFAMINFONAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if(query->doctype){ \
	sql<< " AND `ZJLX`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->doctype.getValue("")); \
} \
if(query->identification){ \
	sql<< " AND `ZJH`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->identification.getValue("")); \
} \
if(query->gender){ \
	sql<< " AND `XB`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->gender.getValue("")); \
} \
if(query->dob){ \
	sql<< " AND `CSRQ`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->dob.getValue("")); \
} \
if(query->age){ \
	sql<< " AND `NL`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
} \
if(query->workplace){ \
	sql<< " AND `GZDW`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workplace.getValue("")); \
} \
if(query->job){ \
	sql<< " AND `ZW`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->job.getValue("")); \
} \
if(query->politicalstatus){ \
	sql<< " AND `ZZMM`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->politicalstatus.getValue("")); \
} \
if(query->testament){ \
	sql<< " AND `SRUVIVORS`=?"; \
	SQLPARAMS_PUSH(params, "s", int, query->testament.getValue(0)); \
} \
if(query->ice){ \
	sql<< " AND `SFJJLLR`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ice.getValue("")); \
} 

// 数据条数
uint64_t FamilysituationDAO::count(const FamilysituationQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimfaminfo";
	FAMILY_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

// 分页查询
std::list<FamilysituationDO> FamilysituationDAO::selectWithPage(const FamilysituationQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM t_pimfaminfo";
	FAMILY_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	FamilysituationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<FamilysituationDO, FamilysituationMapper>(sqlStr, mapper, params);
}



// 指定查询
std::list<FamilysituationDO> FamilysituationDAO::selectWithOne(const FamilysituationQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM t_pimfaminfo";
	SqlParams params;
	sql << " WHERE `PIMFAMINFOID`=?";
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); 
	FamilysituationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<FamilysituationDO, FamilysituationMapper>(sqlStr, mapper, params);
}

// 新增
uint64_t FamilysituationDAO::insert(const FamilysituationDO& iObj)
{
	string sql = "INSERT INTO `t_pimfaminfo` (`PIMPERSONID`, `PIMFAMINFOID`, `YBRGX`, `PIMFAMINFONAME`, `ZJLX`, `ZJH`, `XB`, `CSRQ`, `NL`, `GZDW`, `ZW`, `ZZMM`, `SRUVIVORS`, `SFJJLLR`, `CREATEMAN`, `CREATEDATE`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%i%s%s%s%i%s%s%s", \
		iObj.getPersonId(), iObj.getId(), iObj.getRelationship(), iObj.getName(), iObj.getDoctype(), iObj.getIdentification(), iObj.getGender(), iObj.getDob(), iObj.getAge(), iObj.getWorkplace(), iObj.getJob(), iObj.getPoliticalstatus(), iObj.getTestament(), iObj.getIce(), iObj.getAuthId(), iObj.getOpertime());
}

// 修改
int FamilysituationDAO::update(const FamilysituationDO& uObj)
{
	string sql = "UPDATE `t_pimfaminfo` SET `YBRGX`=?, `PIMFAMINFONAME`=?, `ZJLX`=?, `ZJH`=?, `XB`=?, `CSRQ`=?, `NL`=?, `GZDW`=?, `ZW`=?, `ZZMM`=?, `SRUVIVORS`=?, `SFJJLLR`=?, `UPDATEMAN`=?, `UPDATEDATE`=? WHERE `PIMFAMINFOID`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%i%s%s%s%i%s%s%s%s", \
		uObj.getRelationship(), uObj.getName(), uObj.getDoctype(), uObj.getIdentification(), uObj.getGender(), uObj.getDob(), uObj.getAge(), uObj.getWorkplace(), uObj.getJob(), uObj.getPoliticalstatus(), uObj.getTestament(), uObj.getIce(), uObj.getAuthId(), uObj.getOpertime(), uObj.getId());
}

// 删除
int FamilysituationDAO::deleteById(FamilysituationDO& dObj)
{
	string sql = "DELETE FROM `t_pimfaminfo` WHERE `PIMFAMINFOID`=?" ;
	return sqlSession->executeUpdate(sql, "%s", dObj.getId());
}