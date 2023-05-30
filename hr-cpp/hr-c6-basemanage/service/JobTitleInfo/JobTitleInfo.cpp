#include "stdafx.h"
#include "JobTitleInfo.h"
#include "../../dao/JobTitleInfo/JobTitleInfoDAO.h"

exportJobTitleInfoDTO::Wrapper JobTitleInfoService::listAllJobTitle(const JobTitleInfoDTO::Wrapper& query)
{
	auto results = exportJobTitleInfoDTO::createShared();

	JobTitleInfoDAO dao;
	uint64_t count = dao.count(query);
	if (count < 0)
	{
		return results;
	}

	list<JobTitleDo> resultDO = dao.selectAll(query);
	// ½«DO×ª»»³ÉDTO
	for (auto const& sub : resultDO)
	{
		auto dto = JobTitleInfoDTO::createShared();
		dto->EMPLOYEEID = sub.getEmployeeId();
		dto->EMPLOYEENAME = sub.getEmployeeName();
		dto->CREDENTIALS_NUM = sub.getCertId();
		dto->ORGANIZATION_NAME = sub.getOrgName();
		dto->PROFESSORANALYSIS_NAME = sub.getName();
		dto->PROFESSOR_GRADES = sub.getGrades();
		dto->PROFESSOR_DATE = sub.getGetDate();
		dto->PROFESSIONAL_CATEGORY = sub.getCategory();
		dto->professional_name = sub.getPro_Name();
		dto->issuing_authority = sub.getIssuing_Authority();
		dto->judging_unit = sub.getJudging_Unit();
		dto->b_highest_professional_title = sub.getB_Highest_Professional_Title();
		/*ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, 
			EMPLOYEEID, EmployeeId,
			EMPLOYEENAME, EmployeeName,
			CREDENTIALS_NUM, CertId,
			ORGANIZATION_NAME, OrgName,
			PROFESSORANALYSIS_NAME, Name,
			PROFESSOR_GRADES, Grades,
			PROFESSOR_DATE, GetDate,
			PROFESSIONAL_CATEGORY, Category,
			professional_name, Pro_Name,
			issuing_authority, Issuing_Authority,
			judging_unit, Judging_Unit,
			b_highest_professional_title, B_Highest_Professional_Title)*/
		results->addData(dto);
	}
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
