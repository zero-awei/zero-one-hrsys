/*
* 法人主体设置--删除法人设置(支持批量删除)--pine
*/
#include "stdafx.h"
#include "DeleteLegalEntityDAO.h"
#include "DeleteLegalEntityMapper.h"
#include <sstream>
//t_ormsignorg + t_contractsignorg
int DeleteLegalEntityDAO::update1(string id)
{
	string sql = "UPDATE t_contractsignorg SET ORMSIGNORGID = NULL WHERE ORMSIGNORGID = ?;";
	return sqlSession->executeUpdate(sql, "s", id);
}
int DeleteLegalEntityDAO::update2(string id)
{
	string sql = "UPDATE t_pimcontract SET ORMSIGNORGID = NULL WHERE ORMSIGNORGID =?;";
	return sqlSession->executeUpdate(sql, "s", id);
}
int DeleteLegalEntityDAO::update3(string id)
{
	string sql = "UPDATE t_pimvocational SET ORMSIGNORGID = NULL WHERE ORMSIGNORGID = ?;";
	return sqlSession->executeUpdate(sql, "s", id);
}
int DeleteLegalEntityDAO::deleteById(string id)
{
	string sql = "DELETE FROM t_ormsignorg WHERE ORMSIGNORGID =?;";
	return sqlSession->executeUpdate(sql, "s", id);
}
