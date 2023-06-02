#include "stdafx.h"
#include "JobUpdateService.h"
#include "SimpleDateTimeFormat.h"

bool JobUpdateService::updateJobInfo(const JobUpdateDTO::Wrapper& dto, const PayloadDTO& payload)
{
    PostDetailDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Gwfl, gwfl, IsConfidential, isConfidential, OrmPostName, ormPostName, 
		IsKeyPostion, isKeyPostion, PostNature, postNature, StartStopSign, startStopSign, OrmPostId, ormPostId,
		GwType, gwType, IsTemp, isTemp, OrmOrgId, ormOrgId, Nx, nx, Bxjlnx, bxjlnx);

	data.setUpdateMan(payload.getUsername());
	data.setUpdateDate(SimpleDateTimeFormat::format());

	JobUpdteDAO dao;
    return dao.updateJob(data);
}
