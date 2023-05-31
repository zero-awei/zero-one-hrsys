#include "stdafx.h"
#include "LegalEntitySetDAO.h"
#include "LegalEntitySetMapper.h"
#include <sstream>
/*
组织管理 ——数据设置 —— 法人主体设置  -- cpt

法人主体名称下拉列表 `LegalEntitySetPullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `LegalEntitySet`

新增法人设置（支持批量新增）** `LegalEntitySet`
*/ 

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->ormsignorgname) { \
	sql << " AND `ormsignorgname`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ormsignorgname.getValue("")); \
} \
if (query->contractsignorgname) { \
	sql << " AND contractsignorgname=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->contractsignorgname.getValue("")); \
} \
if (query->isdefaultsignorg) { \
	sql << " AND isdefaultsignorg=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->isdefaultsignorg.getValue(0)); \
}

std::list<LegalEntitySetDO> LegalEntitySetDAO::legalerNamePullDownList(const string& name)
{
	string sql = "SELECT * FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
	LegalEntitySetMapper mapper;
	return sqlSession->executeQuery<LegalEntitySetDO, LegalEntitySetMapper>(sql, mapper, "%s", name);
}

uint64_t LegalEntitySetDAO::insert(const LegalEntitySetDO& iObj)
{
	string sql = "INSERT INTO `t_contractsignorg` (`ORMSIGNORGID`, /*`ORMSIGNORGNAME`,*/ `CONTRACTSIGNORGNAME`, `ISDEFAULTSIGNORG`) VALUES (?, ？, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i",iObj.getORMSIGNORGID(), /*iObj.getORMSIGNORGNAME(),*/ iObj.getCONTRACTSIGNORGNAME(), iObj.getISDEFAULTSIGNORG());
}

int LegalEntitySetDAO::update(const LegalEntitySetDO& uObj)
{
	string sql = "UPDATE `t_contractsignorg` SET `ORMSIGNORGNAME`=?, `CONTRACTSIGNORGNAME`=?, `ISDEFAULTSIGNORG`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%s", uObj.getORMSIGNORGNAME(), uObj.getCONTRACTSIGNORGNAME(), uObj.getISDEFAULTSIGNORG(), uObj.getORMSIGNORGID());
}
