#pragma once
#ifndef _RETIREMENTSERVICE_H_
#define _RETIREMENTSERVICE_H_

#include <list>
#include "domain/vo/RetirementVo/contractManagerVo.h"
#include "domain/query/RetirementQuery/contractManagerQuery.h"
#include "domain/dto/retirement/contractManagerDto.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class contractManagerService
{
public:
	// 分页查询所有数据
	contractmanagerPageDTO::Wrapper listAll(const contractManagerQuery::Wrapper& query);

};

#endif // !_RETIREMENTSERVICE_H_
