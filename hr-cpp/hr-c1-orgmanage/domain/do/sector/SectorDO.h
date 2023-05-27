#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/22 20:38:39

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
#ifndef _SECTORDO_H_
#define _SECTORDO_H_
#include "../DoInclude.h"
/**
 * 编制查询DO
 * 负责人：远翔
 */
class SectorDO
{
	// 项目基本情况
	CC_SYNTHESIZE(string, projBasicInfo, ProjBasicInfo);

	// 更新人
	CC_SYNTHESIZE(string, updateMan, UpdateMan);

	// 地区分类
	CC_SYNTHESIZE(string, areaClassify, AreaClassify);

	// 版本
	CC_SYNTHESIZE(double, edition, Edition);

	// 上班时间
	CC_SYNTHESIZE(string, officeTime, OfficeTime);

	// 下班时间
	CC_SYNTHESIZE(string, leaveTime, LeaveTime);

	// 启停标识
	CC_SYNTHESIZE(string, startStopSign, StartStopSign);

	// 建立时间
	CC_SYNTHESIZE(string, createTime, CreateTime);

	// 工程名称及编码
	CC_SYNTHESIZE(string, projNameAndId, ProjNameAndId);

	// 项目标签
	CC_SYNTHESIZE(string, projId, ProjId);

	// 原记录ID
	CC_SYNTHESIZE(string, oldId, OldId);

	// 上班考勤时间
	CC_SYNTHESIZE(string, officeAttendTime, OfficeAttendTime);

	// 部门组织编号
	CC_SYNTHESIZE(string, orgCode, OrgCode);

	// 计划人月
	CC_SYNTHESIZE(double, planManMonth, PlanManMonth);

	// 审批状态
	CC_SYNTHESIZE(string, approvalStatus, ApprovalStatus);

	// 下班考勤时间
	CC_SYNTHESIZE(string, leaveAttendTime, LeaveAttendTime);

	// 更新时间
	CC_SYNTHESIZE(string, updateTime, UpdateTime);

	// 项目类型
	CC_SYNTHESIZE(string, projClassify, ProjClassify);

	// 组织类型
	CC_SYNTHESIZE(string, orgType, OrgType);

	// ERP部门ID
	CC_SYNTHESIZE(string, erpOrgId, ErpOrgId);

	// 打卡方式
	CC_SYNTHESIZE(string, punchingMode, PunchingMode);

	// 项目类型
	CC_SYNTHESIZE(string, projType, ProjType);

	// 部门名称
	CC_SYNTHESIZE(string, orgSectorName, OrgSectorName);

	// 项目规模
	CC_SYNTHESIZE(string, projScale, ProjScale);
	
	// 对项目经理的要求
	CC_SYNTHESIZE(string, demondOfProjectManager, DemondOfProjectManager);
	
	// 对项目总工的要求
	CC_SYNTHESIZE(string, demondOfChiefEngineer, DemondOfChiefEngineer);
	
	// 头衔
	CC_SYNTHESIZE(string, title, Title);
	
	// 参照职务层级
	CC_SYNTHESIZE(string, referJobLevel, ReferJobLevel);
	
	// 所属OU
	CC_SYNTHESIZE(string, belongOU, BelongOU);
	
	// 简称
	CC_SYNTHESIZE(string, shortName, ShortName);
	
	// 工期安排
	CC_SYNTHESIZE(string, projTimePlan, ProjTimePlan);
	
	// 计划成本（万）
	CC_SYNTHESIZE(double, planCost, PlanCost);
	
	// 部门类型
	CC_SYNTHESIZE(string, depType, DepType);
	
	// 项目部类型
	CC_SYNTHESIZE(string, projDepType, ProjDepType);
	
	// 部门标识  非空
	CC_SYNTHESIZE(string, orgSectorId, OrgSectorId);
	
	// 管控机制
	CC_SYNTHESIZE(string, mechanism, Mechanism);
	
	// 版本状态
	CC_SYNTHESIZE(string, editionState, EditionState);
	
	// 建立人
	CC_SYNTHESIZE(string, createMan, CreateMan);
	
	// 实际成本（万）
	CC_SYNTHESIZE(double, realCost, RealCost);
	
	// 实际人月
	CC_SYNTHESIZE(double, realManMonth, RealManMonth);
	
	// 所属区域
	CC_SYNTHESIZE(string, belongRegion, BelongRegion);
	
	// 部门负责人ID
	CC_SYNTHESIZE(string, pimPersonId, PimPersonId);
	
	// 项目ID
	CC_SYNTHESIZE(string, orgProjId, OrgProjId);
	
	// 项目部ID
	CC_SYNTHESIZE(string, proDepId, ProDepId);
	
	// 项目负责人ID
	CC_SYNTHESIZE(string, proLeaderId, ProLeaderId);
	
	// 上级部门
	CC_SYNTHESIZE(string, pOrgSectorId, POrgSectorId);
	
	// 组织机构ID
	CC_SYNTHESIZE(string, orgId, OrgId);
	
	// 条线代码
	CC_SYNTHESIZE(string, bizCode, BizCode);
	
	// 用户数据
	CC_SYNTHESIZE(string, userData, Userdata);
	
	// 级别编码
	CC_SYNTHESIZE(string, levelCode, LevelCode);
	
	// 用户数据2
	CC_SYNTHESIZE(string, userdata2, Userdata2);
	
	// 备注
	CC_SYNTHESIZE(string, memo, Memo);
	
	// 组织机构
	CC_SYNTHESIZE(string, orgName, OrgName);
	
	// 上级部门
	CC_SYNTHESIZE(string, pOrgSectorName, POrgSectorName);
	
	// 汇报部门名称
	CC_SYNTHESIZE(string, repOrgSectorName, RepOrgSectorName);
	
	// 汇报部门ID
	CC_SYNTHESIZE(string, repOrgSectorId, RepOrgSectorId);

	// 考勤员标识
	CC_SYNTHESIZE(string, pimPersonId, PimPersonId);

	// 考勤设置标识
	CC_SYNTHESIZE(string, attendenceSetUpId, AttendenceSetUpId);

public:
	SectorDO() {
		orgSectorId = "";
	}
	SectorDO(string secid) {
		orgSectorId = secid;
	}

};

#endif // !_SECTORDO_H_