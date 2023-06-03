#pragma once
#ifndef _RRAINEE_SERVICE_
#define _RRAINEE_SERVICE_

// 基础管理 ——人员花名册 ——见习员工 -- cpt

#include <list>
#include "domain/vo/RosterOfPer/RraineeVO.h"
#include "domain/query/RosterOfPer/RraineeQuery.h"
#include "domain/dto/RosterOfPer/RraineeDTO.h"
#include "domain/do/RosterOfPer/RraineeDO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class RraineeService
{
public:
	// 分页查询所有数据
	RraineePageDTO::Wrapper listAll(const RraineeQuery::Wrapper& query);
};

#endif // !_RRAINEE_SERVICE_

