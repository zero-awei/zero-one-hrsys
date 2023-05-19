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
#ifndef _FORMER_EMPLOYEES_DO_
#define _FORMER_EMPLOYEES_DO_
#include "../DoInclude.h"

/**
 * 离职员工数据库实体类
 */
class FormerEmployeesDO
{
	// 离职信息ID，主键，供其他表做外键
	CC_SYNTHESIZE(uint64_t, LEAVINGANALYSIS_ID, LEAVINGANALYSIS_ID);
	// 员工基本信息表ID,同员工ID
	CC_SYNTHESIZE(uint64_t, PIMPERSONNAME, PIMPERSONNAME);
	// 姓名
	CC_SYNTHESIZE(string, EMPLOYEENAME, EMPLOYEENAME);
	// 性别
	CC_SYNTHESIZE(string, XB, XB);
	// 手机号码
	CC_SYNTHESIZE(string, LXDH, LXDH);
	// 出生日期
	CC_SYNTHESIZE(int, CSRQ, CSRQ);
	// 组织
	CC_SYNTHESIZE(string, ORGANIZATION_NAME, ORGANIZATION_NAME);
	// 部门
	CC_SYNTHESIZE(string, BM, BM);
	// 职级
	CC_SYNTHESIZE(string, RANK, RANK);
	// 通讯地址
	CC_SYNTHESIZE(string, POSTALADDRESS, POSTALADDRESS);
	// 家庭联系人
	CC_SYNTHESIZE(string, JTLXR, JTLXR);
	// 家庭联系人电话
	CC_SYNTHESIZE(string, JTLXRDH, JTLXRDH);
	
public:
	FormerEmployeesDO() {}
};

#endif // !_FPRMERRMPLOYEES_DO_
