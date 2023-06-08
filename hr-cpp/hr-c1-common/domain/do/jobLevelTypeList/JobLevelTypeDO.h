#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/23 16:58:16

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
#ifndef _JOBLEVELTYPEDO_H_
#define _JOBLEVELTYPEDO_H_

#include "../DoInclude.h"

/**
 * 职称等级类型下拉列表DO
 * 对应数据表：t_srfcodeitem
 * 对应代码表ID：A794C86F-0433-4620-90B7-32CEB0764120
 * 负责人：Andrew
 */
class JobLevelTypeDO
{
	// 代码项名称
	CC_SYNTHESIZE(string, jobLevel, JobLevel);
	// 代码项值
	CC_SYNTHESIZE(string, code, Code);
public:
	JobLevelTypeDO()
	{
		code = "";
		jobLevel = "";
	}

	JobLevelTypeDO(string code_, string level_)
	{
		code = code_;
		jobLevel = level_;
	}
};


#endif // !_JOBLEVELTYPEDO_H_