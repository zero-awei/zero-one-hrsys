#pragma once

#ifndef _DECLARE_CONTROLLER_
#define _DECLARE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/declareList/DeclareListVO.h"
#include "domain/dto/declareType/DeclareTypeDTO.h"
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
		API_DEF_ADD_AUTH();
	}
	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/declare-type"), queryDeclare, API_HANDLER_AUTH_PARAME) {
		// ÏìÓ¦½á¹û
		API_HANDLER_RESP_VO(execQueryDeclare());
	}
	
private:
	DeclareListVO::Wrapper execQueryDeclare();
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_DECLARE_CONTROLLOR_