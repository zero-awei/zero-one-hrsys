#pragma once
#ifndef _Assign_Info_Query_SERVICE_
#define _Assign_Info_Query_SERVICE_
#include <list>
#include "domain/vo/assignInfo/AssignInfoVO.h"
#include "domain/query/assignInfo/AssignInfoQuery.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class AssignInfoService
{
public:
	// 分页查询所有数据
	AssignInfoPageDTO::Wrapper listAll(const AssignInfoQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const AssignInfoDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const AssignInfoDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(string id);
};

#endif //!_Assign_Info_Query_SERVICE_