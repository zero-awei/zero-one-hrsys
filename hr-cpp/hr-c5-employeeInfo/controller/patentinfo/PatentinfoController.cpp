#include "stdafx.h"
#include "PatentinfoController.h"
#include "service/patentinfo/patentinfoService.h"


//根据id删除专利信息
Uint64JsonVO::Wrapper PatentinfoController::execRemovePatent(const List<String>& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	int length = dto->size();
	if (length <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto it = dto->begin(); it != dto->end(); ++it)
	{
		if (!(*it))
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	
	PatentinfoService service;
	if (service.removeData(dto))
	{
		jvo->success(1);
	}
	else
	{
		jvo->fail(1);
	}
	return jvo;

}

