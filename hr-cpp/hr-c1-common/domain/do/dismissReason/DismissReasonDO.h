#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/21 21:30:35

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
};

#endif // !_DISMISSREASONDO_H_