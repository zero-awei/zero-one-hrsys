#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/29 22:00:52

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
#ifndef _JOBLISTMAPPER_H_
#define _JOBLISTMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/jobList/JobListDO.h"


class JobListMapper : public Mapper<JobListDO>
{
public:
	JobListDO mapper(ResultSet* res)const override
	{
		JobListDO data;
		data.setJobName(res->getString(1));
		return data;
	}

};

#endif // !_JOBLISTMAPPER_H_