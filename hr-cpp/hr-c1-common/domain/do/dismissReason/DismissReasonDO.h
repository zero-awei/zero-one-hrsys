#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 远翔
 @Date: 2023/05/17 22:56:57

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
#ifndef _DISMISSREASONDO_H_
#define _DISMISSREASONDO_H_

#include "../DoInclude.h"
/**
 * 解聘原因下拉列表DO
 * 负责人：远翔
 */
class DismissReasonDO
{
	// 解聘原因下拉列表
	CC_SYNTHESIZE(string, dismissreason, Dismissreason);

	// 原因Code
	CC_SYNTHESIZE(int, code, Code);
};

#endif // !_DISMISSREASONDO_H_
