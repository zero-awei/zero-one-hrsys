#include "stdafx.h"
#include "DeclareService.h"

DeclareDTO::Wrapper DeclareService::declareAll(const DeclareQuery::Wrapper& query)
{
	auto declareTypes = DeclareDTO::createShared();
	
	return declareTypes;
}

