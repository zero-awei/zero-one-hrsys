#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/30 22:50:50

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
#ifndef _QUERYLEGALENTITYSETDO_H_
#define _QUERYLEGALENTITYSETDO_H_

#include "../DoInclude.h"

/* 法人主体设置数据库表t_contractsignorg, t_srforg, t_ormsignorg实体--（组织管理-数据设置-法人主体设置）--TripleGold */

class QueryLegalEntitySetDO
{
	// 签约主体单位标识
	CC_SYNTHESIZE(string, id, Id);
	// 管理单位名称
	CC_SYNTHESIZE(string, orgName, OrgName);
	// 默认签约主体
	CC_SYNTHESIZE(string, defa, Defa);
	// 更新人
	CC_SYNTHESIZE(string, updateman, Updateman);
	// 建立人
	CC_SYNTHESIZE(string, createman, Createman);
	// 建立时间
	CC_SYNTHESIZE(string, createdate, CreateDate);
	// 更新时间
	CC_SYNTHESIZE(string, updatedate, Updatedate);
	// 法人主体标识t_srforg
	CC_SYNTHESIZE(string, lemIdSrf, LEMIdSrf);
	// 法人主体标识t_ormsignorg
	CC_SYNTHESIZE(string, lemId, LEMId);
	// 法人主体名称
	CC_SYNTHESIZE(string, lemName, LEMName);
public:
	QueryLegalEntitySetDO() {
		id = "";
		orgName = "";
		lemName = "";
		defa = "";
	};
	QueryLegalEntitySetDO(std::vector<std::string> vec) {
		int i = 0;
		setOrgName(vec[i++]);
		setLEMName(vec[i++]);
		setDefa(vec[i++]);
	}
};

#endif // !_QUERYLEGALENTITYSETDO_H_