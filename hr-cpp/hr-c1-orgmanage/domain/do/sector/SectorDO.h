#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/22 20:38:39

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
#ifndef _SECTORDO_H_
#define _SECTORDO_H_
#include "../DoInclude.h"
/**
 * 编制查询DO
 * 负责人：远翔
 */
class SectorDO
{
	// 项目基本情况
	// 数据库存储类型为 text
	CC_SYNTHESIZE(string, projBasicInfo, ProjBasicInfo);

	// 更新人
	CC_SYNTHESIZE(string, updateman, Updateman);

	// 地区分类
	// 数据库存储类型为 text
	CC_SYNTHESIZE(string, areaClassify, AreaClassify);

	// 版本
	CC_SYNTHESIZE(double, edition, Edition);

	// 上班时间
	CC_SYNTHESIZE(string, officeTime, OfficeTime);

	// 下班时间
	CC_SYNTHESIZE(string, leaveTime, LeaveTime);

	// 启停标识
	CC_SYNTHESIZE(string, startStopSign, StartStopSign);

	// 建立时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
};

#endif // !_SECTORDO_H_