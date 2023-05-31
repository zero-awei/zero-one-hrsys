#pragma once
#ifndef _QUALIFICATION_SERVICE_
#define _QUALIFICATION_SERVICE_
#include <list>
#include "domain/vo/Qualification/QualificationVO.h"
#include "domain/query/Qualification/QualificationQuery.h"
#include "domain/dto/Qualification/QualificationDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class QualificationService
{
public:
	// 分页查询所有数据
	QualificationPageDTO::Wrapper listAll(const QualificationQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const QualificationDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const QualificationDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_QUALIFICATION_SERVICE_