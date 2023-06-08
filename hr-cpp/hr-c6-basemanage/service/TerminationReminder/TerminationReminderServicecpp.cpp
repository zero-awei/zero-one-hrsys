#include "stdafx.h"
#include "TerminationReminderService.h"
TerminationReminderPageDTO::Wrapper TerminationReminderService::listAll(const TerminationReminderQuery::Wrapper& query)
{
	auto page = TerminationReminderPageDTO::createShared();
	page->pageIndex = query->pageIndex;
	page->pageSize = query->pageSize;
	TerminationReminderDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return page;
	}
	page->total = count;
	page->calcPages();
	list<TerminationReminderDO> result = dao.selectWithPage(query);
	// ½«DO×ª»»³ÉDTO
	for (TerminationReminderDO sub : result)
	{
		auto dto = TerminationReminderDTO::createShared();
		//dto->arrived_time = sub.getArrivedTime();
		//dto->begin_time = sub.getBeginTime();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			employee_id, EmployeeId, employee_name, EmployeeName,
			employee_part, EmployeePart, employee_status, EmployeeStatus,
			arrived_time, ArrivedTime, contract_id, ContractId,
			contract_sign_part, ContractSignPart, contract_lb, ContractLB,
			contract_lx, ContractLX, begin_time, BeginTime, deadline, Deadline)
			page->addData(dto);
	}
	return page;
}

std::string TerminationReminderService::exportAll(const TerminationReminderQuery::Wrapper& query)
{
	TerminationReminderDAO dao;
	list<TerminationReminderDO> result = dao.selectAll(query);
	vector<vector<string>>data;
	data.push_back(vector<string>());
	data[0].push_back("employee_id");
	data[0].push_back("employee_name");
	data[0].push_back("employee_part");
	data[0].push_back("employee_status");
	data[0].push_back("arrived_time");
	data[0].push_back("contract_id");
	data[0].push_back("contract_sign_part");
	data[0].push_back("contract_lb");
	data[0].push_back("contract_lx");
	data[0].push_back("begin_time");
	data[0].push_back("deadline");
	int i = 1;
	for (TerminationReminderDO sub : result)
	{
		data.push_back(vector<string>());
		data[i].push_back(sub.getEmployeeId());
		data[i].push_back(sub.getEmployeeName());
		data[i].push_back(sub.getEmployeePart());
		data[i].push_back(sub.getEmployeeStatus());
		data[i].push_back(sub.getArrivedTime());
		data[i].push_back(sub.getContractId());
		data[i].push_back(sub.getContractSignPart());
		data[i].push_back(sub.getContractLB());
		data[i].push_back(sub.getContractLX());
		data[i].push_back(sub.getBeginTime());
		data[i].push_back(sub.getDeadline());
		i++;
	}
	return ChangeToExcel::changeToExcel(data);
}

