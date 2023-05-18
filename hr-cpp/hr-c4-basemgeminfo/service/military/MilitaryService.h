#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 20:21:30

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
#ifndef _MILITARYSERVICE_H_
#define _MILITARYSERVICE_H_
#include "domain/vo/military/MilitaryVO.h"
#include "domain/query/military/MilitaryQuery.h"
#include "domain/dto/military/MilitaryDTO.h"

class MilitaryService
{
public:
	//查询详情
	MilitaryDTO::Wrapper listDetail(const MilitaryDetailQuery::Wrapper& query);
	// 修改数据
	bool updateData(const MilitaryDTO::Wrapper& dto);
	//导出
	string download(const MilitaryDownloadQuery::Wrapper& query);
};

#endif // !_MILITARYSERVICE_H_

