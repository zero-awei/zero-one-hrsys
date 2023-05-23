#pragma once
#ifndef _Assign_Info_Query_SERVICE_
#define _Assign_Info_Query_SERVICE_
#include <list>
#include "domain/vo/assignInfo/AssignInfoQueryVO.h"
#include "domain/query/assignInfo/AssignInfoQuery.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class AssignInfoQueryService
{
public:
	// 分页查询所有数据
	AssignInfoQuery::Wrapper listAll(const AssignInfoQuery::Wrapper& query);
};

#endif //!_Assign_Info_Query_SERVICE_