#pragma once
#ifndef _TITLEDO_H_
#define _TITLEDO_H_

#include "../DoInclude.h"
/**
 * 职称目录信息实体
 */
class TitleDO
{
private:
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, name, Name);
	CC_SYNTHESIZE(string, sta, Sta);
	CC_SYNTHESIZE(string, org, Org);
	CC_SYNTHESIZE(string, titlename, Titlename);
	CC_SYNTHESIZE(string, acquiredate, Acquiredate);
	CC_SYNTHESIZE(string, certificateid, Certificateid);
	CC_SYNTHESIZE(string, major, Major);
	CC_SYNTHESIZE(string, titlelevel, Titlelevel);
	CC_SYNTHESIZE(string, titlegetmonth, Titlegetmonth);
	CC_SYNTHESIZE(string, titleemploymonth, Titleemploymonth);
	CC_SYNTHESIZE(string, titlegetorg, Titlegetorg);
	CC_SYNTHESIZE(string, titledesorg, Titledesorg);
	CC_SYNTHESIZE(string, highest, Highest);


public:
	TitleDO() {}
};

#endif