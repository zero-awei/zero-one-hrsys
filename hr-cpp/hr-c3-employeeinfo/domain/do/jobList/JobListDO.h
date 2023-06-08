#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/29 11:07:00

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
#ifndef _JOBLISTDO_H_
#define _JOBLISTDO_H_
#include "../DoInclude.h"

class JobListDO
{
	CC_SYNTHESIZE(string, jobName, JobName)
public:
	JobListDO() {
		jobName = "";
	}
};

#endif // !_JOBLISTDO_H_