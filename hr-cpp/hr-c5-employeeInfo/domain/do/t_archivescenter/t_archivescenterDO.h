#pragma once
#ifndef _T_ARCHIVESCENTER_DO_
#define _T_ARCHIVESCENTER_DO_
#include "../DoInclude.h"

class t_archivescenterDO
{
	//���������ı��� λ�����ݱ�t_archivescenter
	CC_SYNTHESIZE(string, archivescentername, Archivescentername);
public:
	t_archivescenterDO() {
		archivescentername = "";
	}
};

#endif // !_T_ARCHIVESCENTER_DO_