#include "stdafx.h"
#include "JobTitleInfo.h"
#include "../../dao/JobTitleInfo/JobTitleInfoDAO.h"
#include "../../uselib/excel/ExportExcel.h"
#include "../../uselib/fastdfs/UseFastDfs.h"

std::string JobTitleInfoService::listAllJobTitle(const JobTitleInfoDTO::Wrapper& query)
{
	std::string url;
	JobTitleInfoDAO dao;
	uint64_t count = dao.count(query);
	if (count < 0)
	{
		return url;
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
	head.erase(head.begin() + 13);
	data.insert(data.begin(), head);
	// 生成Excel
	ExportExcel excel;
	string filename = excel.exportExcel(data);
	UseFastDfs dfs("8.130.87.15");
	url = dfs.uploadWithNacos(filename);
	return url;
}

JobTitleInfoDTO::Wrapper JobTitleInfoService::queryDataDetail(const JobTitleInfoDTO::Wrapper& query)
{
	return JobTitleInfoDTO::Wrapper();
}

bool JobTitleInfoService::updateData(const JobTitleInfoDTO::Wrapper& dto)
{
	return false;
}
