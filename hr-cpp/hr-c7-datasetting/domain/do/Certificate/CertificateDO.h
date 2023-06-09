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
	CC_SYNTHESIZE(int32_t, seialno, seialNo);
	// 岗位技能证书
	CC_SYNTHESIZE(string, pimqualtypename, pimQualTypeName);
public:
	CertificateDO() 
	{
		seialno = 0;
		pimqualtypename = "";
	}
	//分别为排序号，岗位技能证书
	CertificateDO(int seialno, string pimqualtypename)
	{
		this->seialno = seialno;
		this->pimqualtypename = pimqualtypename;
	}
};

#endif