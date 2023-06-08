#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/25 22:44:58

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
#ifndef _ORGLISTDO_H_
#define _ORGLISTDO_H_

#include "../DoInclude.h"

class OrgListDO
{
	// 区域补贴
	CC_SYNTHESIZE(string, regionSubsidy, RegionSubsidy);
	// 公司根组织ID
	CC_SYNTHESIZE(string, flag, Flag);
	// 对应OU
	CC_SYNTHESIZE(string, correspondou, Correspondou);
	// 建立人
	CC_SYNTHESIZE(string, createby, Createby);
	// 更新人
	CC_SYNTHESIZE(string, updater, Updater);
	// 更新时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// 建立时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// ERP组织ID
	CC_SYNTHESIZE(string, erpOrgId, ErpOrgId);
	// 所属区域
	CC_SYNTHESIZE(string, belongRegion, BelongRegion);
	// 组织性质
	CC_SYNTHESIZE(string, legalEntity, LegalEntity);
	// 级别编码
	CC_SYNTHESIZE(string, levelCode, LevelCode);
	// 组织编号
	CC_SYNTHESIZE(string, orgCode, OrgCode);
	// 组织机构标识
	CC_SYNTHESIZE(string, orgId, OrgId);
	// 组织机构名称
	CC_SYNTHESIZE(string, orgName, OrgName);
	// 上级组织机构
	CC_SYNTHESIZE(string, porgId, PorgId);
	// 上级组织机构名称
	CC_SYNTHESIZE(string, porgName, PorgName);
	// 简称
	CC_SYNTHESIZE(string, shortname, Shortname);
	// 所属OU
	CC_SYNTHESIZE(string, belongou, Belongou);
	// 启停标识
	CC_SYNTHESIZE(string, sign, Sign);
	// 组织地址编码
	CC_SYNTHESIZE(string, orgAddrCode, OrgAddrCode);
	// 组织地址1
	CC_SYNTHESIZE(string, orgAddrOne, OrgAddrOne);
	// 组织地址2
	CC_SYNTHESIZE(string, orgAddrTwo, OrgAddrTwo);
	// 组织创建时间
	CC_SYNTHESIZE(string, orgCreateTime, OrgCreateTime);
	// 组织显示时间
	CC_SYNTHESIZE(string, name, Name);
	// 组织类型
	CC_SYNTHESIZE(string, orgType, OrgType);

public:
	OrgListDO()
	{
		regionSubsidy = "";
		flag = "";
		correspondou = "";
		createby = "admin";
		updater = "admin";
		createTime = "2000-01-01 00:00:00";
		updateTime = "2000-01-01 00:00:00";
		erpOrgId = "";
		belongRegion = "";
		legalEntity = "";
		levelCode = "";
		orgCode = "";
		orgId = "";
		orgName = "";
		porgId = "";
		shortname = "";
		belongou = "";
		sign = "";
		orgAddrCode = "";
		orgAddrOne = "";
		orgAddrTwo = "";
		orgCreateTime = "";
		name = "";
		orgType = "";
	}
};

#endif // !_ORGLISTDO_H_