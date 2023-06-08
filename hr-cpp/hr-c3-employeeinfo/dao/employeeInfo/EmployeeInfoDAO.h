#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/25 8:16:26

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
#ifndef _EMPLOYEEINFODAO_H_
#define _EMPLOYEEINFODAO_H_
#include "BaseDAO.h"
#include "../../domain/do/employeeInfo/EmployeeInfoDO.h"
#include "../../domain/dto/employeeInfo/EmployeeInfoAddDTO.h"
#include "../../domain/dto/employeeInfo/EmployeeInfoDTO.h"
#include "../../domain/query/employeeInfo/EmployeeInfoQuery.h"

/* *
* 员工信息DAO
* 执行人：Detachment
*/
class EmployeeInfoDAO : public BaseDAO
{
public:
	/* *
	* 修改指定员工员工信息
	* 执行人：Detachment
	*/
	int updateEmployee(const EmployeeInfoDTO::Wrapper& edo,string pl);
	/* *
	* 新增员工信息
	* 执行人：Detachment
	*/
	int insertEmployee(const EmployeeInfoAddDTO::Wrapper& eadto, string pimid,string dt,string pl);
	/* *
	* 查询指定员工员工信息
	* 执行人：Detachment
	*/
	list<EmployeeInfoDO> selectEmployee(const EmployeeInfoQuery::Wrapper& query);
};

#endif // !_EMPLOYEEINFODAO_H_