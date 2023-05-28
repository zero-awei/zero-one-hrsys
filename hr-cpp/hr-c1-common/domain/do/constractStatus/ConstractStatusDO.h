#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/28 10:24:20

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
#ifndef _CONSTRACTSTATUSDO_H_
#define _CONSTRACTSTATUSDO_H_
#include "../DoInclude.h"
/**
 * 合同状态DO
 * 负责人：远翔
 */
class ConstractStatusDO
{
	// 合同状态下拉列表
	CC_SYNTHESIZE(string, constractStatus, ConstractStatus);

	// 合同状态Code
	CC_SYNTHESIZE(int, code, Code);
};

#endif // !_CONSTRACTSTATUSDO_H_