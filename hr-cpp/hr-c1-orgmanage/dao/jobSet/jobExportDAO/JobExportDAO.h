//2023年5月28日
//作者：狗皮电耗子
//岗位导出的DAO
#pragma once
#ifndef _JOB_EXPORT_DAO_
#define _JOB_EXPORT_DAO_

#include "BaseDAO.h"
#include "domain/query/postSet/PostDetailQuery.h"
#include "domain/do/postSet/PostDetailDO.h"
#include "JobExportMapper.h"

class JobExportDAO : public BaseDAO
{
public:
	std::list<PostDetailDO> exportJobInfo(const PostDetailQuery::Wrapper& query);

	vector<std::string> getJobInfoHead();
};


#endif // !_JOB_EXPORT_DAO_



