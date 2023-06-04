/*
证书管理-新建证书--pine
*/
#include "stdafx.h"
#include "CreateNewCerDAO.h"
#include "CreateNewCerMapper.h"
#include <sstream>

uint64_t CreateNewCerDAO::insert(const CertificateDO& iObj)
{
	string sql = "INSERT INTO t_pimvocational (ygbh, pimvocationalid, bcardNumber, pimVocationalName, zslx, zghqrq, zgsydw, zcdw,sxrq,nsqk,syqk,alteration,\
					pimpersonid,zgzsbh,regisnumber,socsecpayunit,cszcsj,xzcsj)\
					VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?); ";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", iObj.getYgbh(), iObj.getPimvocationalid(), iObj.getBcardNumber(), iObj.getPimVocationalName(), iObj.getZslx(), iObj.getZghqrq(), iObj.getZgsydw(), iObj.getZcdw(), iObj.getSxrq(), iObj.getNSQK(), iObj.getSYQK(), iObj.getALTERATION(),
		iObj.getPIMPERSONID(), iObj.getZGZSBH(), iObj.getREGISNUMBER(), iObj.getSOCSECPAYUNIT(), iObj.getCSZCSJ(), iObj.getXZCSJ());
}

