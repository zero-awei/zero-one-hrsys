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
	//员工编号
	CC_SYNTHESIZE(string, YGBH, YGBH);
	//员工姓名
	CC_SYNTHESIZE(string, PIMPERSONNAME, PIMPERSONNAME);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(string, NJ, NJ);
	// 组织
	CC_SYNTHESIZE(string, ORGANIZATION_NAME, ORGANIZATION_NAME);
	// 部门
	CC_SYNTHESIZE(string, BM, BM);
	// 职务
	CC_SYNTHESIZE(string, RANK, RANK);
	// 岗位
	CC_SYNTHESIZE(string, GW, GW);
	//手机号码
	CC_SYNTHESIZE(string, LXDH, LXDH);
	// 家庭联系人
	CC_SYNTHESIZE(string, JTLXR, JTLXR);
	// 家庭联系人电话
	CC_SYNTHESIZE(string, JTLXRDH, JTLXRDH);
	
public:
	CommonRosterOfPerDO() {

	}
};

#endif // !_COMMONROSTEROFPER_DO_
