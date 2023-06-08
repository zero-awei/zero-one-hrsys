#include "stdafx.h"
#include "DeclareController.h"
#include "service/declareType/DeclareTypeService.h"

DeclareListVO::Wrapper DeclareController::execQueryDeclare()
{
	auto vo = DeclareListVO::createShared();
	DeclareTypeService service;
	auto dto = service.getDeclareTypes();
	vo->success(dto);

	return vo;
}