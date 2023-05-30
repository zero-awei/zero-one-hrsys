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
	//// 保存数据
	//uint64_t saveData(const CheckCerListDTO::Wrapper& dto);
	//// 修改数据
	//bool updateData(const CheckCerListDTO::Wrapper& dto);
	//// 通过ID删除数据
	//bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

