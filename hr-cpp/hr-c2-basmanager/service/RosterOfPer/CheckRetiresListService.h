#pragma once
/*
人员花名册-离退休人员-分页查询员工列表--pine
*/
#ifndef _CHECK_RETIRES_LIST_SERVICE_
#define _CHECK_RETIRES_LIST_SERVICE_
#include <list>
#include "domain/query/RosterOfPer/CheckRetiresListQuery.h"
#include "domain/dto/RosterOfPer/CheckRetiresListDTO.h"
#include "domain/vo/RosterOfPer/CheckRetiresListVO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class CheckRetiresListService
{
public:
	// 分页查询所有数据
	CheckRetiresListPageDTO::Wrapper listAll(const CheckRetiresListQuery::Wrapper& query);

};

#endif // !_CHECK_RETIRES_LIST_SERVICE_

