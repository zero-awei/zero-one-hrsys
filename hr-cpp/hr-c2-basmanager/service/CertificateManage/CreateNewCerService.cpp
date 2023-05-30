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

	
	data.setYgbh(dto->ygbh.getValue(0));
	data.setPimVocationalName(dto->pimVocationalName.getValue(""));
	//雪花算法生成唯一标识ID
	SnowFlake f2(1, 2);
	data.setPimvocationalid(to_string(f2.nextId()));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Ygbh, ygbh, PimVocationalName, pimVocationalName)
	// 执行数据添加
	CreateNewCerDAO dao;
	return dao.insert(data);
}

