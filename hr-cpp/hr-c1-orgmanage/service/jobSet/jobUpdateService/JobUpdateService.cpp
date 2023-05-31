#include "stdafx.h"
#include "JobUpdateService.h"

bool JobUpdateService::uodateJobInfo(const JobUpdateDTO::Wrapper& dto)
{
    PostDetailDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Gwfl, gwfl, IsConfidential, isConfidential, OrmPostName, ormPostName, 
		IsKeyPostion, isKeyPostion, PostNature, postNature, StartStopSign, startStopSign, OrmPostId, ormPostId,
		GwType, gwType, IsTemp, isTemp, OrmOrgId, ormOrgId, UpdateDate, updateDate, UpdateMan, updateMan);

	JobUpdteDAO dao;
    return dao.updateJob(data);
}
