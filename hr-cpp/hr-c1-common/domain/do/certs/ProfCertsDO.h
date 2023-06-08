#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/21 16:52:22

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
#ifndef _PROFCERTS_DO_
#define _PROFCERTS_DO_
#include "../DoInclude.h"

/**
 * 执(职)业资格证书下拉列表查询DO
 * 负责人：米饭
 */
class ProfCertsDO
{
	// 执业资格专业编码
	CC_SYNTHESIZE(string, pimQualMajorId, PimQualMajorId);
	// 执业资格
	CC_SYNTHESIZE(string, pimQualMajorName, PimQualMajorName);
	// 建立人
	CC_SYNTHESIZE(string, createMan, CreateMan);
	// 建立时间
	CC_SYNTHESIZE(string, createDate, CreateDate);
	// ENABLE
	CC_SYNTHESIZE(uint64_t, enable, Enable);
	// 更新人
	CC_SYNTHESIZE(string, upDateMan, UpDateMan);
	// 更新时间
	CC_SYNTHESIZE(string, upDateDate, UpDateDate);
	// 执业资格类别标识
	CC_SYNTHESIZE(string, pimQualTypeId, PimQualTypeId);
	// 组织标识
	CC_SYNTHESIZE(string, ormOrgId, OrmOrgId);
	// 执业资格类别
	CC_SYNTHESIZE(string, professionalType, ProfessionalType);
	// 专业技术职务
	CC_SYNTHESIZE(string, zyjszw, Zyjszw);
	// 级别
	CC_SYNTHESIZE(string, quaLevel, QuaLevel);
	// 专业
	CC_SYNTHESIZE(string, quaMajor, QuaMajor);
	// 岗位类型
	CC_SYNTHESIZE(string, gwlx, Gwlx);
	// 岗位类型
	CC_SYNTHESIZE(string, gwType, GwType);
	// 岗位类型
	CC_SYNTHESIZE(string, gwzs, Gwzs);
	// 岗位（技能）证书
	CC_SYNTHESIZE(string, pimQualTypeName, PimQualTypeName);

public:
	ProfCertsDO() {
		pimQualMajorId = "";
		pimQualMajorName = "";
		createMan = "";
		createDate = "";
		enable = 0;
		upDateMan = "";
		upDateDate = "";
		pimQualTypeId = "";
		ormOrgId = "";
		professionalType = "";
		zyjszw = "";
		quaLevel = "";
		quaMajor = "";
		gwlx = "";
		gwType = "";
		gwzs = "";
		pimQualTypeName = "";
	}
};

#endif // !_PROFCERTS_DO_
