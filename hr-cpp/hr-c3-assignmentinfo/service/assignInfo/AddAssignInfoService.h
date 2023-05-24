#pragma once
#ifndef _Add_Assign_Info_SERVICE_
#define _Add_Assign_Info_SERVICE_
#include <list>
#include "domain/vo/assignInfo/AddAssignInfoVO.h"
#include "domain/dto/assignInfo/AddAssignInfoDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class AddAssignInfoService
{
public:
	// 分页查询所有数据
	// 保存数据
	uint64_t saveData(const AddAssignInfoDTO::Wrapper& dto);
};

#endif // !_Add_Assign_Info_SERVICE_