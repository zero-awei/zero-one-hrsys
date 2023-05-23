#include "stdafx.h"
#include "DeclareController.h"

DeclareListVO::Wrapper DeclareController::execQueryDeclare() 
{
	auto dto = DeclareTypeListDTO::createShared();
	auto vo = DeclareListVO::createShared();
	auto a = DeclareDTO::createShared(1,"A");
	dto->declareList->push_back(a);

	auto b = DeclareDTO::createShared(2, "B");
	dto->declareList->push_back(b);

	auto c = DeclareDTO::createShared(3, "C");
	dto->declareList->push_back(c);

	vo->success(dto);

	return vo;
}