#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/25 15:25:41

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
#ifndef _EMPLOYEE_INFORMATION_SERVICER_
#define _EMPLOYEE_INFORMATION_SERVICER_

#include "domain/dto/EmployeeInformationPageQuery/EmployeeInformationPageQueryDTO.h"
#include "domain/query/EmployeeInformationPageQuery/EmployeeInformationPageQuery.h"
#include "domain/vo/EmployeeInformation/EmployeeInformationVO.h"
#include "domain/do/EmployeeInformationPage/EmployeeInformationPageDO.h"
#include "domain/dto/importInfo/ImportInfoDTO.h"
#include "domain/vo/importInfo/importInfoVO.h"
#include "domain/query/postSet/PostDetailQuery.h"


class EmployeeInformationServicer
{
public:
	// 分页查询所有数据
	EmployeeInformationPageDTO::Wrapper listAll(const EmployeeInformationPageQuery::Wrapper& query);
	//新增员工信息
	uint64_t saveData(const EmployeeInformationDTO::Wrapper& dto, const PayloadDTO& payload);
	//导入员工信息(批量新增)
	importInfoVO::Wrapper addMultiEmployee(const ImportInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	//导出员工信息(导出本页在前端完成)
	std::string exportEmpInfomation(const PostDetailQuery::Wrapper& query);
};

#endif // !_EMPLOYEE_INFORMATION_SERVICER_
