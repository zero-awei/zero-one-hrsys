#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 11:45:12

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
#ifndef _DISMISSREASONMAPPER_H_
#define _DISMISSREASONMAPPER_H_
#include "Mapper.h"
#include "domain/do/dismissReason/DismissReasonDO.h"
/**
 * 解聘原因字段匹配映射
 * 负责人：远翔
 */
class DismissReasonMapper : public Mapper<DismissReasonDO>
{
public:
	DismissReasonDO mapper(ResultSet* resultSet) const override
	{
		DismissReasonDO data;
		data.setDismissreason(resultSet->getString(1));
		data.setCode(resultSet->getInt(2));
		return data;
	}
};

#endif // !_DISMISSREASONMAPPER_H_