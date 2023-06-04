#pragma once
#ifndef _T_ORMSIGNORGDO_H_
#define _T_ORMSIGNORGDO_H_

#include "../DoInclude.h"

/* 法人主体维护数据库表t_ormsignorg实体--（组织管理-数据设置-法人主体维护）--TripleGold */

class OrmsignorgDO
{
	// 法人主体标识
	CC_SYNTHESIZE(string, id, Id);
	// 法人主体名称
	CC_SYNTHESIZE(string, name, Name);
	// 组织编号
	CC_SYNTHESIZE(string, orgcode, Code);
	// 更新人
	CC_SYNTHESIZE(string, updateman, Updateman);
	// 建立人
	CC_SYNTHESIZE(string, createman, Createman);
	// 建立时间
	CC_SYNTHESIZE(string, createdate, CreateDate);
	// 更新时间
	CC_SYNTHESIZE(string, updatedate, Updatedate);
	// 简称
	CC_SYNTHESIZE(string, shortForm, Zzjc);
public:
	OrmsignorgDO() {
		id = "";
		name = "";
		orgcode = "";
	}
	OrmsignorgDO(std::vector<std::string> vec)
	{
		int i = 0;
		setName(vec[i++]);
		setCode(vec[i++]);
	}
	/*OrmsignorgDO(string id, string updateman, string createman, string createdate,
		string name, string updatedate, string orgcode, string shortForm) {
		this->id = id;
		this->updateman = updateman;
		this->createman = createman;
		this->createdate = createdate;
		this->name = name;
		this->updatedate = updatedate;
		this->orgcode = orgcode;
		this->shortForm = shortForm;
	}*/
};
#endif // !_T_ORMSIGNORGDO_H_