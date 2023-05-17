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
#ifndef _SciResultCONTROLLER_H_
#define _SciResultCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/SciResult/SciResultQuery.h"
#include "domain/vo/SciResult/SciResultVO.h"
#include "domain/dto/SciResult/DelSciResultDTO.h"
#include "domain/dto/SciResult/SciResultDTO.h"
#include "domain/dto/SciResult/AddSciResultDTO.h"
#include "domain/dto/SciResult/IntoSciResultDTO.h"
#include <oatpp-swagger/Types.hpp>
#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * 查询控制器
 */
class SciResultController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(SciResultController);
public: // 定义接口
	// 3 定义接口描述
	ENDPOINT_INFO(querySciResult) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("sample.get.summary");
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(SciResultPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 添加其他查询参数
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
	}
	// 4 定义接口端点
	ENDPOINT(API_M_GET, "/SciResult", querySciResult, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, SciResultQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryTest(query));
	}

	//新增指定员工科研成果(单条新增)
	ENDPOINT_INFO(AddSciResult) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("sample.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/SciResult/add", AddSciResult, BODY_DTO(AddSciResultDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddSciResult(dto));
	}


	// 删除员工科研成果(支持批量删除)
	ENDPOINT_INFO(DelSciResult) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("sample.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义批量删除接口处理
	ENDPOINT(API_M_POST, "/SciResult/del", DelSciResult, BODY_DTO(DelSciResultDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execDelSciResult(dto));
	}

	//导入指定员工科研成果
	ENDPOINT_INFO(postFile) {
		info->summary = ZH_WORDS_GETTER("Into.fileinto");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("sciresult.file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
	}
	// 定义文件上传端点处理
	ENDPOINT(API_M_POST, "/sciresult/file", postFile, BODY_STRING(String, body), QUERY(String, suffix)) {
		// 执行文件保存逻辑
		API_HANDLER_RESP_VO(execIntoSciResult(body, suffix));
	}






private: // 定义接口执行函数
	// 5 定义接口的执行函数
	//定义查询执行函数
	SciResultPageJsonVO::Wrapper execQueryTest(const SciResultQuery::Wrapper& query);
	//定义新增试行函数
	Uint64JsonVO::Wrapper execAddSciResult(const AddSciResultDTO::Wrapper& dto);
	//定义删除执行函数
	Uint64JsonVO::Wrapper execDelSciResult(const DelSciResultDTO::Wrapper& dto);
	//定义导入执行函数
	StringJsonVO::Wrapper execIntoSciResult(const String body, const String suffix);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_CONTRACTCONTROLLER_H_