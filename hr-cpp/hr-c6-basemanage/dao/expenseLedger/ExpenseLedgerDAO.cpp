/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/27 9:06:20

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
#include "ExpenseLedgerDAO.h"
#include "ExpenseLedgerMapper.h"
#include "../dao-sql-macro/macro.h"

#define EXPENSELEDGER_TERAM_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->PIMEXPACCOUNTNAME) { \
	sql << " AND `PIMLABOURCAMPANYNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->PIMEXPACCOUNTNAME.getValue("")); \
} \
if (query->PIMEXPACCOUNTID) { \
	sql << " AND `PIMEXPACCOUNTID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->PIMEXPACCOUNTID.getValue("")); \
} \
if(query->UPDATEMAN) { \
	sql << " AND `UPDATEMAN`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->UPDATEMAN.getValue("")); \
} \
if (query->CREATEDATE) { \
	sql << " AND `CREATEDATE`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->CREATEDATE.getValue("")); \
} \
if (query->CREATEMAN) { \
	sql << " AND `CREATEMAN`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->CREATEMAN.getValue("")); \
} \
if (query->UPDATEDATE) { \
	sql << " AND `UPDATEDATE`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->UPDATEDATE.getValue("")); \
} \
if (query->FYLB) { \
	sql << " AND `FYLB`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->FYLB.getValue("")); \
} \
if (query->FYJE) { \
	sql << " AND `FYJE`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->FYJE.getValue("")); \
} \
if (query->FFRS) { \
	sql << " AND `FFRS`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->FFRS.getValue("")); \
} \
if (query->FFSJ) { \
	sql << " AND `FFSJ`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->FFSJ.getValue("")); \
} \
if (query->FFYBZ) { \
	sql << " AND `FFYBZ`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->FFYBZ.getValue("")); \
} \
if (query->BZ) { \
	sql << " AND `BZ`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->BZ.getValue("")); \
} \

inline SqlParams expenseledge_teram_parse(const ExpenseLedgeDTO::Wrapper & query, stringstream & sql)
{
	SqlParams params;
	sql << " WHERE 1=1";
	SQLPARAMS_INT_PUSH(FFRS);
	SQLPARAMS_INT_PUSH(PIMEXPACCOUNTID);
	SQLPARAMS_FLOAT_PUSH(FYJE);
	SQLPARAMS_STRING_PUSH(PIMEXPACCOUNTNAME);
	SQLPARAMS_STRING_PUSH(FFSJ);
	SQLPARAMS_STRING_PUSH(FFYBZ);
	return params;
}

uint64_t ExpenseLedgerDAO::count(const ExpenseLedgerPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimexpaccount";
	EXPENSELEDGER_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);

}

std::list<ExpenseLedgerDO> ExpenseLedgerDAO::selectByPageQuery(const ExpenseLedgerPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM t_pimexpaccount";
	EXPENSELEDGER_TERAM_PARSE(query, sql);
	// ·ÖÒ³²éÕÒ
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ExpenseLedgerMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ExpenseLedgerDO, ExpenseLedgerMapper>(sqlStr, mapper, params);
}

std::list<ExpenseLedgerDO> ExpenseLedgerDAO::selectAll(const ExpenseLedgeDTO::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM t_pimexpaccount";
	SqlParams params = expenseledge_teram_parse(query, sql);
	ExpenseLedgerMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ExpenseLedgerDO, ExpenseLedgerMapper>(sqlStr, mapper, params);
}

int ExpenseLedgerDAO::update(const ExpenseLedgerDO& uObj)
{
	stringstream sql;
	stringstream fmts;
	sql << "UPDATE `t_pimexpaccount` SET ";
	SQLPARAMS_UPDATE_STRING(name);
	SQLPARAMS_UPDATE_STRING(updateman);
	SQLPARAMS_UPDATE_STRING(createdate);
	SQLPARAMS_UPDATE_STRING(createman);
	SQLPARAMS_UPDATE_STRING(updatedate);
	SQLPARAMS_UPDATE_STRING(fylb);
	SQLPARAMS_UPDATE_FLOAT(fyje);
	SQLPARAMS_UPDATE_INT(ffrs);
	SQLPARAMS_UPDATE_STRING(ffsj);
	SQLPARAMS_UPDATE_STRING(fybz);
	SQLPARAMS_UPDATE_PUSH_FINAL(bz,"%s",id);
	return sqlSession->executeUpdate(sql.str(), fmts.str().c_str(),
		uObj.getName(),
		uObj.getUpdateman(),
		uObj.getCreatedate(),
		uObj.getCreateman(),
		uObj.getUpdatedate(),
		uObj.getFylb(),
		uObj.getFyje(),
		uObj.getFfrs(),
		uObj.getFfsj(),
		uObj.getFybz(),
		uObj.getBz(),
		uObj.getId());
}

uint64_t ExpenseLedgerDAO::insert(const ExpenseLedgerDO& ido)
{
	string sql = "INSERT INTO `t_pimexpaccount` (`PIMEXPACCOUNTNAME`, `PIMEXPACCOUNTID`, `UPDATEMAN`, `CREATEDATE`, `CREATEMAN`, `UPDATEDATE`, `FYLB`, `FYJE`, `FFRS`, `FFSJ`, `FFYBZ`, `BZ`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeInsert(sql,"%s%s%s%s%s%s%s%d%i%s%s%s",ido.getName(),ido.getId(),ido.getUpdateman(),ido.getCreatedate(),ido.getCreateman(),ido.getUpdatedate(),ido.getFylb(),ido.getFyje(),ido.getFfrs(),ido.getFfsj(),ido.getFybz(),ido.getBz());
}
