#pragma once

/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanchen
 @Date: 2023/05/27 21:26:49

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
#ifndef _JOBCATEGORYDO_H_
#define _JOBCATEGORYDO_H_
#include "../DoInclude.h"
/**
 * 岗位类型下拉列表
 * 负责人：yuanchen
 */
class JobCategoryDO
{
	CC_SYNTHESIZE(string, jobCategory, JobCategory);
	CC_SYNTHESIZE(string, code, Code);
	
public:
	JobCategoryDO()
	{
		jobCategory = "";
		code = "";
	}
	JobCategoryDO(string code_, string jobCategory_)
	{
		code = code_;
		jobCategory = jobCategory_;
	}
};

#endif // !_JOBCATEGORYDO_H_