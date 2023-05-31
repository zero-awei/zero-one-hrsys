/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/30 11:13:19

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

#include "stdafx.h"
#include "JobListService.h"
#include "../../dao/jobList/JobListDAO.h"

JobListPageQuery::Wrapper JobListService::listAll(const JobListQuery::Wrapper& query)
{
	auto pagee = JobListPageQuery::createShared();
	pagee->pageIndex = query->pageIndex;
	pagee->pageSize = query->pageSize;

	JobListDAO dao;
	uint64_t count = dao.count(query);
	if ( count <= 0 )
	{
		return pagee;
	}

	pagee->total = count;
	pagee->calcPages();
	list<JobListDO> res = dao.selectJobList(query);
	for (JobListDO c : res)
	{
		auto dto = JobListQuery::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, c, jobName, JobName);
		pagee->addData(dto);
	}
	return pagee;
}
