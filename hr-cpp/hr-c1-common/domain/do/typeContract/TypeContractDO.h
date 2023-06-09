#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanchen
 @Date: 2023/05/23 21:46:57

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
#ifndef _TYPECONTRACTDO_H_
#define _TYPECONTRACTDO_H_

#include "../DoInclude.h"
/**
 * 合同类型下拉列表
 * 负责人：yuanchen
 */
class TypeContractDO
{
	// 合同类型名称
	CC_SYNTHESIZE(string, typeContract, TypeContract);
	// 合同类型代码
	CC_SYNTHESIZE(string, typeCode, TypeCode);
};

#endif // !_TYPECONTRACTDO_H_