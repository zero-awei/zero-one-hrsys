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

#ifndef _PROBATIONARY_EMPLOYEE_DO_H_
#define _PROBATIONARY_EMPLOYEE_DO_H_

#include "../DoInclude.h"

/* 试用员工数据库实体 */
/* 数据表：t_pimperson  t_pcmsgqmgr */
class ProbationaryEmployeeDO
{	
	
	// 员工编号
	CC_SYNTHESIZE(string, YGBH, YGBH);
	// 员工姓名
	CC_SYNTHESIZE(string, PIMPERSONNAME, PIMPERSONNAME);
	// 组织
	CC_SYNTHESIZE(string, ORMORGNAME, ORMORGNAME);
	// 部门
	CC_SYNTHESIZE(string, ORMORGSECTORNAME, ORMORGSECTORNAME);
	// 职务
	CC_SYNTHESIZE(string, ZW, ZW);
	// 岗位
	CC_SYNTHESIZE(string, ORMPOSTNAME, ORMPOSTNAME);
	// 任职时间
	CC_SYNTHESIZE(string, RZSJ, RZSJ);
	// 试用到期时间 
	CC_SYNTHESIZE(string, SYDQ, SYDQ);
	// 下列为查询使用，非前端传输
	// 人员信息标识  REFERENCES `t_pimperson`
	CC_SYNTHESIZE(string, pimPersonId, pimPersonId);
	// 试岗期管理标识 PRIMARY KEY
	CC_SYNTHESIZE(string, PCMSGQMGRID, PCMSGQMGRID);

public:
	ProbationaryEmployeeDO() {};
	// 有参构造函数
	ProbationaryEmployeeDO(string id, string name, string zz, string bm, string zw, string gw, string rzsj, string time)
		: YGBH(id)
		, PIMPERSONNAME(name)
		, ORMORGNAME(zz)
		, ORMORGSECTORNAME(bm)
		, ZW(zw)
		, ORMPOSTNAME(gw)
		, RZSJ(rzsj)
		, SYDQ(time)
		, pimPersonId(pimPersonId)
		, PCMSGQMGRID(PCMSGQMGRID)
	{}
};

#endif // !_DO_H_