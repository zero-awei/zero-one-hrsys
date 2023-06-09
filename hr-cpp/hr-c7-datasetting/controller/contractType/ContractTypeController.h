#pragma once
#ifndef _CONTRACTCONTROLLER_H_
#define _CONTRACTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
//#include "ApiHelper.h"
#include "domain/query/ContractType/ContractTypeQuery.h"
#include "domain/dto/ContractType/ContractTypeDTO.h"
#include "domain/vo/ContractType/ContractTypeVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * 合同查询控制器
 */
class ContractTypeController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ContractTypeController);
public: // 定义接口
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryContract) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contractType.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractTypePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 添加其他查询参数
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("contractType.field.name");
		info->queryParams["name"].addExample("default", String("he tong ming"));
		info->queryParams["name"].required = false;
	}
	// 3.1 定义查询接口端点
	ENDPOINT(API_M_GET, "/contracttype/query-contractType", queryContract, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(ContractTypeQuery, ContractTypeQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryContractType(ContractTypeQuery, authObject->getPayload()));
	}
	// 定义新增接口描述
	ENDPOINT_INFO(addContractType) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contractType.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractTypeJsonVO);
	}
	// 定义新增接口处理
	ENDPOINT(API_M_POST, "/contracttype/add-contractType", addContractType, BODY_DTO(ContractTypeDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddContractType(dto));
	}
	// 定义修改接口描述
	ENDPOINT_INFO(modifyContractType) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contractType.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractTypeJsonVO);
	}
	// 定义修改接口处理
	ENDPOINT(API_M_PUT, "/contracttype/modify-contractType", modifyContractType, BODY_DTO(ContractTypeDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyContractType(dto));
	}
	// 定义删除接口描述
	ENDPOINT_INFO(removeContractType) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contractType.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractTypeJsonVO);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/contract/remote-contractType", removeContractType, BODY_DTO(ContractTypeDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveContractType(dto));
	}
private: // 定义接口执行函数
	// 5 定义接口的执行函数
	//ContractTypePageJsonVO::Wrapper ContractController::execQueryContractType(const ContractTypeQuery::Wrapper & query)
	ContractTypePageJsonVO::Wrapper execQueryContractType(const ContractTypeQuery::Wrapper& query, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execAddContractType(const ContractTypeDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execModifyContractType(const ContractTypeDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execRemoveContractType(const ContractTypeDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_CONTRACTCONTROLLER_H_