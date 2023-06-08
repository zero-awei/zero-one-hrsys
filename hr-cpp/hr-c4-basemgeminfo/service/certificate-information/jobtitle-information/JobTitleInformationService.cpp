#include "stdafx.h"
#include "JobTitleInformationService.h"
#include"../../../dao/certificate-information/jobtitle-information/JobTitleInformationDAO.h"
//定义分页查询所有职称数据的函数listAll
JobTitleInformationPageDTO::Wrapper JobTitleInformationService::listAll(const JobTitleInformationPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = JobTitleInformationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数,传递到dao层
	JobTitleInformationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<JobTitleInformationDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (JobTitleInformationDO sub : result)
	{
		auto dto = JobTitleInformationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, professoranalysis_name, Professoranalysis_name, credentials_num, Credentials_num, professor_grades, Professor_grades, major, Major, zchqrq, Zchqrq, reviewbody, Reviewbody, lssuingagency, Lssuingagency, employtime, Employtime, enable, Enable, employeeid, Employeeid);
		pages->addData(dto);
	}
	return pages;
}