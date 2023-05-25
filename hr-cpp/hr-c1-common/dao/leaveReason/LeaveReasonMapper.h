#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 15:54:19

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
#ifndef _LEAVEREASONMAPPER_H_
#define _LEAVEREASONMAPPER_H_
#include "Mapper.h"
#include "domain/do/leaveReson/LeaveReasonDO.h"
/**
 * 离职原因字段匹配映射
 * 负责人：远翔
 */
class LeaveReasonMapper : public Mapper<LeaveReasonDO>
{
public:
	LeaveReasonDO mapper(ResultSet* resultSet) const override
	{
		LeaveReasonDO data;
		data.setLeavereason(resultSet->getString(1));
		data.setCode(resultSet->getInt(2));
		return data;
	}
};

#endif // !_LEAVEREASONMAPPER_H_