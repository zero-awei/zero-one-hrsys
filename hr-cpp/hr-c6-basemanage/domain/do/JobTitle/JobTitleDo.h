#pragma once

/**
* 数据库实体类
*/
#include "stdafx.h"
#include "../Doinclude.h"

#ifndef _JOBTITLE_DO_
#define _JOBTITLE_DO_

class JobTitleDo {
private:
	// 员工编号
	CC_SYNTHESIZE(uint64_t, employeeid, EmployeeId);
	// 员工姓名
	CC_SYNTHESIZE(string, employeename, EmployeeName);
	// 组织名称
	CC_SYNTHESIZE(string, orgname, OrgName);
	// 组织ID
	CC_SYNTHESIZE(string, orgid, OrgId);
	// 职称编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 职称名称
	CC_SYNTHESIZE(string, name, Name);
	// 证书编号
	CC_SYNTHESIZE(string, certid, CertId);
	// 职称等级
	CC_SYNTHESIZE(string, grades, Grades);
	// 职称类型
	CC_SYNTHESIZE(string, jobtype, JobType);
	// 专业类别
	CC_SYNTHESIZE(string, category, Category);
	// 专业名称
	CC_SYNTHESIZE(string, pro_name, Pro_Name);
	// 获取时间
	CC_SYNTHESIZE(string, getdate, GetDate);
	// 签发机构
	CC_SYNTHESIZE(string, issuing_authority, Issuing_Authority);
	// 评审单位
	CC_SYNTHESIZE(string, judging_unit, Judging_Unit);
	// 是否最高职称
	CC_SYNTHESIZE(bool, b_highest_professional_title, B_Highest_Professional_Title);
public:
	// 给参数以默认值
	JobTitleDo() {
		id = 0;
		name = "";
		certid = "";
		grades = "";
		jobtype = "";
		category = "";
		getdate = "";
	}
};
#endif