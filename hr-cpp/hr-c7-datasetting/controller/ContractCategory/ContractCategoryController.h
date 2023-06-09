#pragma once
#ifndef _CONTRACTCATEGORYCONTROLLER_H_
#define _CONTRACTCATEGORYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/contractcategory/ContractCategoryQuery.h"
#include "domain/dto/contractcategory/ContractCategoryDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 合同类别查询控制器
 */
class ContractCategoryController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(ContractCategoryController);

public:
    ENDPOINT_INFO(queryContractCategory) {
        info->summary = ZH_WORDS_GETTER("contractCategory.query-all.summary");
        API_DEF_ADD_RSP_JSON_WRAPPER(ContractCategoryPageDTO);
        API_DEF_ADD_PAGE_PARAMS();
        info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
        info->queryParams["name"].addExample("default", String("t**"));
        info->queryParams["name"].required = false;
    }
    ENDPOINT(API_M_GET, "/contractcategory/query-contractCategory", queryContractCategory, QUERIES(QueryParams, qps)) {
        API_HANDLER_QUERY_PARAM(query, ContractCategoryQuery, qps);
        API_HANDLER_RESP_VO(execQueryContractCategory(query));
    }

    ENDPOINT_INFO(addContractCategory) {
        info->summary = ZH_WORDS_GETTER("contractCategory.post.summary");
        API_DEF_ADD_RSP_JSON_WRAPPER(ContractCategoryDTO);
    }
    ENDPOINT(API_M_POST, "/contractcategory/add-contractCategory", addContractCategory, BODY_DTO(ContractCategoryDTO::Wrapper, dto)) {
        API_HANDLER_RESP_VO(execAddContractCategory(dto));
    }

    ENDPOINT_INFO(modifyContractCategory) {
        info->summary = ZH_WORDS_GETTER("contractCategory.put.summary");
        API_DEF_ADD_RSP_JSON_WRAPPER(ContractCategoryDTO);
    }
    ENDPOINT(API_M_PUT, "/contractcategory/modify-contractCategory", modifyContractCategory, BODY_DTO(ContractCategoryDTO::Wrapper, dto)) {
        API_HANDLER_RESP_VO(execModifyContractCategory(dto));
    }

	ENDPOINT_INFO(removeContractCategory) {
		info->summary = ZH_WORDS_GETTER("contractCategory.delete.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_DEL, "/contractcategory/remove-contractCategory/{id}", removeContractCategory, PATH(UInt64, id)) {
		API_HANDLER_RESP_VO(execRemoveContractCategory(id));
	}


private:
    ContractCategoryPageDTO::Wrapper execQueryContractCategory(const ContractCategoryQuery::Wrapper& query);
    Uint64JsonVO::Wrapper execAddContractCategory(const ContractCategoryDTO::Wrapper& dto);
    Uint64JsonVO::Wrapper execModifyContractCategory(const ContractCategoryDTO::Wrapper& dto);
    Uint64JsonVO::Wrapper execRemoveContractCategory(uint64_t id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_CONTRACTCATEGORYCONTROLLER_H_
