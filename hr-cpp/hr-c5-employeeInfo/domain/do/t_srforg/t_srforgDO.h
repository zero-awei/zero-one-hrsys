#pragma once
#pragma once
#ifndef _T_SRGORG_DO_
#define _T_SRGORG_DO_
#include "../DoInclude.h"

class t_srforgDO
{
	//����λ���ı��� λ�����ݱ�t_srforg
	CC_SYNTHESIZE(string, orgname, Orgname);
public:
	t_srforgDO() {
		orgname = "";
	}
};

#endif // !_T_SRGORG_DO_