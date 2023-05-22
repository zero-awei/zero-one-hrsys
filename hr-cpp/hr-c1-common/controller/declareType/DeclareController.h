//



#pragma once
#ifndef _DECLARE_CONTROLLER_
#define _DECLARE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/declareList/DeclareListVO.h"
#include "domain/dto/declareDto/declareDTO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class DeclareController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(DeclareController);
public:
	ENDPOINT_INFO(queryDeclare) {
		info -> summary = ZH_WORDS_GETTER("common.controller.declareType");
		API_DEF_ADD_RSP_JSON_WRAPPER(DeclareListVO);
	}
	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/declare-type"), queryDeclare) {
		// ÏìÓ¦½á¹û
		API_HANDLER_RESP_VO(execQueryDeclare());
		return createResponse(Status::CODE_202, "OK");
	}
	
private:
	DeclareListVO::Wrapper execQueryDeclare();
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_DECLARE_CONTROLLOR_