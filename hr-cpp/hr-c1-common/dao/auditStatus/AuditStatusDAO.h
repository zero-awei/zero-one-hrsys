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
#ifndef _AUDITSTATUSDAO_H_
#define _AUDITSTATUSDAO_H_

#include "BaseDAO.h"
#include "domain/do/auditStatus/AuditStatusDO.h"
/**
 * 审核状态下拉列表DAO实现
 * 负责人：咫尺之书
 */
class AuditStatusDAO : public BaseDAO
{
private:
	// 审核状态对应哈希表
	unordered_map<string, string> auditStatus = {
		{"10", u8"待审核"},
		{"20", u8"审核中"},
		{"30", u8"审核通过"},
		{"40", u8"审核未通过"}
	};
public:
	// 查询数据
	list<AuditStatusDO> listAll();
	// 返回下拉列表
	unordered_map<string, string> getMapList();
};

#endif // !_AUDITSTATUSDAO_H_