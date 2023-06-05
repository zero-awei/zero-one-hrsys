#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/05/26 15:17:12

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
#ifndef _PROJTAGLISTMAPPER_H_
#define _PROJTAGLISTMAPPER_H_

#include "Mapper.h"
#include "domain/do/projTag/ProjTagDO.h"

/**
 * 项目标签列表字段匹配映射
 * 负责人：咫尺之书
 */
class ProjTagListMapper : public Mapper<ProjTagDO>
{
public:
	ProjTagDO mapper(ResultSet* resultSet) const override
	{
		ProjTagDO data;

		data.setId(resultSet->getString(1));
		data.setCreator(resultSet->getString(2));
		data.setTagName(resultSet->getString(3));
		data.setUpdater(resultSet->getString(4));
		data.setCreateTime(resultSet->getString(5));
		data.setUpdateTime(resultSet->getString(6));
		data.setOrgId(resultSet->getString(7));

		return data;
	}
};

#endif // !_PROJTAGLISTMAPPER_H_