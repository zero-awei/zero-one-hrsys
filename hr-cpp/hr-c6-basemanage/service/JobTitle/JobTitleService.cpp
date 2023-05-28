#include "stdafx.h"
#include "JobTitleService.h"
#include "./dao/JobTitle/JobTitleDao.h"
#include "Macros.h"

JobTitlePageDTO::Wrapper JobTitleService::listAll(const JobTitleQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = JobTitlePageDTO::createShared();
	pages->pageIndex = query->pageIndex;   // 页面索引 
	pages->pageSize = query->pageSize;     // 页面大小

	// 创建dao对象
	JobTitleDAO dao;
	// 查询数据条数
	uint64_t count = dao.count(query);
	cout << "总条数为：" << count << endl;
	if (count <= 0) {
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages(); // 计算总页数

	// 获取数据
	std::list<JobTitleDO> result = dao.selectAll(query);

	// 将DO转换成DTO
	for (JobTitleDO r : result) {
		auto dto = JobTitleDTO::createShared();
		// 将DO转换为DTO
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, r, employee_id, Employee_Id
			, employee_name, Employee_Name, employee_state, Employee_State,
			org_name, Org_Name, jobtitle_name, Jobtitle_Name,
			get_time, Get_Time, certificate_id, Certificate_Id,
			professional_cate, Professional_Cate,
			professional_name, Professional_Name,
			jobtitle_grades, Jobtitle_Grades,
			issuing_authority, Issuing_Authority,
			judging_unit, Judging_Unit,
			b_highest_professional_title, B_Highest_Professional_Title
		);
		// 将每条数据加入到结果对象中
		pages->addData(dto);
	}
	return pages;
}

JobTitlePageDTO::Wrapper JobTitleService::listByParams(const JobTitleQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = JobTitlePageDTO::createShared();
	pages->pageIndex = query->pageIndex;   // 页面索引 
	pages->pageSize = query->pageSize;     // 页面大小

	// 创建dao对象
	JobTitleDAO dao;
	// 查询数据条数
	uint64_t count = dao.count(query);
	cout << "总条数为：" << count << endl;
	if (count <= 0) {
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages(); // 计算总页数

	// 获取数据
	std::list<JobTitleDO> result = dao.selectAll(query);

	// 将DO转换成DTO
	for (JobTitleDO r : result) {
		auto dto = JobTitleDTO::createShared();
		// 将DO转换为DTO
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, r, employee_id, Employee_Id
			, employee_name, Employee_Name, employee_state, Employee_State,
			org_name, Org_Name, jobtitle_name, Jobtitle_Name,
			get_time, Get_Time, certificate_id, Certificate_Id,
			professional_cate, Professional_Cate,
			professional_name, Professional_Name,
			jobtitle_grades, Jobtitle_Grades,
			issuing_authority, Issuing_Authority,
			judging_unit, Judging_Unit,
			b_highest_professional_title, B_Highest_Professional_Title
		);
		// 将每条数据加入到结果对象中
		pages->addData(dto);
	}
	return pages;
}

uint64_t JobTitleService::addData(const JobTitleDTO::Wrapper& dto)
{
	// 组装DO数据
	JobTitleDO data;
	data.setId(dto->id.getValue(0));
	data.setEmployee_Id(dto->employee_id.getValue(0));
	data.setEmployee_Name(dto->employee_name.getValue(""));
	data.setJobtitle_Name(dto->jobtitle_name.getValue(""));
	data.setEmployee_State(dto->employee_state.getValue(""));
	data.setOrg_Name(dto->org_name.getValue(""));
	data.setGet_Time(dto->get_time.getValue(""));
	data.setCertificate_Id(dto->certificate_id.getValue(0));
	data.setJobtitle_Grades(dto->jobtitle_grades.getValue(""));
	data.setProfessional_Cate(dto->professional_cate.getValue(""));
	data.setProfessional_Name(dto->professional_name.getValue(""));
	data.setIssuing_Authority(dto->issuing_authority.getValue(""));
	data.setJudging_Unit(dto->judging_unit.getValue(""));
	data.setTitle_Employment_Time(dto->title_employment_time.getValue(""));
	data.setB_Highest_Professional_Title(dto->b_highest_professional_title.getValue(""));
	// 执行数据添加
	JobTitleDAO dao;
	return dao.addTitle(data);
}

uint64_t JobTitleService::removeData(const JobTitleDeleteDTO::Wrapper& dto)
{
	JobTitleDAO dao;
	return dao.removeById(dto);
}
