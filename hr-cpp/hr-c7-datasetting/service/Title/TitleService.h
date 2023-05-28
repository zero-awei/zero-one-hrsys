#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/27 13:25:22

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
#ifndef _TITLE_SERVICE_
#define _TITLE_SERVICE_
#include <list>
#include "domain/dto/Title/TitleDTO.h"
#include "domain/query/Title/TitleQuery.h"
#include "domain/vo/Title/TitleVO.h"

class TitleService
{
public:
	// 分页查询职称数据
	TitlePageDTO::Wrapper listAll(const TitleQuery::Wrapper& query);
	//保存职称数据
	uint64_t saveData(const TitleDTO::Wrapper& dto);
	//修改职称数据
	bool updateData(const TitleDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint32_t id);
};

#endif // !_TITLESERVICE_H_