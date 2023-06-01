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
	if (count <= 0)
	{
		return url;
	}

	list<JobTitleDO> resultDO = dao.selectAll(query);
	vector<vector<string>> data;
	// 将DO转换成二维数组
	for (auto const& sub : resultDO)
	{
		vector<string> temp;
		temp.push_back(sub.getEmployee_Id());
		temp.push_back(sub.getEmployee_Name());
		temp.push_back(sub.getCertificate_Id());
		temp.push_back(sub.getOrg_Name());
		temp.push_back(sub.getJobtitle_Name());
		temp.push_back(sub.getJobtitle_Grades());
		temp.push_back(sub.getGet_Time());
		temp.push_back(sub.getProfessional_Cate());
		temp.push_back(sub.getProfessional_Name());
		temp.push_back(sub.getIssuing_Authority());
		temp.push_back(sub.getJudging_Unit());
		temp.push_back(sub.getB_Highest_Professional_Title());
		data.push_back(temp);
	}

	// 生成数据表表头
	vector<string> head = dao.getHead();
	head.erase(head.begin() + 12,head.end());
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
