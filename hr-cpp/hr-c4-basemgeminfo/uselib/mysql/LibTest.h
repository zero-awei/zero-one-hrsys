#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:19:28
 
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
#ifndef _LIB_TEST_
#define _LIB_TEST_
#include <string>
#include "Mapper.h"
#include "BaseDAO.h"

/**
 * 测试数据库查询的实体类
 */
class LibTest
{
public:
	int id = 0;
	std::string first = "";
	std::string last = "";
	int age = 1;
};

/**
 * 测试结果集匹配Mapper实现
 */
class LibTestMapper : public Mapper<LibTest>
{
public:
	LibTest mapper(ResultSet* resultSet) const override
	{
		LibTest p;
		p.id = resultSet->getInt(1);
		p.first = resultSet->getString(2);
		p.last = resultSet->getString(3);
		p.age = resultSet->getInt(4);
		return p;
	}
};

/**
 * 测试DAO1
 */
class LibTestDAO1 :public BaseDAO {
public:
	int update(LibTest uObj) {
		string sql = "UPDATE `lib_test` SET `first`=? WHERE `id`=?";
		return sqlSession->executeUpdate(sql, "s%i", uObj.first, uObj.id);
	}
};

/**
 * 测试DAO2
 */
class LibTestDAO2 :public BaseDAO {
public:
	int deleteById(int id) {
		string sql = "DELETE FROM `lib_test` WHERE `id`=?";
		return sqlSession->executeUpdate(sql, "i", id);
	}
};

#endif // _LIB_TEST_
