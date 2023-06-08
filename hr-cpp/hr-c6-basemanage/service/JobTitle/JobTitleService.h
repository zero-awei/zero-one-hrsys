#pragma once

#ifndef _JOBTITLE_SERVICE_
#define _JOBTITLE_SERVICE_

#include "./domain/dto/JobTitle/JobTitleDTO.h"
#include "domain/query/PageQuery.h"
#include "./domain/query/JobTitle/JobTitleQuery.h"

class JobTitleService {
public:

	// 分页查询职称信息--无参--所有数据
	JobTitlePageDTO::Wrapper listAll(const JobTitleQuery::Wrapper& query);
	// 分页查询通过id或name进行模糊查询
	JobTitlePageDTO::Wrapper listByParams(const JobTitleQuery::Wrapper& query);
	// 需新增职称
	uint64_t addData(const JobTitleAddDTO::Wrapper& dto);
	// 删除职称，支持批量删除
	uint64_t removeData(const JobTitleDeleteDTO::Wrapper& dto);

	// 上传文件
	String postFile(const String& fileBody, const String& suffix);
};

#endif // !1
