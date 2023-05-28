#pragma once
#include"stdafx.h"
#ifndef _ADDPIMARMYCADRESDO_H_
#define _ADDPIMARMYCADRESDO_H_

#include "../DoInclude.h"

class AddPimarmycadresDO {
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
	//军转干部记录id
	CC_SYNTHESIZE(string, PIMARMYCADRESID,pIMARMYCADRESID);

	AddPimarmycadresDO() = default;

	AddPimarmycadresDO(std::vector<std::string> vec) {
		int i = 0;
		setpIMID(vec[i++]);
		setfORM(vec[i++]);
		setlEVEL(vec[i++]);
		setoCCURTIME(vec[i++]);
		setaNNEXPATH(vec[i++]);
	}

};

#endif