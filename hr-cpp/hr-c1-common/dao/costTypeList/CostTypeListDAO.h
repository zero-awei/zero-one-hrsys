#pragma once
#ifndef _COSTTYPELISTDAO_H_
#define _COSTTYPELISTDAO_H_

#include "BaseDAO.h"
#include "domain/do/costTypeList/CostType.h"

class CostTypeListDAO : public BaseDAO
{
private:
	// 职称等级对应哈希表
	unordered_map<string, string> costType = {
		{"10", u8"老干部活动费"},
		{"20", u8"津补贴"},
		{"30", u8"企业效益奖金"},
		{"40", u8"体检费"},
		{"50", u8"医疗费"},
		{"60", u8"其他费用（备注明细）"}
	};
public:
	// 查询数据
	list<CostTypeDO> listAll();
	// 返回下拉列表
	unordered_map<string, string> getMapList();
};

#endif // !_COSTTYPELISTDAO_H_