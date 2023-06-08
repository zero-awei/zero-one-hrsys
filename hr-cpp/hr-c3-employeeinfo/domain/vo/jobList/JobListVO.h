#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/31 21:21:12

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
#ifndef _JOBLISTVO_H_
#define _JOBLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../query/jobList/JobListQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class JobListJsonVO : public JsonVO<JobListQuery::Wrapper>
{
	DTO_INIT(JobListJsonVO, JsonVO<JobListQuery::Wrapper>);
	
};
class JobListPageJsonVO : public JsonVO<JobListPageQuery::Wrapper>
{
	DTO_INIT(JobListPageJsonVO, JsonVO<JobListPageQuery::Wrapper>);

};
#include OATPP_CODEGEN_END(DTO)

#endif // !_JOBLISTVO_H_