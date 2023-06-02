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
		temp.push_back(sub.getOrg_Name());
		temp.push_back(sub.getJobtitle_Name());
		temp.push_back(sub.getGet_Time());
		temp.push_back(sub.getProfessional_Cate());
		temp.push_back(sub.getJobtitle_Grades());
		temp.push_back(sub.getTitle_Employment_Time());
		temp.push_back(sub.getIssuing_Authority());
		temp.push_back(sub.getJudging_Unit());
		temp.push_back(sub.getB_Highest_Professional_Title());
		data.push_back(temp);
	}

	// 生成数据表表头
	vector<string> head = dao.getHead(query);
	//head.erase(head.begin() + 12,head.end());
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
	JobTitleInfoDAO dao;
	auto resD0 = dao.selectAll(query);
	auto resDTO = JobTitleDTO::createShared();
	resDTO->id = resD0.front().getId();
	resDTO->employee_id = resD0.front().getEmployee_Id();
	resDTO->employee_name = resD0.front().getEmployee_Name();
	resDTO->employee_state = resD0.front().getEmployee_State();
	resDTO->org_name = resD0.front().getOrg_Name();
	resDTO->get_time = resD0.front().getGet_Time();
	resDTO->professional_cate = resD0.front().getProfessional_Cate();
	resDTO->jobtitle_grades = resD0.front().getJobtitle_Grades();
	resDTO->title_employment_time = resD0.front().getTitle_Employment_Time();
	resDTO->org_name = resD0.front().getOrg_Name();
	resDTO->issuing_authority = resD0.front().getIssuing_Authority();
	resDTO->judging_unit = resD0.front().getJudging_Unit();
	resDTO->b_highest_professional_title = resD0.front().getB_Highest_Professional_Title();
	return resDTO;
}

bool JobTitleInfoService::updateData(const JobTitleDTO::Wrapper& dto)
{
	JobTitleInfoDAO dao;
	JobTitleDO data;
	data.setId(dto->id);
	data.setEmployee_Id(dto->employee_id);
	data.setEmployee_Name(dto->employee_name);
	data.setEmployee_State(dto->employee_state);
	data.setOrg_Name(dto->org_name);
	data.setJobtitle_Name(dto->jobtitle_name);
	data.setGet_Time(dto->get_time);
	data.setCertificate_Id(dto->certificate_id);
	data.setProfessional_Cate(dto->professional_cate);
	data.setJobtitle_Grades(dto->jobtitle_grades);
	data.setTitle_Employment_Time(dto->title_employment_time);
	data.setIssuing_Authority(dto->issuing_authority);
	data.setJudging_Unit(dto->judging_unit);
	data.setB_Highest_Professional_Title(dto->b_highest_professional_title);
	return !!dao.update(data);
}
