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
#ifndef _COMMONROSTEROFPER_DO_
#define _COMMONROSTEROFPER_DO_
#include "../DoInclude.h"

/**
 * 人员花名册公共DO--(人员花名册)--luoluo
 */
class CommonRosterOfPerDO
{
	// 离职信息ID，主键，供其他表做外键
	CC_SYNTHESIZE(uint64_t, leavingAnalysis_ID, leavingAnalysis_ID);
	// 员工基本信息表ID,同员工ID
	CC_SYNTHESIZE(uint64_t, pimperSonName, pimperSonName);
	//员工姓名
	CC_SYNTHESIZE(string, name, name);
	// 性别
	CC_SYNTHESIZE(string, sex, sex);
	// 年龄
	CC_SYNTHESIZE(string, nj, nj);
	//员工编号、工号
	CC_SYNTHESIZE(string, ygbh, ygbh);
	// 组织
	CC_SYNTHESIZE(string, organizationName, organizationName);
	// 部门
	CC_SYNTHESIZE(string, bm, bm);
	// 职务
	CC_SYNTHESIZE(string, rank, rank);
	// 岗位
	CC_SYNTHESIZE(string, gw, gw);
	//手机号码
	CC_SYNTHESIZE(string, lxdh, lxdh);
	// 家庭联系人
	CC_SYNTHESIZE(string, jtlxr, jtlxr);
	// 家庭联系人电话
	CC_SYNTHESIZE(string, jtlxrdh, jtlxrdh);
	
public:
	CommonRosterOfPerDO() {
		
	}
};

#endif // !_COMMONROSTEROFPER_DO_
