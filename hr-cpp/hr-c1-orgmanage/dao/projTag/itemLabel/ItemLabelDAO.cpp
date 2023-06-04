/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanchen
 @Date: 2023/05/31 21:32:07

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
#include "stdafx.h"
#include "ItemLabelDAO.h"
#include "ItemLabelMapper.h"
#define PROJTAGLIST_TERAM_PARSE(__QUERY__, __SQL__) \
SqlParams params; \
__SQL__ << " WHERE 1=1"; \
if (__QUERY__->itemLabel) { \
	__SQL__ << " AND `ORMXMBQNAME` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, __QUERY__->itemLabel.getValue("")); \
} \

std::list<ProjTagDO> ItemLabelDAO::selectItemLabelList(const ItemLabelQuery::Wrapper& query)
{
	stringstream sql;

	sql << "SELECT `ORMXMBQID`, `CREATEMAN`, `ORMXMBQNAME`, `UPDATEMAN`, `CREATEDATE`, `UPDATEDATE`,"
		<< "`ORMORGID` FROM `t_ormxmbq` ";
	PROJTAGLIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ItemLabelMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProjTagDO, ItemLabelMapper>(sqlStr, mapper, params);
}