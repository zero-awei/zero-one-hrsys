#pragma once/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/30 23:20:18

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
#ifndef _LEAVEANDDISMISSREASONDO_H_
#define _LEAVEANDDISMISSREASONDO_H_
#include "../DoInclude.h"
/**
 * 离职/解聘原因下拉列表
 * 负责人：远翔
 */
class LeaveAndDismissReasonDO
{
	// 原因下拉列表
	CC_SYNTHESIZE(string, reason, Reason);

	// 原因code
	CC_SYNTHESIZE(int, code, Code);
};

#endif // !_LEAVEANDDISMISSREASONDO_H_