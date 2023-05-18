#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 19:59:13

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
#ifndef _MILITARYDAO_H_
#define _MILITARYDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/military/MilitaryDO.h"
#include "../../domain/query/military/MilitaryQuery.h"

class MilitaryDAO : public BaseDAO
{
public:
	// 查询详情数据
	list<MilitaryDO> selectDetail(const MilitaryDetailQuery::Wrapper& query);
	// 修改数据
	int update(const MilitaryDO& uObj);
	// 分页查询数据
	list<MilitaryDO> selectWithPage(const MilitaryDownloadQuery::Wrapper& query);

};

#endif // !_MILITARYDAO_H_

