/*
 证书管理-新建证书--pine
*/
#include "stdafx.h"
#include "SnowFlake.h"
#include "CreateNewCerService.h"
#include "../../dao/CertificateManage/CreateNewCerDAO.h"

uint64_t CreateNewCerService::saveData(const CreateNewCerDTO::Wrapper& dto)
{
	// 组装DO数据
	CertificateDO data;

	
	data.setYgbh(dto->ygbh.getValue(""));
	data.setZGZSBH(dto->zgzsbh.getValue(""));
	data.setPimVocationalName(dto->pimVocationalName.getValue(""));
	//雪花算法生成唯一标识ID
	SnowFlake f2(1, 2);
	data.setPimvocationalid(to_string(f2.nextId()));

	data.setBcardNumber(dto->bcardNumber.getValue(""));
	data.setZslx(dto->zslx.getValue(""));
	data.setZghqrq(dto->zghqrq.getValue(""));
	data.setZcdw(dto->zcdw.getValue(""));
	data.setZgsydw(dto->zgsydw.getValue(""));
	data.setSxrq(dto->sxrq.getValue(""));//未加入
	data.setNSQK(dto->nsqk.getValue(""));//插入独有字段
	data.setSYQK(dto->syqk.getValue(""));
	data.setALTERATION(dto->alteration.getValue(""));

	data.setPIMPERSONID(dto->pimpersonid.getValue(""));
	data.setREGISNUMBER(dto->regisnumber.getValue(""));
	data.setSOCSECPAYUNIT(dto->socsecpayunit.getValue(""));
	data.setCSZCSJ(dto->cszcsj.getValue(""));
	data.setXZCSJ(dto->xzcsj.getValue(""));

	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Ygbh, ygbh, BcardNumber, bcardNumber, PimVocationalName,
	//	pimVocationalName, Zslx, zslx, Zghqrq, zghqrq, Zgsydw, zgsydw, Zcdw, zcdw, NSQK, nsqk, SYQK, syqk, ALTERATION, alteration)
	// 执行数据添加
	CreateNewCerDAO dao;
	return dao.insert(data);
	/*
宏定义与set二选一即可
*/
}

