#include "stdafx.h"
#include "SpercificCertificateDAO.h"
/**
 *  证书管理 —— 证书信息 —— 查询、更新指定证书 —— 楚孟献
 */

int SpercificCertificateDAO::update(const SpercificCertificateDO& uObj)
{
	string sql = "UPDATE `t_pimvocational` \
SET  `zgzsbh`=?, `zslx`=?, \
`pimVocationalName`=?, `zgsydw`=?, `REGISNUMBER`=?,\
 `zcdw`=?, `SOCSECPAYUNIT`=?, `bcardNumber`=?,\
 `zghqrq`=?, `CSZCSJ`=?, `XZCSJ`=?,\
 `sxrq`=?, `NSQK`=?, `SYQK`=?,\
 `ALTERATION`=? \
WHERE `PIMVOCATIONALID`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s"
		, uObj.getZgzsbh(), uObj.getZslx(), uObj.getPimVocationalName()
		, uObj.getZgsydw(), uObj.getregisNumber(), uObj.getZcdw(), uObj.getSOCSECPAYUNIT()
		, uObj.getBcardNumber(), uObj.getZghqrq(), uObj.getCSZCSJ(), uObj.getXZCSJ()
		, uObj.getSxrq(), uObj.getNSQK(), uObj.getSYQK(), uObj.getALTERATION()
		, uObj.getPIMVOCATIONALID());
}

std::list<SpercificCertificateDO> SpercificCertificateDAO::querySpercificC(const SpercificCertificateQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT `pimperSonName` , `zgzsbh` , `zslx` ,`pimVocationalName` , `zgsydw` , `REGISNUMBER` ,\
	`zcdw` , `SOCSECPAYUNIT` , `bcardNumber` ,`zghqrq` , `CSZCSJ` , `XZCSJ` ,`sxrq` , `NSQK` , `SYQK` ,`ALTERATION` \
	FROM `t_pimvocational` INNER JOIN  t_pimperson ON t_pimvocational.PIMPERSONID = t_pimperson.PIMPERSONID  WHERE PIMVOCATIONALID = ?";

	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->PIMVOCATIONALID.getValue(""));

	SpercificCertificateMapper mapper;
	string sqlStr = sql.str();

	return sqlSession->executeQuery<SpercificCertificateDO, SpercificCertificateMapper>(sqlStr, mapper, params);
}