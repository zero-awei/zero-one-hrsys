#pragma once
#include <list>
#include <vector>
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/TerminationReminderVO/TerminationReminderVO.h"
#include "domain/dto/TerminationReminderDTO/TerminationReminderDTO.h"
#include "domain/query/TerminationReminder/TerminationReminderQuery.h"
#include "dao/TerminationReminder/TerminationReminderDAO.h"
#include "dao/TerminationReminder/TerminationReminderMapper.h"
#include "uselib/excel/TerminationRemidner/ChangeToExcel.h"

class TerminationReminderService
{
public:
	// 分页查询所有数据
	TerminationReminderPageDTO::Wrapper listAll(const TerminationReminderQuery::Wrapper& query);
	// 保存数据
	//uint64_t saveData(const TerminationReminderDTO::Wrapper& dto);
	std::string exportAll(const TerminationReminderQuery::Wrapper& query);
};