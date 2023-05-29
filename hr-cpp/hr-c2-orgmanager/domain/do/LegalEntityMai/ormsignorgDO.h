#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/18 22:06:12

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

	//// 法人主体标识
	//CC_SYNTHESIZE(string, id, ORMSIGNORGID);
	//// 更新人
	//CC_SYNTHESIZE(string, updateman, UPDATEMAN);
	//// 建立人
	//CC_SYNTHESIZE(string, createman, CREATEMAN);
	//// 建立时间
	//CC_SYNTHESIZE(string, createdate, CREATEDATE);
	//// 法人主体名称
	//CC_SYNTHESIZE(string, name, ORMSIGNORGNAME);
	//// 更新时间
	//CC_SYNTHESIZE(string, updatedate, UPDATEDATE);
	//// 组织编号
	//CC_SYNTHESIZE(string, orgcode, ORGCODE);
	//// 简称
	//CC_SYNTHESIZE(string, shortForm, ZZJC);
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