#pragma once

/**
* 数据库实体类
*/
#include "stdafx.h"
#include "../DoInclude.h"

#ifndef _JOBTITLE_DO_
#define _JOBTITLE_DO_

class JobTitleDO {
private:
	// 职称信息编号
	CC_SYNTHESIZE(string, id, Id);
	// 员工编号
	CC_SYNTHESIZE(string, employee_id, Employee_Id);
	// 员工姓名
	CC_SYNTHESIZE(string, employee_name, Employee_Name);
	// 员工状态
	CC_SYNTHESIZE(string, employee_state, Employee_State);
	// 组织名称
	CC_SYNTHESIZE(string, org_name, Org_Name);
	// 职称名称
	CC_SYNTHESIZE(string, jobtitle_name, Jobtitle_Name);
	// 获取日期
	CC_SYNTHESIZE(string, get_time, Get_Time);
	// 证书编号
	CC_SYNTHESIZE(string, certificate_id, Certificate_Id);
	// 专业类别
	CC_SYNTHESIZE(string, professional_cate, Professional_Cate);

	// 专业名称
	CC_SYNTHESIZE(string, professional_name, Professional_Name);

	// 职称等级
	CC_SYNTHESIZE(string, jobtitle_grades, Jobtitle_Grades);
	// 职称获取月数
	CC_SYNTHESIZE(string, employment_month, Employment_Month);
	// 职称聘用时间
	CC_SYNTHESIZE(string, title_employment_time, Title_Employment_Time);
	// 签发机构
	CC_SYNTHESIZE(string, issuing_authority, Issuing_Authority);
	// 评审单位
	CC_SYNTHESIZE(string, judging_unit, Judging_Unit);
	// 是否使最高职称
	CC_SYNTHESIZE(string, b_highest_professional_title, B_Highest_Professional_Title);

public:
	// 给参数以默认值
	JobTitleDO() {
		employee_id = "";
		employee_name = "";
		org_name = "";
		jobtitle_name = "";
		get_time = "";
		certificate_id = "";
		professional_cate = "";
		//employment_month = "";
		professional_name = "";
		jobtitle_grades = "";
		issuing_authority = "";
		judging_unit = "";
		b_highest_professional_title = "";
	}
};

class JobTitleAddDO {
private:
	// 职称信息编号
	CC_SYNTHESIZE(string, id, Id);
	// 员工编号
	CC_SYNTHESIZE(string, employee_id, Employee_Id);
	// 员工姓名
	CC_SYNTHESIZE(string, employee_name, Employee_Name);
	// 人员信息id
	CC_SYNTHESIZE(string, pimperson_id, Pimperson_Id);
	// 员工状态
	CC_SYNTHESIZE(string, employee_state, Employee_State);
	// 组织名称
	CC_SYNTHESIZE(string, org_name, Org_Name);
	// 职称名称
	CC_SYNTHESIZE(string, jobtitle_name, Jobtitle_Name);
	// 获取日期
	CC_SYNTHESIZE(string, get_time, Get_Time);
	// 证书编号
	CC_SYNTHESIZE(string, certificate_id, Certificate_Id);
	// 专业类别
	CC_SYNTHESIZE(string, professional_cate, Professional_Cate);
	// 专业名称
	CC_SYNTHESIZE(string, professional_name, Professional_Name);
	// 职称等级
	CC_SYNTHESIZE(string, jobtitle_grades, Jobtitle_Grades);
	// 职称聘用时间
	CC_SYNTHESIZE(string, title_employment_time, Title_Employment_Time);
	// 签发机构
	CC_SYNTHESIZE(string, issuing_authority, Issuing_Authority);
	// 评审单位
	CC_SYNTHESIZE(string, judging_unit, Judging_Unit);
	// 是否使最高职称
	CC_SYNTHESIZE(string, b_highest_professional_title, B_Highest_Professional_Title);
	// 附件
	CC_SYNTHESIZE(string, attachment, Attachment);

public:
	// 给参数以默认值
	JobTitleAddDO() {
		employee_id = "";
		employee_name = "";
		pimperson_id = "";
		org_name = "";
		jobtitle_name = "";
		get_time = "";
		certificate_id = "";
		professional_cate = "";
		professional_name = "";
		jobtitle_grades = "";
		issuing_authority = "";
		judging_unit = "";
		b_highest_professional_title = "";
		attachment = "";
	}
};


#endif