#pragma once
#ifndef _Assign_Info_Query_SERVICE_
#define _Assign_Info_Query_SERVICE_
#include <list>
#include "domain/vo/assignInfo/AssignInfoVO.h"
#include "domain/query/assignInfo/AssignInfoQuery.h"
#include "domain/query/assignInfo/AssignExportQuery.h"
#include "domain/vo/assignInfo/ImportAssignInfoVO.h"
#include "domain/dto/assignInfo/ImportAssignInfoDTO.h"
#include "domain/dto/assignInfo/MulDeleteAssignInfoDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class AssignInfoService
{
public:
	// 分页查询所有数据
	AssignInfoPageDTO::Wrapper listAll(const AssignInfoQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const AssignInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改数据
	bool updateData(const AssignInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	// 通过ID删除数据
	bool removeData(string id);
	// 查询详细数据
	AssignInfoDTO::Wrapper QueryDetail(const AssignInfoDTO::Wrapper& dto);
	//导入员工信息(批量新增)
	ImportInfoJsonVO::Wrapper addMultiAssignInfo(const ImportAssignInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	//批量删除
	bool removeMulData(const MulDeleteAssignInfoDTO::Wrapper& dto);
	string exportData(const AssignExportQuery::Wrapper& query);
};

#endif //!_Assign_Info_Query_SERVICE_