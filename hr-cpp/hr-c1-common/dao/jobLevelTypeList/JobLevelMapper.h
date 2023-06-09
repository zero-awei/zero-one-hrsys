#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/05/26 22:54:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _JOBLEVELMAPPER_H_
#define _JOBLEVELMAPPER_H_

#include "Mapper.h"
#include "domain/do/jobLevelTypeList/JobLevelTypeDO.h"

/**
 * 职称等级类型下拉列表数据库字段匹配映射
 * 负责人：咫尺之书
 */
class JobLevelMapper : public Mapper<JobLevelTypeDO>
{
public:
	JobLevelTypeDO mapper(ResultSet* result) const override
	{
		JobLevelTypeDO data;
		data.setCode(result->getString(1));
		data.setJobLevel(result->getString(2));
		return data;
	}
};

#endif // !_JOBLEVELMAPPER_H_