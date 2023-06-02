/*
证书管理-新建证书--pine
*/
#include "stdafx.h"
#include "CreateNewCerDAO.h"
#include "CreateNewCerMapper.h"
#include <sstream>


uint64_t CreateNewCerDAO::insert(const CertificateDO& iObj)
{
	string sql = "INSERT INTO t_pimvocational (ygbh, pimvocationalid, bcardNumber, pimVocationalName, zslx, zghqrq, zgsydw, zcdw,fzyxq,sxrq,nsqk,syqk,alteration)\
					VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?); ";
	return sqlSession->executeUpdate(sql, "%i%s%s%s%s%s%s%s%s%s%s%s%s", iObj.getYgbh(), iObj.getPimvocationalid(), iObj.getBcardNumber(), iObj.getPimVocationalName(), iObj.getZslx(), iObj.getZghqrq(), iObj.getZgsydw(), iObj.getZcdw(), iObj.getFzyxq(), iObj.getSxrq(), iObj.getNSQK(), iObj.getSYQK(), iObj.getALTERATION());
}

