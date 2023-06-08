#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/25 21:06:11

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
#ifndef _LABORDISPATCHSERVICE_H_
#define _LABORDISPATCHSERVICE_H_
#include "domain/dto/LaborDispatch/LaborDispatchDTO.h"
#include "domain/query/LaborDispatch/LaborDispatchQuery.h"

class LaborDispatchService
{
public:
	//分页查询所有数据
	LaborDispatchPageDTO::Wrapper listAll_ld(const LaborDispatchQuery::Wrapper& query);
	//保存数据
	uint64_t saveData_ld(const LaborDispatchModifyDTO::Wrapper& dto);
	//通过ID删除数据
	bool removeData_ld(string id);
	//导出数据
	string LaborDispatchExport_ld(const LaborDispatchQuery::Wrapper& query, const LaborDispatchExportDTO::Wrapper& dto);
};
#endif // !_LABORDISPATCHSERVICE_H_