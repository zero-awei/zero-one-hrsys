/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/20 10:46:22

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
#include <sstream>
#include "LaborDispatchDAO-mg.h"
#include "../laborDispatch/LaborDispatchMapper-mh.h"


#define LABORDISPATCH_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->corporateName) { \
	sql << " AND `PIMLABOURCAMPANYNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->corporateName.getValue("")); \
} \
//if(query->id) { \
//	sql << " AND `PIMLABOURCAMPANYID`=?"; \
//	SQLPARAMS_PUSH(params,"s",std::string,query->id.getValue("")); \
//} 

uint64_t LaborDispatchMDAO::count(const LaborDispatchMQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimlabourcampany";
	LABORDISPATCH_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<LaborDispatchDO> LaborDispatchMDAO::selectByCorporateName(const LaborDispatchMQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM t_pimlabourcampany";
	LABORDISPATCH_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	LaborDispatchMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<LaborDispatchDO, LaborDispatchMapper>(sqlStr, mapper, params);
}

int LaborDispatchMDAO::update(const LaborDispatchDO& uDo)
{
	string sql = "UPDATE `t_pimlabourcampany` SET  `LXDZ`=?, `LXR`=?, `LXFS`=?, `LEGALPEROSN`=?, `REGCAPITAL`=?, `GSJJ`=? WHERE `PIMLABOURCAMPANYNAME`=?";
	return sqlSession->executeUpdate(sql,"%s%s%s%s%s%s%s",uDo.getLxdz(),uDo.getLxr(),uDo.getLxfs(),uDo.getLegalperson(),uDo.getRegcapital(),uDo.getGsjj(), uDo.getName());
}
