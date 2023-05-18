#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/18 8:56:54

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
#ifndef _WORKHISTORYSERVICE_H_
#define _WORKHISTORYSERVICE_H_

#include "domain/dto/work-history/WorkHistoryFindDTO.h"
#include "domain/query/work-history/WorkHistoryPageQuery.h"

class WorkHistoryService
{
public:
	// 分页查询所有数据
	WorkHistoryFindPageDTO::Wrapper listAll(const WorkHistoryPageQuery::Wrapper& query);
};

#endif // !_WORKHISTORYSERVICE_H_