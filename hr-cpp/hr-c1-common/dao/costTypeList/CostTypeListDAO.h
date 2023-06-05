#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/05/26 22:37:53

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
#ifndef _COSTTYPELISTDAO_H_
#define _COSTTYPELISTDAO_H_

#include "BaseDAO.h"
#include "domain/do/costTypeList/CostType.h"
/**
 * 费用类别下拉列表DAO实现
 * 负责人：咫尺之书
 */
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