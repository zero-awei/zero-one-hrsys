#pragma once
#ifndef _JOBTITLE_INFORMATION_DAO_H_
#define _JOBTITLE_INFORMATION_DAO_H_
#include "BaseDAO.h"
#include "../../../domain/do/certificate-information/JobTitleInformationDO.h"
#include "../../../domain/query/certificate-information/JobTitleInformationPageQuery.h"

class JobTitleInformationDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const JobTitleInformationPageQuery::Wrapper& query);
	// 分页查询数据
	list<JobTitleInformationDO> selectWithPage(const JobTitleInformationPageQuery::Wrapper& query);
};

#endif //
