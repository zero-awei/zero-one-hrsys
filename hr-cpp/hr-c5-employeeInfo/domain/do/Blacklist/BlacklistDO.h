#pragma once
#ifndef _BLACKLIST_DO_
#define _BLACKLIST_DO_
#include "../DoInclude.h"


class BlacklistDO
{
	//Ա�����
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	//Ա������
	CC_SYNTHESIZE(string, ygxm, Ygxm);
	//֤�����
	CC_SYNTHESIZE(string, zjbh, Zjbh);
	//��֯
	CC_SYNTHESIZE(string, zz, Zz);
	//Ա��״̬
	CC_SYNTHESIZE(string, ygzt, Ygzt);
	//�Ƿ����������
	CC_SYNTHESIZE(string, lrhmd, Lrhmd);
	//������ԭ��
	CC_SYNTHESIZE(string, hmdyy, Hmdyy);
public:
	BlacklistDO() {
		ygbh = "";
		ygxm = "";
		zjbh = "";
		zz = "";
		ygzt = "";
		lrhmd = "";
		hmdyy = "";
	}
};

#endif