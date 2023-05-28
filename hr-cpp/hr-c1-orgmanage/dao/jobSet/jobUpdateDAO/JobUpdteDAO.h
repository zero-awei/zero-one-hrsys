//2023年5月28日
//作者：狗皮电耗子
//岗位更新的DAO
#pragma once
#ifndef _JOB_UPDATE_DAO_
#define _JOB_UPDATE_DAO_

#include "BaseDAO.h"
#include "domain/do/postSet/PostDetailDO.h"

class JobUpdteDAO : public BaseDAO
{
public:
	bool updateJob(const PostDetailDO& data);
};

#endif // !_JOB_UPDATE_DAO_

