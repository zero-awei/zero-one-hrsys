#pragma once
#pragma once
#ifndef _T_PIMPERSON_DO_
#define _T_PIMPERSON_DO_
#include "../DoInclude.h"

/**
 * ���µ���ʵ����
 */
class t_pimpersonDO
{
	//Ա����� λ�����ݱ�t_pimperson
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	//Ա������ λ�����ݱ�t_pimperson
	CC_SYNTHESIZE(string, pimpersonname, Pimpersonname);
	//Ա��״̬ λ�����ݱ�t_pimperson
	CC_SYNTHESIZE(string, ygzt, Ygzt);
public:
	t_pimpersonDO() {
		ygbh = "";
		pimpersonname = "";
		ygzt = "";
	}
};

#endif // !_T_PIMPERSON_DO_