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
#include "CharsetConvertHepler.h"

/**
 * 离职员工数据库实体类
 */
class FormerEmployeesDO
{
	// 员工基本信息表ID,同员工ID
	CC_SYNTHESIZE(string, ygbh, ygbh);
	// 姓名
	CC_SYNTHESIZE(string, pimPersonName, pimPersonName);
	// 性别
	CC_SYNTHESIZE(string, sex, sex);
	// 手机号码
	CC_SYNTHESIZE(string, lxdh, lxdh);
	// 出生日期
	CC_SYNTHESIZE(string, csrq, csrq);
	// 组织
	CC_SYNTHESIZE(string, organizationName, organizationName);
	// 部门
	CC_SYNTHESIZE(string, bm, bm);
	// 职级
	CC_SYNTHESIZE(string, rank, rank);
	// 通讯地址
	CC_SYNTHESIZE(string, postalAddress, postalAddress);
	// 家庭联系人
	CC_SYNTHESIZE(string, jtlxr, jtlxr);
	// 家庭联系人电话
	CC_SYNTHESIZE(string, jtlxrdh, jtlxrdh);

	// 以下为非前端显示字段
	// t_pcmydlzmx主键：异动离职明细标识
	CC_SYNTHESIZE(string, pcmydlzmxId, pcmydlzmxId);
	// FOREIGN KEY t_pimperson 人员信息标识
	CC_SYNTHESIZE(string, lzmtrId, lzmtrId);

public:
	FormerEmployeesDO() {};
	std::vector<std::string> FormerEmployeestoVector()
	{
		std::vector<std::string> vec { this->getygbh(),\
			this->getpimPersonName(), this->getsex(), this->getlxdh(),\
			this->getcsrq(), this->getorganizationName(), this->getbm(),\
			this->getrank(), this->getpostalAddress(), this->getjtlxr(), this->getjtlxrdh() };
		
		return vec;
	}
};

#endif // !_FPRMERRMPLOYEES_DO_
