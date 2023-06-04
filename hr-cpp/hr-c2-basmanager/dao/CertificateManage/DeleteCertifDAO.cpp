/*
（证书管理-证书信息-删除证书）--洛洛
*/
#include "stdafx.h"
#include <sstream>
#include "BaseDAO.h"
#include "DeleteCertifDAO.h"

int DeleteCertifDAO::deleteById(string id)
{
	string sql = "DELETE FROM `t_pimvocational` WHERE `PIMVOCATIONALID`=?";
	return sqlSession->executeUpdate(sql,"s",id);
}