#include "stdafx.h"
#include "ExpenseLedgeService.h"
#include "domain/dto/ExpenseLedger/ExpenseLedgerDTO.h"
#include "dao/expenseLedger/ExpenseLedgerDAO.h"
#include "domain/do/expenseLedger/ExpenseLedgerDO.h"
#include "../../uselib/excel/ExportExcel.h"
#include "../../uselib/fastdfs/UseFastDfs.h"

std::string ExpenseLedgerService::listAllExpense(const ExpenseLedgerDTO::Wrapper& query)
{
	std::string url;
	ExpenseLedgerDAO dao;
	auto countQuery = ExpenseLedgerPageQuery::createShared();
	countQuery->fylb = query->fylb;
	uint64_t count = dao.count(countQuery);
	if (count <= 0)
	{
		return url;
	}

	list<ExpenseLedgerDO> resultDO = dao.selectAll(query);
	vector<vector<string>> data;
	// 将DO转换成二维数组
	for (auto const& sub : resultDO)
	{
		vector<string> temp;
		temp.push_back(sub.getFylb());
		temp.push_back(std::to_string(sub.getFyje()));
		temp.push_back(std::to_string(sub.getFfrs()));
		temp.push_back(sub.getFfsj());
		temp.push_back(sub.getFybz());
		data.push_back(temp);
	}

	// 生成数据表表头
	vector<string> head = dao.getHead(query);
	//head.erase(head.begin() + 12,head.end());
	data.insert(data.begin(), head);
	// 生成Excel
	ExportExcel excel;
	string filename = excel.exportExcel(data);
	UseFastDfs dfs("8.130.87.15");
	url = dfs.uploadWithNacos(filename);
	return url;
}

ExpenseLedgerDTO::Wrapper ExpenseLedgerService::queryDataDetail(const ExpenseLedgerDTO::Wrapper& query)
{
	ExpenseLedgerDAO dao;
	auto resD0 = dao.selectAll(query);
	auto resDTO = ExpenseLedgerDTO::createShared();
	resDTO->fylb = resD0.front().getFylb();
	resDTO->fyje = resD0.front().getFyje();
	resDTO->ffrs = resD0.front().getFfrs();
	resDTO->ffsj = resD0.front().getFfsj();
	resDTO->ffybz = resD0.front().getFybz();
	resDTO->bz = resD0.front().getBz();
	return resDTO;
}

bool ExpenseLedgerService::updateData(const ExpenseLedgerDTO::Wrapper& dto)
{
	ExpenseLedgerDAO dao;
	ExpenseLedgerDO data;
	data.setFylb(dto->fylb);
	data.setFyje(dto->fyje);
	data.setFfrs(dto->ffrs);
	data.setFfsj(dto->ffsj);
	data.setFybz(dto->ffybz);
	data.setBz(dto->bz);
	data.setId(dto->pimexpaccountid);
	auto res = dao.update(data);
	return !!res;
}
