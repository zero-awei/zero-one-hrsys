#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _SECONDED_PERSONNEL_DO_
#define _SECONDED_PERSONNEL_DO_
#include "../DoInclude.h"

/*
 离退休员工DO--（人员花名册）--pine
 (对应数据库表t_pcmydjdmx：异动借调明细 与 t_pcmydmx：异动明细)
 */
class SecondedPersonnelDO
{
	// 员工编号
	CC_SYNTHESIZE(uint64_t, ygbh, ygbh);
	// 员工姓名
	CC_SYNTHESIZE(string, pimPersonName, pimPersonName);
	// 原组织
	CC_SYNTHESIZE(string, zz, zz);
	// 原部门
	CC_SYNTHESIZE(string, bm, bm);
	// 原职务
	CC_SYNTHESIZE(string, yzw, yzw);
	// 原岗位
	CC_SYNTHESIZE(string, ygw, ygw);
	// 新组织
	CC_SYNTHESIZE(string, ormOrgId, ormOrgId);
	// 新部门
	CC_SYNTHESIZE(string, ormOrgSectorId, ormOrgSectorId);
	// 新职务
	CC_SYNTHESIZE(string, ormDutyId, ormDutyId);
	// 新岗位
	CC_SYNTHESIZE(string, ormPostId, ormPostId);
	// 借调状态（异动借调明细标识）
	CC_SYNTHESIZE(string, pcmydjdmxId, pcmydjdmxid);
	//借调开始时间
	CC_SYNTHESIZE(string, jdksrq, jdksrq);
	//借调结束时间
	CC_SYNTHESIZE(string, jdjsrq, jdjsrq);

public:
	SecondedPersonnelDO() {
		ygbh = "0";
		pimPersonName = "";
		zz = "";
		bm = "";
		yzw = "";
		ygw = "";
		ormOrgId = "";
		ormOrgSectorId = "";
		ormDutyId = "";
		ormPostId = "";
		pcmydjdmxId = "";
		jdksrq = "";
		jdjsrq = "";
	}
};

#endif // !_SAMPLE_DO_
