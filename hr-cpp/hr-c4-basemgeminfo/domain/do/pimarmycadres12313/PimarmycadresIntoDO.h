#pragma once


#ifndef _PIMARMYCADRESINTODO_H_
#define _PIMARMYCADRESINTODO_H_

#include "../DoInclude.h"

class PimarmycadresIntoDO {
	// 编号
	CC_SYNTHESIZE(string, PIMID, pIMID);
	//	种类
	CC_SYNTHESIZE(string, FORM, fORM);
	// 级别
	CC_SYNTHESIZE(string, LEVEL, lEVEL);
	// 发生时间
	CC_SYNTHESIZE(string, OCCURTIME, oCCURTIME);
	//附件路径
	CC_SYNTHESIZE(string, ANNEXPATH, aNNEXPATH);

	CC_SYNTHESIZE(string, PIMARMYCADRESID, pIMARMYCADRESID);



};

#endif