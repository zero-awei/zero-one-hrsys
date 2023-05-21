#pragma once
#ifndef _ARCHIVESLEVELS_CONTROLLER_
#define _ARCHIVESLEVELS_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/archivesLevelsDto/archivesLevelsDTO.h"
#include "domain/query/archivesListQuery/ArchivesQuery.h"
#include "domain/vo/archivesList/ArchivesListVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ArchivesLevelsController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(ArchivesLevelsController);
public:
	ENDPOINT_INFO(queryArchivesLevels) {
		info->summary = ZH_WORDS_GETTER("common.controller.archivesLevel");
	}
	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/archives-level"), queryArchivesLevels) {
		// ÏìÓ¦½á¹û
		API_HANDLER_RESP_VO(execQueryArchivesLevels());
	}
private:
	ArchivesListVO::Wrapper execQueryArchivesLevels();
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_ARCHIVESLEVELS_CONTROLLER_