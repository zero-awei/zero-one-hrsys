#pragma once
#ifndef _DECLARE_TYPE_SERVICE_
#define _DECLARE_TYPE_SERVICE_

#include <list>
#include "domain/do/declareType/DeclareTypeDO.h"
#include "domain/vo/declareList/DeclareListVO.h"
#include "domain/dto/declareType/DeclareTypeDTO.h"
#include "dao/DeclareType/DeclareTypeListDAO.h"

class DeclareTypeService
{
public:
	DeclareTypeListDTO::Wrapper getDeclareTypes();
};

#endif