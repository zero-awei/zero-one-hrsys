#pragma once
/*
（人员花名册-借调人员-分页查询员工列表（导出本页在前端完成））--luoluo
*/
#ifndef _LOANEDPERPAGE_SERVICE_
#define _LOANEDPERPAGE_SERVICE_
#include <list>
#include "domain/query/RosterOfPer/LoanedPerPageQuery.h"
#include "domain/dto/RosterOfPer/LoanedPerPageDTO.h"
#include "domain/vo/RosterOfPer/LoanedPerPageVO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class LoanedPerPageService
{
public:
	// 分页查询所有数据
	LoanedPerPageDTO::Wrapper listAll(const LoanedPerPageQuery::Wrapper& query);
};

#endif // !_LOANEDPERPAGE_SERVICE_

