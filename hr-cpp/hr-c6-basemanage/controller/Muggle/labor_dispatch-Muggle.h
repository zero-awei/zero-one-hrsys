#pragma once
#ifndef _LD_M_CONTROLLER
#define _LD_M_CONTROLLER

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Muggle/laborDispatchQuery.h"
#include "domain/dto/Muggle/laborDispatchDTO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class LaborDispatchMController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(LaborDispatchMController);
public:
	// 查询指定公司信息
	ENDPOINT_INFO(queryLaborDispatch) {
		info->summary = ZH_WORDS_GETTER("labordispatch_mug.get.summary");
		//API_DEF_ADD_RSP_JSON_WRAPPER()
		info->queryParams.add<String>("corporateName").description = ZH_WORDS_GETTER("labordispatch_mug.field.corporatename");;
		info->queryParams["corporateName"].addExample("default", String("PDD"));
		//info->queryParams["corporateName"].required = false;
	}

	ENDPOINT(API_M_GET, "/query-by-corporate-name", queryLaborDispatch,QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, LaborDispatchMQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryLaborDispatch());
	}

	
	// 修改指定公司信息
	ENDPOINT_INFO(modifyLaborDispatch) {
		info->summary = ZH_WORDS_GETTER("labordispatch_mug.modify.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	ENDPOINT(API_M_DEL, "/modify-labor-dispatch-corporate", modifyLaborDispatch, BODY_DTO(LaborDispatchMDTO::Wrapper, dto)) {
		API_HANDLER_RESP_VO(execModifyLaborDispatch());
	}
private:
	StringJsonVO::Wrapper execQueryLaborDispatch();


	StringJsonVO::Wrapper execModifyLaborDispatch();
};
#endif // !_LD_M_CONTROLLER
