#pragma once
#ifndef _DELWORKHISTORYDO_H_
#define _DELWORKHISTORYDO_H_

#include "../../GlobalInclude.h"
#include <list>

class t_pimarchivesDelDO
{
	CC_SYNTHESIZE(std::list<std::string>, deleteById, DeleteById);
};

#endif // !_DELWORKHISTORYDO_H_