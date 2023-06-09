#pragma once
#ifndef _WORKHISTORY_DO_H_
#define _WORKHISTORY_DO_H_
#include "../DoInclude.h"

class WorkHistoryDO
{
	CC_SYNTHESIZE(string, rzkssj, Rzkssj);
	CC_SYNTHESIZE(string, rzjssj, Rzjssj);
	CC_SYNTHESIZE(string, ormorgname, Ormorgname);
	CC_SYNTHESIZE(string, ormorgsectorname, Ormorgsectorname);
	CC_SYNTHESIZE(string, ormdutyname, Ormdutyname);
	CC_SYNTHESIZE(string, ormpostname, Ormpostname);
	CC_SYNTHESIZE(string, cfplx, Cfplx);
	CC_SYNTHESIZE(uint64_t, experience, Experience);
	CC_SYNTHESIZE(string, pimpersonid, Pimpersonid);
	CC_SYNTHESIZE(string, updatedate, Updatedate);
	CC_SYNTHESIZE(string, updateman, Updateman);
	CC_SYNTHESIZE(string, pimworkhistoryid, Pimworkhistoryid);
	
};

#endif