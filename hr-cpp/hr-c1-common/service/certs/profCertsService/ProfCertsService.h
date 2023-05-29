#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/24 14:08:56

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
#ifndef _PROFCERTS_SERVICE_
#define _PROFCERTS_SERVICE_
#include <list>
#include "domain/vo/certs/ProfCertsVO.h"
#include "domain/dto/certs/ProfCertsDTO.h"
#include "domain/query/certs/ProfCertsQuery.h"

/**
 * 职业资格证书类型下拉列表Service
 * 负责人 : rice
 */
class ProfCertsService
{
public:
	// 查询所有数据
	ProfCertsListDTO::Wrapper listAll(const ProfCertsQuery::Wrapper& query);
};

#endif // !_PROFCERTS_SERVICE_

