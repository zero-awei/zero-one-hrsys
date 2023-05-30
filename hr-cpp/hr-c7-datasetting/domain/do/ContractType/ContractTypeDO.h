#pragma once
#ifndef _CONTRACTDO_H_
#define _CONTRACTDO_H_

#include "../DoInclude.h"

class ContractTypeDO
{
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, name, Name);
public:
	ContractTypeDO() {
		id = "";
		name = "";
	}
	ContractTypeDO(string id, string name) {
		this->id = id;
		this->name = name;
	}
};

#endif // !_CONTRACTDO_H_