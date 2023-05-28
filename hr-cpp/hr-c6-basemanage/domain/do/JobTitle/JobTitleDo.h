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
	// 职称编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 职称名称
	CC_SYNTHESIZE(string, name, Name);
	// 证书编号
	CC_SYNTHESIZE(uint64_t, certid, CertId);
	// 职称等级
	CC_SYNTHESIZE(string, grades, Grades);
	// 职称类型
	CC_SYNTHESIZE(string, jobtype, JobType);
	// 专业类别
	CC_SYNTHESIZE(string, category, Category);
	// 获取时间
	CC_SYNTHESIZE(string, getdate, GetDate);
public:
	// 给参数以默认值
	JobTitleDo() {
		id = 0;
		name = "";
		certid = 0;
		grades = "";
		jobtype = "";
		category = "";
		getdate = "";
	}
};
#endif