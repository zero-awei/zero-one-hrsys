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
		/*dto->id = sub.getId();
		dto->name = sub.getName();
		dto->sex = sub.getSex();
		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)*/
		results->addData(dto);
	}
	return pages;
}

JobTitleInfoDTO::Wrapper JobTitleInfoService::queryDataDetail(const JobTitleInfoDTO::Wrapper& query)
{
	return JobTitleInfoDTO::Wrapper();
}

bool JobTitleInfoService::updateData(const JobTitleInfoDTO::Wrapper& dto)
{
	return false;
}
