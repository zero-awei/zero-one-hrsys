#pragma once
#ifndef _JOBTITLE_INFO_H_
#define _JOBTITLE_INFO_H_
#include "domain/vo/JobTitle/JobTitleJsonVO.h"
#include "domain/do/JobTitle/JobTitleDo.h"
#include "domain/dto/JobTitle/JobTitleDTO.h"
#include "domain/vo/BaseJsonVO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class JobTitleInfoService
{
public:
	// 查询所有职称信息
	std::string listAllJobTitle(const JobTitleDTO::Wrapper& query);
	// 查询指定数据详细
	JobTitleDTO::Wrapper queryDataDetail(const JobTitleDTO::Wrapper& query);
	// 修改数据
	bool updateData(const JobTitleDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_