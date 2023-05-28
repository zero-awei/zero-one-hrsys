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
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "domain/do/RosterOfPer/RraineeDO.h"

/**
 * 示例表字段匹配映射
 */
class RraineeMapper : public Mapper<RraineeDO>
{
public:
	RraineeDO mapper(ResultSet* resultSet) const override
	{
		RraineeDO data;
		data.setYgbh(resultSet->getString(1));
		data.setPcmjxszzkhjgjlname(resultSet->getString(2));
		data.setZz(resultSet->getString(3));
		data.setBm(resultSet->getString(4));
		data.setZw(resultSet->getString(5));
		data.setGw(resultSet->getString(6));
		data.setDuration(resultSet->getString(7));
		data.setKsrq(resultSet->getString(8));
		data.setJsrq(resultSet->getString(9));
		return data;
	}
};

/*
RraineeMapper类的作用是将ResultSet对象中的数据映射到RraineeDO对象中。ResultSet通常用于表示从数据库中检索到的结果集。
mapper方法接受一个ResultSet*参数，即指向ResultSet对象的指针，并返回一个RraineeDO对象。
在mapper方法中，首先创建一个RraineeDO对象data。然后通过调用resultSet对象的各种方法，如getUInt64、getString和getInt，
获取结果集中的具体数据，并使用data对象的相应setter方法，如setId、setName、setSex和setAge，将数据设置到RraineeDO对象中。
最后，将填充好的RraineeDO对象返回。
这段代码展示了一种常见的数据映射模式，用于将数据库查询结果映射到自定义的数据对象中。
*/
#endif // !_SAMPLE_MAPPER_