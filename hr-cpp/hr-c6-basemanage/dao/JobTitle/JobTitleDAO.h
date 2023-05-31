#pragma once

#ifndef _JOBTITLE_DAO_
#define _JOBTITLE_DAO_

#include "BaseDAO.h"
#include "./domain/do/JobTitle/JobTitleDo.h"
#include "./domain/query/JobTitle/JobTitleQuery.h"
#include "./domain/dto/JobTitle/JobTitleDTO.h"

class JobTitleDAO :public BaseDAO {
public:
	// 查询数据条数
	uint64_t count(const JobTitleQuery::Wrapper& query);
	// 查询数据结果
	list<JobTitleDO> selectAll(const JobTitleQuery::Wrapper& query);

	// 添加职称
	uint64_t addTitle(const JobTitleAddDO& aObj);

	// 批量删除职称
	uint64_t removeById(const JobTitleDeleteDTO::Wrapper& list);

	/**通过id获取人员信息id*/
	list<JobTitleAddDO> getPinpersonid(const JobTitleAddDO& aObj);

	//// 根据职称名称获取职称目录编号
	//list<JobTitleAddDO> getPinpersonid(const JobTitleAddDO& aObj);

	//// 根据职称等级，获取职称等级代码
	//list<JobTitleAddDO> getPinpersonid(const JobTitleAddDO& aObj);
};

#endif