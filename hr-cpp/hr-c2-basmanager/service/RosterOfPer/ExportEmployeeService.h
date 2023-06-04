#pragma once
#ifndef _EXPORTEMPLOYEE_SERVICE_
#define _EXPORTEMPLOYEE_SERVICE_
#include <list>
#include "domain/vo/RosterOfPer/ExportEmployeeJsonVO.h"
#include "domain/query/RosterOfPer/ExportEmployeeQuery.h"
#include "domain/dto/RosterOfPer/ExportEmployeeDTO.h"

class ExportEmployeeService
{
public:
	// 分页查询所有数据
	ExportEmployeeDTO::Wrapper listAll(const ExportEmployeeQuery::Wrapper& query);
};

#endif // !_EXPORTEMPLOYEE_SERVICE_

