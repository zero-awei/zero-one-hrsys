#pragma once
#ifndef _CONTRACTCATEGORYDO_H_
#define _CONTRACTCATEGORYDO_H_

#include "../DoInclude.h"

class ContractCategoryDO
{
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, name, Name);
	// 你可以根据需要添加其他变量
};

#endif // !_CONTRACTCATEGORYDO_H_