#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/17 20:13:24

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
#ifndef _JOBLISTQUERY_H_
#define _JOBLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/* *
* 分页查询岗位列表
* 执行人：Detachment
*/
class JobListQuery : public PageQuery
{
	DTO_INIT(JobListQuery, PageQuery);
	
	DTO_FIELD(String, jobName);
	DTO_FIELD_INFO(jobName) {
		info->description = ZH_WORDS_GETTER("employee.field.jobList");
	}
	// API_DTO_FIELD_DEFAULT(UInt64, total, ZH_WORDS_GETTER("employee.field.total"));
};
class JobListPageQuery : public PageDTO<JobListQuery::Wrapper>
{
	DTO_INIT(JobListPageQuery, PageDTO<JobListQuery::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_JOBLISTQUERY_H_