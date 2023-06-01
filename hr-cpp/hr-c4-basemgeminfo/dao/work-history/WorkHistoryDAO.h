#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/18 10:43:10

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
#ifndef _WORKHISTORYDAO_H_
#define _WORKHISTORYDAO_H_

#include "BaseDAO.h"
#include "domain/query/work-history/WorkHistoryPageQuery.h"
#include "domain/do/work-history/WorkHIstoryFindPageDO.h"

//陈靓仔
#include "../../domain/do/work-history/WorkHistoryDO.h"
#include "../../domain/query/work-history/WorkHistoryQuery.h"
#include "domain/do/work-history/AddWorkHistoryDO.h"
#include "domain/query/work-history/WorkHistoryExportQuery.h"
#include "domain/do/work-history/ModWorkHistoryDO.h"
class WorkHistoryDAO : public BaseDAO
{
public:
	// 分页查询数据
	list<WorkHistoryFindDO> selectWithPage(const WorkHistoryPageQuery::Wrapper& query);
	
	// 统计数据条数
	uint64_t count(const WorkHistoryPageQuery::Wrapper& query);

	//插入数据
	uint64_t insert(const AddWorkHistoryDO& iObj);

	//删除数据（支持批量删除数据）
	int deleteById(std::string pimpersonid, std::string pimworkhistoryid);


	//查询数据，把查询的数据填入Excel中
	list<WorkHistoryFindDO> selectAllData(const WorkHistoryExportQuery::Wrapper& query);



	//陈靓仔
	list<WorkHistoryDO> selectDetail(const WorkHistoryQuery::Wrapper& query);

	int update(const ModWorkHistoryDO& uObj);
};



#endif // !_WORKHISTORYDAO_H_





