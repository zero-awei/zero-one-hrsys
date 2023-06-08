#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 10:50:58
 
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
#ifndef _RESULT_MAPPER_
#define _RESULT_MAPPER_
#include "jdbc/cppconn/resultset.h"
using namespace sql;

/**
 * 查询结果集匹配接口定义
 */
template <class T>
class Mapper
{
public:
	virtual T mapper(ResultSet* resultSet) const = 0;
};

#endif // !_RESULT_MAPPER_