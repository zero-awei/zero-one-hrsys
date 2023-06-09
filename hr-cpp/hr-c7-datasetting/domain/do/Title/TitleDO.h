#pragma once
#ifndef _TITLEDO_H_
#define _TITLEDO_H_

#include "../DoInclude.h"
/**
 * 职称目录信息实体
 */
class TitleDO
{
	//排序号
	CC_SYNTHESIZE(uint32_t, id, Id);
	//职称代码
	CC_SYNTHESIZE(string, num, Num);
	//职称目录名称
	CC_SYNTHESIZE(string, name, Name);
	//职称目录类型
	CC_SYNTHESIZE(string, dtype, Dtype);
	//职称类型
	CC_SYNTHESIZE(string, Ttype, TTtype);

public:
	TitleDO() {
		id = 0;
		num = "";
		name = "";
		dtype = "";
		Ttype = "";
	}
	TitleDO(uint32_t Id, string Num, string Name, string Dtype, string TTtype)
	{
		this->id = Id;
		this->num = Num;
		this->name = Name;
		this->dtype = Dtype;
		this->Ttype = TTtype;
		// 你可以根据需要添加其他变量
	}
};

#endif
