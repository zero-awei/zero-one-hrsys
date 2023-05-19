#pragma once
#ifndef _DECLARE_CONTROLLER_
#define _DECLARE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/vo/declareList/DeclareListVO.h"
#include "domain/dto/declareDto/declareDTO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

class DeclareController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(DeclareController);
public:
	ENDPOINT_INFO(queryDeclare) {
		info -> summary = ZH_WORDS_GETTER("common.get.declare");
	}
	ENDPOINT(API_M_GET, "/declare", queryDeclare, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ÏìÓ¦½á¹û
		API_HANDLER_RESP_VO(execQueryDeclare());
	}
private:
	DeclareListVO::Wrapper execQueryDeclare();
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_DECLARE_CONTROLLOR_