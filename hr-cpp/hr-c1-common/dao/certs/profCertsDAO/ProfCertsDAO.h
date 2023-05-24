#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/24 14:35:49

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
#ifndef _PROFCERTS_DAO_
#define _PROFCERTS_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/certs/ProfCertsDO.h"
#include "../../../domain/query/certs/ProfCertsQuery.h"
/**
 * 职业资格证书类型下拉列表DAO
 * 负责人 : rice
 */
class ProfCertsDAO : public BaseDAO
{
public:
	list<ProfCertsDO> selectWithPage(const ProfCertsQuery::Wrapper& query);
	uint64_t count(const ProfCertsQuery::Wrapper& query);
};
#endif // !_PROFCERTS_DAO_
