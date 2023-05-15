#include "stdafx.h"
#include "WorkHistoryController.h"


WorkHistoryFindVO::Wrapper WorkHistoryController::execQueryWorkHistory(const WorkHistoryPageQuery::Wrapper& query)
{
	auto vo = WorkHistoryFindVO::createShared();

	auto pdto = WorkHistoryFindPageDTO::createShared();

	pdto->addData(WorkHistoryFindDTO::createShared("ASDA", "DFSF", "HF", "FS", "WEFE", "TGRE", "HYT", "FSD"));
	pdto->addData(WorkHistoryFindDTO::createShared("ASDSDA", "DFDFSF", "HASF", "FAS", "WEFACE", "TGASDRE", "HADYT", "FSD"));

	vo->success(pdto);

	return vo;
	
}
