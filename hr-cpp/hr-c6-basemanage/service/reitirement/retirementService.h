#pragma once
#ifndef _RETIREMENTSERVICE_H_
#define _RETIREMENTSERVICE_H_

#include <list>
#include "domain/vo/RetirementVo/RetirementVo.h"
#include "domain/query/RetirementQuery/RetirementQuery.h"
#include "domain/dto/retirement/RetiremetDto.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class retirementService
{
public:
	// 分页查询所有数据
	RetirementPageDTO::Wrapper listAll(const RetirementQuery_gan::Wrapper& query);
};

#endif // !_RETIREMENTSERVICE_H_
