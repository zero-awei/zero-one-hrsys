#include "stdafx.h"
#include "DeleteProjTagDAO.h"
#include <sstream>

int DeleteProjTagDAO::deleteById(string id)
{
	string sql = "SET FOREIGN_KEY_CHECKS = 0";
	sqlSession->execute(sql);
	sql = "DELETE FROM `t_ormxmbq` WHERE `ORMXMBQID`= '" + id + "'";
	return sqlSession->executeUpdate(sql);
}