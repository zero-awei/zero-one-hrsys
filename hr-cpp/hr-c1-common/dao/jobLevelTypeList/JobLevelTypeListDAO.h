#pragma once
#ifndef _JOBLEVELTYPELISTDAO_H_
#define _JOBLEVELTYPELISTDAO_H_

#include "BaseDAO.h"
#include "domain/do/jobLevelTypeList/JobLevelTypeDO.h"

class JobLevelTypeListDAO : public BaseDAO
{
private:
	// 职称等级对应哈希表
	unordered_map<string, string> jobLevel = {
		{"30", u8"正高级"},
		{"20", u8"高级"},
		{"10", u8"中级"},
		{"5", u8"初级"}
	};
public:
	// 查询数据
	list<JobLevelTypeDO> listAll();
	// 返回下拉列表
	unordered_map<string, string> getMapList();
};

#endif // !_JOBLEVELTYPELISTDAO_H_