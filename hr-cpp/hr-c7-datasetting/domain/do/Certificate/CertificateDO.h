#pragma once
#ifndef _CERTIFICATEDO_H_
#define _CERTIFICATEDO_H_

#include "../DoInclude.h"
/**
 * 岗位技能证书信息实体
 */
class CertificateDO
{
	// 排序号
	CC_SYNTHESIZE(string, seialno, seialNo);
	// 岗位技能证书
	CC_SYNTHESIZE(string, pimqualtypename, pimQualTypeName);
public:
	CertificateDO() 
	{
		seialno = "";
		pimqualtypename = "";
	}
	//分别为排序号，岗位技能证书
	CertificateDO(string seialno, string pimqualtypename)
	{
		this->seialno = seialno;
		this->pimqualtypename = pimqualtypename;
	}
};

#endif