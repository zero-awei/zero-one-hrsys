#pragma once
#ifndef _DECLARE_SERVICE_
#define _DECLARE_SERVICE_
#include <list>
#include "domain/vo/declare/DeclareVO.h"
#include "domain/query/declare/DeclareQuery.h"
#include "domain/dto/declare/DeclareDTO.h"

class DeclareService
{
public:
	DeclareDTO::Wrapper declareAll(const DeclareQuery::Wrapper& query);
};

#endif