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
#include "ExportExpenseMapper.h"
#include "../dao-sql-macro/macro.h"

#define EXPENSELEDGER_TERAM_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->pimexpaccountname) { \
	sql << " AND `PIMLABOURCAMPANYNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimexpaccountname.getValue("")); \
} \
if (query->pimexpaccountid) { \
	sql << " AND `PIMEXPACCOUNTID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimexpaccountid.getValue("")); \
} \
if(query->updateman) { \
	sql << " AND `UPDATEMAN`=?"; \
	SQLPARAMS_PUSH(params,"s",std::string,query->updateman.getValue("")); \
} \
if (query->createdate) { \
	sql << " AND `CREATEDATE`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->createdate.getValue("")); \
} \
if (query->createman) { \
	sql << " AND `CREATEMAN`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->createman.getValue("")); \
} \
if (query->updatedate) { \
	sql << " AND `UPDATEDATE`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->updatedate.getValue("")); \
} \
if (query->fylb) { \
	sql << " AND `FYLB`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->fylb.getValue("")); \
} \
if (query->fyje) { \
	sql << " AND `FYJE`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->fyje.getValue("")); \
} \
if (query->ffrs) { \
	sql << " AND `FFRS`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ffrs.getValue("")); \
} \
if (query->ffsj) { \
	sql << " AND `FFSJ`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ffsj.getValue("")); \
} \
if (query->ffybz) { \
	sql << " AND `FFYBZ`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ffybz.getValue("")); \
} \
if (query->bz) { \
	sql << " AND `BZ`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->bz.getValue("")); \
} \
if (query->ormorgid) { \
	sql << " AND `ORMORGID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ormorgid.getValue("")); \
} \

#define EXPENSELEDGEREXPORT_TERAM_PARSE(query, sql) \
SqlParams params; \
if (query->pimexpaccountid) { \
	sql << " AND `PIMEXPACCOUNTID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimexpaccountid.getValue("")); \
} \
if (query->fylb) { \
	sql << " AND `FYLB`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->fylb.getValue("")); \
} \

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
	// 分页查找
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ExpenseLedgerMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ExpenseLedgerDO, ExpenseLedgerMapper>(sqlStr, mapper, params);
}

std::list<ExpenseLedgerDO> ExpenseLedgerDAO::selectAll(const ExpenseLedgerDTO::Wrapper& query)
{
	stringstream sql;
	sql << "select tpa.FYLB as '费用类别', tpa.FYJE as '费用金额', tpa.FFRS as '费用人数', tpa.FFSJ as '发放时间', tpa.FFYBZ as '费用标准', tpa.BZ as '备注' FROM t_pimexpaccount as tpa ";
	sql << "WHERE 1=1 ";
	EXPENSELEDGEREXPORT_TERAM_PARSE(query, sql);
	ExportExpenseMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ExpenseLedgerDO, ExportExpenseMapper>(sqlStr, mapper, params);
}

int ExpenseLedgerDAO::update(const ExpenseLedgerDO& uObj)
{
	stringstream sql;
	stringstream fmts; fmts << "%s%d%i%s%s%s%s";
	sql << "UPDATE `t_pimexpaccount` as tpa SET \
		tpa.FYLB = ?,\
		tpa.FYJE = ?,\
		tpa.FFRS = ?,\
		tpa.FFSJ = ?,\
		tpa.FFYBZ = ?,\
		tpa.BZ = ?\
		WHERE tpa.PIMEXPACCOUNTID = ?";
	//cout << sql.str() << endl;
	return sqlSession->executeUpdate(sql.str(), fmts.str().c_str(),
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
	return sqlSession->executeUpdate(sql,"%s%s%s%s%s%s%s%d%i%s%s%s",ido.getName(),ido.getId(),ido.getUpdateman(),ido.getCreatedate(),ido.getCreateman(),ido.getUpdatedate(),ido.getFylb(),ido.getFyje(),ido.getFfrs(),ido.getFfsj(),ido.getFybz(),ido.getBz());
}

uint64_t ExpenseLedgerDAO::deleteById(const ExpenseLedgerDO& obj)
{
	string sql = "DELETE FROM `t_pimexpaccount` WHERE `PIMEXPACCOUNTID` = ?";
	return sqlSession->executeUpdate(sql,"%s",obj.getId());
}

vector<string> ExpenseLedgerDAO::getHead(const ExpenseLedgerDTO::Wrapper& query)
{
	vector<string> head;
	head.push_back(u8"费用类别");
	head.push_back(u8"费用金额");
	head.push_back(u8"发放人数");
	head.push_back(u8"发放时间");
	head.push_back(u8"费用标准");
	return head;
}

