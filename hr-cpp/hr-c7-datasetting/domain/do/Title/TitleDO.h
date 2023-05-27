#pragma once
#ifndef _TITLEDO_H_
#define _TITLEDO_H_

#include "../DoInclude.h"
/**
 * 职称目录信息实体
 */
class TitleDO
{

	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, name, Name);

public:
	TitleDO() {}
	TitleDO(string Id,string Name) 
	{
		this->id = Id;
		this->name = Name;
		// 你可以根据需要添加其他变量
	}
};

#endif