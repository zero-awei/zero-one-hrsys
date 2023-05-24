#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/24 23:15:37

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
#ifndef _DO_H_
#define _DO_H_

#include "../DoInclude.h"

/* 试用员工数据库实体 */
/* 数据表：t_pimperson */
class ProbationaryEmployeeDO
{	
	// 员工编号
	CC_SYNTHESIZE(string, id, YGBH);
	// 员工姓名
	CC_SYNTHESIZE(string, name, PIMPERSONNAME);
	// 组织
	CC_SYNTHESIZE(string, zz, ZZ);
	// 部门
	CC_SYNTHESIZE(string, bm, BM);
	// 职务
	CC_SYNTHESIZE(string, zw, ZW);
	// 岗位
	CC_SYNTHESIZE(string, gw, GW);
	// 任职时间
	CC_SYNTHESIZE(string, rzsj, RZSJ);
	// 试用到期时间 
	CC_SYNTHESIZE(string, time, SYDQ);
public:
	ProbationaryEmployeeDO() {};
	// 有参构造函数
	ProbationaryEmployeeDO(string id, string name, string zz, string bm, string zw, string gw, string rzsj, string time)
		: id(id)
		, name(name)
		, zz(zz)
		, bm(bm)
		, zw(zw)
		, gw(gw)
		, rzsj(rzsj)
		, time(time)
	{}
};

#endif // !_DO_H_