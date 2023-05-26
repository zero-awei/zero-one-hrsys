#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/25 20:30:40

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
#ifndef _EMPLOYEE_INFORMATION_DAO_
#define _EMPLOYEE_INFORMATION_DAO_
#include "BaseDAO.h"
#include "domain/do/EmployeeInformationPage/EmployeeInformationPageDO.h"
#include "domain/query/EmployeeInformationPageQuery/EmployeeInformationPageQuery.h"

class EmployeeInformationDAO:public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const EmployeeInformationPageQuery::Wrapper& query);
	// 分页查询数据
	list<EmployeeInformationPageDO> selectWithPage(const EmployeeInformationPageQuery::Wrapper& query);
	// 通过姓名查询数据
	list<EmployeeInformationPageDO> selectByName(const string& name);

	// 插入数据
	uint64_t insert(const EmployeeInformationPageDO& iObj);
	// 修改数据
	int update(const EmployeeInformationPageDO& uObj);
	// 通过ID删除数 据
	int deleteById(uint64_t id);

};

#endif // !_EMPLOYEE_INFORMATION_DAO_
