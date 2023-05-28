#include "stdafx.h"
#include "RraineeDAO.h"
#include "RraineeMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}

//uint64_t RraineeDAO::count(const RraineeQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT COUNT(*) FROM sample";
//	SAMPLE_TERAM_PARSE(query, sql);
//	string sqlStr = sql.str();
//	return sqlSession->executeQueryNumerical(sqlStr, params);
//}

std::list<RraineeDO> RraineeDAO::selectWithPage(const RraineeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM sample";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	RraineeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<RraineeDO, RraineeMapper>(sqlStr, mapper, params);
}

/*
std::list<RraineeDO> RraineeDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
	RraineeMapper mapper;
	return sqlSession->executeQuery<RraineeDO, RraineeMapper>(sql, mapper, "%s", name);
}

uint64_t RraineeDAO::insert(const RraineeDO& iObj)
{
	string sql = "INSERT INTO `sample` (`name`, `sex`, `age`) VALUES (?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getName(), iObj.getSex(), iObj.getAge());
}

int RraineeDAO::update(const RraineeDO& uObj)
{
	string sql = "UPDATE `sample` SET `name`=?, `sex`=?, `age`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
}

int RraineeDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `sample` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}*/