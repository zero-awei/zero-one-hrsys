#pragma once
#ifndef _CONTRACTCATEGORYDO_H_
#define _CONTRACTCATEGORYDO_H_

#include "../DoInclude.h"

class ContractCategoryDO
{
	CC_SYNTHESIZE(std::string, id, Id);
	CC_SYNTHESIZE(std::string, name, Name);
	CC_SYNTHESIZE(std::string, createDate, CreateDate);
	CC_SYNTHESIZE(std::string, enable, Enable);
	CC_SYNTHESIZE(std::string, createMan, CreateMan);
	CC_SYNTHESIZE(std::string, updateMan, UpdateMan);
	CC_SYNTHESIZE(std::string, updateDate, UpdateDate);
	CC_SYNTHESIZE(std::string, sbm, Sbm);
	CC_SYNTHESIZE(std::string, lx, Lx);
	CC_SYNTHESIZE(std::string, ormOrgId, OrmOrgId);
};

#endif // !_CONTRACTCATEGORYDO_H_
