#include "stdafx.h"
#include "ArchiveDAO.h"
#include "ArchiveMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define ARCHIVE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->sortid) { \
	sql << " AND `sortid`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->sortid.getValue(1)); \
} \
if (query->archivename) { \
	sql << " AND archivename=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->archivename.getValue("")); \
} \
if (query->cabinetnum) { \
	sql << " AND cabinetnum=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->cabinetnum.getValue(1)); \
}\
if (query->layernum) {\
		sql << " AND layernum=?"; \
		SQLPARAMS_PUSH(params, "i", int, query->layernum.getValue(1));\
} \
if (query->numid) {\
		sql << " AND numid=?"; \
		SQLPARAMS_PUSH(params, "i", int, query->numid.getValue(1));\
} \

uint64_t ArchiveDAO::count(const ArchiveQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_archivescenter";
	ARCHIVE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ArchiveDO> ArchiveDAO::selectWithPage(const ArchiveQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM t_archivescenter";
	ARCHIVE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ArchiveMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ArchiveDO, ArchiveMapper>(sqlStr, mapper, params);
}

std::list<ArchiveDO> ArchiveDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM t_archivescenter WHERE `ARCHIVESCENTERNAME` LIKE CONCAT('%',?,'%')";
	ArchiveMapper mapper;
	return sqlSession->executeQuery<ArchiveDO, ArchiveMapper>(sql, mapper, "%s", name);
}

uint64_t ArchiveDAO::insert(const ArchiveDO& iObj)
{
	string sql = "INSERT INTO `t_archivescenter` (`SERIALNO`, `ARCHIVESCENTERNAME`, `CABINETNO`,`LAYERNO`,`ARCHIVESCENTERID`) VALUES (?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%i%s%i%i%i", iObj.getsortID(), iObj.getarchiveName(), iObj.getcabinetNum(), iObj.getlayerNum(), iObj.getnumID());
}

int ArchiveDAO::update(const ArchiveDO& uObj)
{
	string sql = "UPDATE `t_archivescenter` SET `ARCHIVESCENTERNAME`=?, `CABINETNO`=? ,`LAYERNO`=?,`BNUMBER`=? WHERE `SERIALNO`=?";
	return sqlSession->executeUpdate(sql, "%s%i%i%i%i", uObj.getarchiveName(), uObj.getcabinetNum(), uObj.getlayerNum(), uObj.getnumID(), uObj.getsortID());
}

int ArchiveDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `t_archivescenter` WHERE `SERIALNO`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}