#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
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
#ifndef _ARCHIVESLEVELDO_H_
#define _ARCHIVESLEVELDO_H_

#include "../DoInclude.h"
/**
 * 档案室层级下拉列表DO
 * 负责人：咫尺之书
 */
class ArchivesLevelDO
{
	// 代码项名称
	CC_SYNTHESIZE(string, archivesLevel, ArchivesLevel);
	// 代码项值
	CC_SYNTHESIZE(int, code, Code);
};

#endif // !_ARCHIVESLEVELDO_H_