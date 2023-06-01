#include "stdafx.h"
#include "JobTitleInfo.h"
#include "../../dao/JobTitleInfo/JobTitleInfoDAO.h"
#include "../../uselib/excel/ExportExcel.h"
#include "../../uselib/fastdfs/UseFastDfs.h"

std::string JobTitleInfoService::listAllJobTitle(const JobTitleDTO::Wrapper& query)
{
	std::string url;
	JobTitleInfoDAO dao;
	auto countQuery = JobTitleQuery::createShared();
	countQuery->employee_id = query->employee_id;
	countQuery->employee_name = query->employee_name;
	countQuery->org_name = query->org_name;
	countQuery->jobtitle_name = query->jobtitle_name;
	countQuery->jobtitle_grades = query->jobtitle_grades;
	countQuery->b_highest_professional_title = query->b_highest_professional_title;
	uint64_t count = dao.count(countQuery);
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
	vector<string> head/* = dao.getHead()*/;
	head.erase(head.begin() + 12,head.end());
	data.insert(data.begin(), head);
	// 生成Excel
	ExportExcel excel;
	string filename = excel.exportExcel(data);
	UseFastDfs dfs("8.130.87.15");
	url = dfs.uploadWithNacos(filename);
	return url;
}

JobTitleDTO::Wrapper JobTitleInfoService::queryDataDetail(const JobTitleDTO::Wrapper& query)
{
	return JobTitleDTO::Wrapper();
}

bool JobTitleInfoService::updateData(const JobTitleDTO::Wrapper& dto)
{
	return false;
}
