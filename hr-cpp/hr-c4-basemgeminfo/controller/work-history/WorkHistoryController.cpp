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

Uint64JsonVO::Wrapper WorkHistoryController::execAddWorkHistory(const AddWorkHistoryDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	if (!dto->bm || !dto->gw || !dto->ormrankid || !dto->pimpersonid || !dto->servebegintime || \
		!dto->serveendtime || !dto->workunit || !dto->zw)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	jvo->success(1);

	return jvo;
}

Uint64JsonVO::Wrapper WorkHistoryController::execDelWorkHistory(const DelWorkHistoryDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	int length = dto->deleteById->size();

	if (length <= 0 || !dto->pimpersonid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	else
	{
		for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
		{
			if (!(*it))
			{
				jvo->init(UInt64(-1), RS_PARAMS_INVALID);
				return jvo;
			}
		}
	}

	jvo->success(1);

	return jvo;

}
