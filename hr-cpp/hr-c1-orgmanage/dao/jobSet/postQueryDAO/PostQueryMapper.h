#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _POSTQUERY_MAPPER_
#define _POSTQUERY_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/postSet/PostDetailDO.h"

/**
 * 岗位设置 - 查询指定岗位详情表字段匹配映射
 * 负责人 : rice
 */
class PostQueryMapper : public Mapper<PostDetailDO>
{
public:
	PostDetailDO mapper(ResultSet* resultSet) const override
	{
		PostDetailDO data;
		data.setOrmPostId(resultSet->getString(1));
		data.setOrmPostName(resultSet->getString(2));
		data.setCreateMan(resultSet->getString(3));
		data.setUpdateDate(resultSet->getString(4));
		data.setUpdateMan(resultSet->getString(5));
		data.setCreateDate(resultSet->getString(6));
		data.setXh(resultSet->getUInt(7));
		data.setOrmOrgId(resultSet->getString(8));
		data.setGwType(resultSet->getString(11));
		data.setGwfl(resultSet->getString(12));
		data.setIsConfidential(resultSet->getString(13));
		data.setIsTemp(resultSet->getString(14));
		data.setNx(resultSet->getUInt(15));
		data.setBxjlnx(resultSet->getUInt(16));
		data.setIsKeyPostion(resultSet->getString(17));
		data.setPostNature(resultSet->getString(18));
		data.setStartStopSign(resultSet->getString(18));
		data.setOrmOrgName(resultSet->getString(19));
		return data;
	}
};

#endif // !_POSTQUERY_MAPPER_