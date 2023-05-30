#include "stdafx.h"
#include "JobTitleInfo.h"
#include "../../dao/JobTitleInfo/JobTitleInfoDAO.h"

StringJsonVO::Wrapper JobTitleInfoService::listAllJobTitle(const JobTitleInfoDTO::Wrapper& query)
{
	auto result = StringJsonVO::createShared();

	JobTitleInfoDAO dao;
	uint64_t count = dao.count(query);
	if (count < 0)
	{
		return result;
	}

	list<JobTitleDo> resultDO = dao.selectAll(query);
	vector<vector<string>> data;
	// 将DO转换成二维数组
	for (auto const& sub : resultDO)
	{
		vector<string> temp;
		temp.push_back(sub.getEmployeeId());
		temp.push_back(sub.getEmployeeName());
		temp.push_back(sub.getCertId());
		temp.push_back(sub.getOrgName());
		temp.push_back(sub.getName());
		temp.push_back(sub.getGrades());
		temp.push_back(sub.getGetDate());
		temp.push_back(sub.getCategory());
		temp.push_back(sub.getPro_Name());
		temp.push_back(sub.getIssuing_Authority());
		temp.push_back(sub.getJudging_Unit());
		temp.push_back(sub.getB_Highest_Professional_Title()?"t":"f");
		data.push_back(temp);
	}

	// 生成数据表表头
	vector<string> head = dao.getHead();
	head.erase(head.begin() + 6);
	return results;
}

JobTitleInfoDTO::Wrapper JobTitleInfoService::queryDataDetail(const JobTitleInfoDTO::Wrapper& query)
{
	return JobTitleInfoDTO::Wrapper();
}

bool JobTitleInfoService::updateData(const JobTitleInfoDTO::Wrapper& dto)
{
	return false;
}
