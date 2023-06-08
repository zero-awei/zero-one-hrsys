#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/08 21:23:08

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _GOSHCONTROLLER_H_
#define _GOSHCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Gosh/ContractQuery.h"
#include "domain/dto/Gosh/ContractDTO.h"
#include "domain/vo/Gosh/ContractVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "oatpp/codegen/api_controller/base_define.hpp"
#include "ApiHelper.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * 测试控制器
 */
class GoshController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(GoshController);
public: 
	// 3.1 定义查询合同接口描述
	ENDPOINT_INFO(queryContract) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contract_gosh.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//过滤参数描述
		//1.员工编号
		info->queryParams.add<String>("personid").description = ZH_WORDS_GETTER("contract_gosh.field.personid");
		//ZH_WORDS_GETTER("person_gosh.get.summary");
		info->queryParams["personid"].required = false;
		//2.员工姓名
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("contract_gosh.field.name");
		info->queryParams["name"].required = false;
		//3、员工状态
		info->queryParams.add<String>("person_condition").description = ZH_WORDS_GETTER("contract_gosh.field.person_condition");
		info->queryParams["person_condition"].required = false;
		//4、合同编号
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("contract_gosh.field.id");
		info->queryParams["id"].required = false;
		//5、合同类别
		info->queryParams.add<String>("type").description = ZH_WORDS_GETTER("contract_gosh.field.type");
		info->queryParams["type"].required = false;
		//6、合同状态
		info->queryParams.add<String>("condition").description = ZH_WORDS_GETTER("contract_gosh.field.condition");
		info->queryParams["condition"].required = false;
		//7、起始日期
		info->queryParams.add<String>("date").description = ZH_WORDS_GETTER("contract_gosh.field.date");
		info->queryParams["date"].required = false;
		//8、结束日期
		info->queryParams.add<String>("date_over").description = ZH_WORDS_GETTER("contract_gosh.field.date_over");
		info->queryParams["date_over"].required = false;
		//9、合同类型
		info->queryParams.add<String>("variety").description = ZH_WORDS_GETTER("contract_gosh.field.variety");
		info->queryParams["variety"].required = false;
		//--------------------------------------------------------------------选择显示字段列
		API_DEF_SHOW_PAGE_PARAMS();
		
	}
	 //3.2 定义查询合同接口端点
	ENDPOINT(API_M_GET, "/contract-management/query-contract", queryContract, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, ContractQuery, qps);		
		// 响应结果
		API_HANDLER_RESP_VO(execQueryContract(query, authObject->getPayload()));
	}
	//3.1 定义查询个人信息接口描述
	ENDPOINT_INFO(queryPerson) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("person_gosh.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractPageJsonVO);
		// 定义分页查询参数描述
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("contract_gosh.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = true;
		API_DEF_SHOW_PAGE_PARAMS();
	}
	//3.2 定义查询个人信息接口处理
	ENDPOINT(API_M_GET, "/contract-management/query-person", queryPerson, API_HANDLER_AUTH_PARAME,QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, ContractQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryPerson(query, authObject->getPayload()));
	}
	// 3.1 定义新增合同接口描述
	ENDPOINT_INFO(addContract) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contract_gosh.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增合同接口处理
	ENDPOINT(API_M_POST, "/contract-management/add-contract", addContract, BODY_DTO(ContractDTO_gs_insert::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddContract(dto));
	}
	// 3.1 定义删除合同接口描述
	ENDPOINT_INFO(removeContract) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contract_gosh.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义删除合同接口处理
	ENDPOINT(API_M_DEL, "/contract-management/remove-contract", removeContract, BODY_DTO(ContractDTO_gs_delete::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveContract(dto));
	}

private: // 定义接口执行函数

	// 3.3 演示查询合同信息
	ContractPageJsonVO::Wrapper execQueryContract(const ContractQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 演示查询个人信息
	ContractPageJsonVO::Wrapper execQueryPerson(const ContractQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 演示新增合同数据
	Uint64JsonVO::Wrapper execAddContract(const ContractDTO_gs_insert::Wrapper& dto);
	// 3.3 演示删除合同数据
	Uint64JsonVO::Wrapper execRemoveContract(const ContractDTO_gs_delete::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_