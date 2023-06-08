#pragma once

#include "../Doinclude.h"
class ExpenseLedgeDO
{
	//费用ID
	CC_SYNTHESIZE(string, id, ID);
	//费用类别
	CC_SYNTHESIZE(string, name, Name);
	//费用金额
	CC_SYNTHESIZE(uint64_t, money, Money);
	//发放人数
	CC_SYNTHESIZE(uint64_t, people_num, People_num);
	//发放时间
	CC_SYNTHESIZE(string, time, Time);
	//费用标准
	CC_SYNTHESIZE(uint64_t, stardandmoney, Stardandmoney);

public:
	ExpenseLedgeDO() {
		id = "";
		name = "";
		money = 0;
		people_num = 0;
		time = "2022-01-01";
		stardandmoney = 0;
	}
};