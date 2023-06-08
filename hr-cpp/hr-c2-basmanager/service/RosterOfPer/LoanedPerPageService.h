#pragma once
#ifndef _LOANEDPERPAGE_SERVICE_
#define _LOANEDPERPAGE_SERVICE_
#include <list>
#include "domain/query/RosterOfPer/LoanedPerPageQuery.h"
#include "domain/dto/RosterOfPer/LoanedPerPageDTO.h"
#include "domain/vo/RosterOfPer/LoanedPerPageVO.h"

/*
（人员花名册-借调人员-分页查询员工列表（导出本页在前端完成））--luoluo
*/
class LoanedPerPageService
{
public:
	// 分页查询所有数据
	LoanedPerPageDTO::Wrapper listAll(const LoanedPerPageQuery::Wrapper& query);
	//导出功能，返回fastdfs路径
	std::string exportData(const LoanedPerPageQuery::Wrapper& query);
};

#endif // !_LOANEDPERPAGE_SERVICE_

