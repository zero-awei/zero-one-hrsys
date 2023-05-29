/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/24 14:26:52

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
#include "ProfCertsDAO.h"
#include "ProfCertsMapper.h"
#include <sstream>


list<ProfCertsDO> ProfCertsDAO::selectWithPage(const ProfCertsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t1.*, IFNULL(t2.PIMQUALTYPENAME, NULL) AS PIMQUALTYPENAME FROM t_pimqualmajor t1 LEFT JOIN t_pimqualtype t2 ON t1.PIMQUALTYPEID = t2.PIMQUALTYPEID";
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProfCertsMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProfCertsDO, ProfCertsMapper>(sqlStr, mapper);
}

uint64_t ProfCertsDAO::count(const ProfCertsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimqualmajor";
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr);
}
