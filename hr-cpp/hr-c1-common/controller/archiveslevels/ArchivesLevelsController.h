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
		info->summary = ZH_WORDS_GETTER("common.get.archiveslevels");
		info->queryParams.add<String>("层级").description = ZH_WORDS_GETTER("archiveslevels");
		info->queryParams["层级"].addExample("default", String("up"));
		info->queryParams["层级"].required = false;
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesListVO);
	}
	ENDPOINT(API_M_GET, "/archives", queryArchivesLevels) {
		// 响应结果
		API_HANDLER_RESP_VO(execQueryArchivesLevels());
		return createResponse(Status::CODE_203, "OK");
	}
	
private:
	ArchivesListVO::Wrapper execQueryArchivesLevels();
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_ARCHIVESLEVELS_CONTROLLER_