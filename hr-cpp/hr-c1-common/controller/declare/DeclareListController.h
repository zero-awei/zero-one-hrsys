#pragma once
#ifndef _DECLARELIST_CONROLLER_
#define _DECLARELIST_CONROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/vo/declare/DeclareVO.h"
#include "domain/query/declare/DeclareQuery.h"
#include "domain/vo/declare/DeclareVO.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

class DeclareListController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(DeclareListController);
public:
	//定义查询接口描述
	ENDPOINT_INFO(queryDeclare) {
		info->summary = ZH_WORDS_GETTER("t_pcmprofile.get.declaretype");
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DeclareListJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("declare").description = ZH_WORDS_GETTER("t_pcmprofile.field.declaretype");
		info->queryParams["declare"].addExample("default", String("A"));
	}
	//定义查询接口处理
	ENDPOINT(API_M_GET, "/declare", queryDeclare, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		//解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, DeclareQuery, queryParams);
		//响应结果
		API_HANDLER_RESP_VO(execQueryDeclare(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 演示分页查询数据
	DeclareListJsonVO::Wrapper execQueryDeclare(const DeclareQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) 
#endif