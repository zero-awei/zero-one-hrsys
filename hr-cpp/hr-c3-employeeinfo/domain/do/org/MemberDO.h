#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
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
#ifndef _MEMBER_DO_
#define _MEMBER_DO_
#include "../DoInclude.h"

class MemberDO
{
    // 员工编号
	CC_SYNTHESIZE(string, ygbh, YGBH);
    // 员工姓名
	CC_SYNTHESIZE(string, pimpersonname, PimPersonID);
    // 组织
	CC_SYNTHESIZE(string, ormorgname, OrmOrgName);
    // 部门
	CC_SYNTHESIZE(string, ormorgsectorname, OrmOrgSectorName);
    // 职务
	CC_SYNTHESIZE(string, zw, ZW);
	// 岗位
	CC_SYNTHESIZE(string, gw, GW);
	// 证件号码
	CC_SYNTHESIZE(string, zjhm, ZJHM);
	// 出生日期
	CC_SYNTHESIZE(string, csrq, CSRQ);
	// 年纪
	CC_SYNTHESIZE(string, nj, NJ);
	// 联系电话
	CC_SYNTHESIZE(string, lxdh, LXDH);
public:
	MemberDO() {
        ygbh = "";
        pimpersonname = "";
        ormorgname = "";
        ormorgsectorname = "";
        zw = "";
        gw = "";
        zjhm = "";
        csrq = "";
        nj = "";
        lxdh = "";
    }

};

#endif // !_MEMBER_DO_