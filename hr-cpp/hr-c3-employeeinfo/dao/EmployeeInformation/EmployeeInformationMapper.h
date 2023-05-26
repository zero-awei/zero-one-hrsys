#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/25 22:21:05

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
#ifndef _EMPLOYEE_INFORMATION_MAPPER_
#define _EMPLOYEE_INFORMATION_MAPPER_

#include "Mapper.h"
#include "domain/do/EmployeeInformationPage/EmployeeInformationPageDO.h"

/**
 * 员工信息表字段匹配映射
 */
class EmployeeInformationMapper :public Mapper<EmployeeInformationPageDO>
{
public:
	EmployeeInformationPageDO mapper(ResultSet* resultSet) const override
	{
		EmployeeInformationPageDO data;
		// 姓名
		data.setName(resultSet->getString(1));
		// 年龄
		data.setAge(resultSet->getInt(2));
		//编号
		data.setId(resultSet->getString(3));
		//组织
		data.setOrganize(resultSet->getString(4));
		//部门
		data.setDepart(resultSet->getString(5));
		//职务
		data.setJob(resultSet->getString(6));
		//岗位
		data.setPost(resultSet->getString(7));
		//证件号
		data.setIdMum(resultSet->getString(8));
		//出生日期
		data.setBirthday(resultSet->getString(9));
		//手机号码
		data.setPhone(resultSet->getString(10));
		//员工状态
		data.setState(resultSet->getString(11));
		return data;
	}
};

#endif // !_EMPLOYEE_INFORMATION_MAPPER_
