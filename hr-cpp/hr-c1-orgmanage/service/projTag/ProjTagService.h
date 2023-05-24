#pragma once
/*
 Copyright Zero One Star. All rights reserved.

<<<<<<<< HEAD:hr-cpp/hr-c1-common/domain/do/costTypeList/CostType.h
 @Author: Andrew211vibe
 @Date: 2023/05/23 18:51:56
========
 @Author: yuanxiang
 @Date: 2023/05/23 17:01:55
>>>>>>>> origin/c1-orgmanage-yuanxiang:hr-cpp/hr-c1-orgmanage/service/projTag/ProjTagService.h

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
<<<<<<<< HEAD:hr-cpp/hr-c1-common/domain/do/costTypeList/CostType.h
#ifndef _COSTTYPELIST_H_
#define _COSTTYPELIST_H_

#include "../DoInclude.h"

/**
 * 费用类别下拉列表
 * 对应数据表：t_pimexpaccount
 * 负责人：Andrew
 */
class CostTypeDO
{
	// 费用类别代码
	CC_SYNTHESIZE(int, code, Code);
	// 费用类别名
	CC_SYNTHESIZE(string, costType, CostType);
};


#endif // !_COSTTYPELIST_H_
========
#ifndef _PROJTAGSERVICE_H_
#define _PROJTAGSERVICE_H_
#include "domain/dto/projTag/ProjTagDTO.h"

/**
 * 项目标签Service
 * 负责人：远翔
 */
class ProjTagService
{
public:
	uint64_t saveData(const ProjTagDTO::Wrapper& dto);
};

#endif // !_PROJTAGSERVICE_H_
>>>>>>>> origin/c1-orgmanage-yuanxiang:hr-cpp/hr-c1-orgmanage/service/projTag/ProjTagService.h
