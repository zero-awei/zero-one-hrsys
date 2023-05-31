#pragma once
#ifndef _QUALIFICATIONDO_H_
#define _QUALIFICATIONDO_H_

#include "../DoInclude.h"
/**
 * 执业资格证书信息实体
 */
class QualificationDO
{
	// 执业资格专业编码
	CC_SYNTHESIZE(string, pimqualmajorid, pimQualMajorId);
	// 级别
	CC_SYNTHESIZE(string, qualevel, quaLevel);
	// 执业资格
	CC_SYNTHESIZE(string, pimqualmajorname, pimQualMajorName);
	// 专业
	CC_SYNTHESIZE(string, quamajor, quaMajor);
public:
	QualificationDO() 
	{ 
		pimqualmajorid = "";
		qualevel = "";
		pimqualmajorname = "";
		quamajor = "";
	}
	//分别为执业资格专业编码，级别，执业资格，专业
	QualificationDO(string pimqualmajorid, string qualevel, string pimqualmajorname, string quamajor)
	{
		this->pimqualmajorid = pimqualmajorid;
		this->qualevel = qualevel;
		this->pimqualmajorname = pimqualmajorname;
		this->quamajor = quamajor;
	}
};

#endif