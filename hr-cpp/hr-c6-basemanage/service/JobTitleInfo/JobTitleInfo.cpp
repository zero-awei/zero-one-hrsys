#include "stdafx.h"
#include "JobTitleInfo.h"
#include "../../dao/JobTitleInfo/JobTitleInfoDAO.h"

JobTitleInfoDTO::Wrapper JobTitleInfoService::listAllJobTitle(const JobTitleInfoDTO::Wrapper& query)
{
	auto results = JobTitleInfoDTO::createShared();

	JobTitleInfoDAO dao;
	uint64_t count = dao.count(query);
	if (count < 0)
	{
		return results;
	}

	results.
}

JobTitleInfoDTO::Wrapper JobTitleInfoService::queryDataDetail(const JobTitleInfoDTO::Wrapper& query)
{
	return JobTitleInfoDTO::Wrapper();
}

bool JobTitleInfoService::updateData(const JobTitleInfoDTO::Wrapper& dto)
{
	return false;
}
