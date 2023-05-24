#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/15 15:25:13

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
#ifndef _MHCONSTROLLER_H_
#define _MHCONSTROLLER_H_

#include "ApiHelper.h"
#include "domain/query/PageQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/LaborDispatch/LaborDispatchQuery.h"
#include "domain/vo/LaborDispatch/LaborDispatchVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

// 1 继承控制器
class LaborDispatchConstroller : public oatpp::web::server::api::ApiController
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(LaborDispatchConstroller);
public: 
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryLDCorlist) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("ldcompany.get.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(LaborDispatchPageJsonVO);
		//定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("PIMLABOURCAMPANYNAME").description = ZH_WORDS_GETTER("ldcompany.field.PIMLABOURCAMPANYNAME");
		info->queryParams["PIMLABOURCAMPANYNAME"].required = false;
		info->queryParams.add<String>("PIMLABOURCAMPANYID").description = ZH_WORDS_GETTER("ldcompany.field.PIMLABOURCAMPANYID");
		info->queryParams["PIMLABOURCAMPANYID"].required = false;

	}
	// 3.2 定义接口端点
	ENDPOINT(API_M_GET, "/ContracManagement/LaborDispatch/QueryPages-Information", queryLDCorlist, QUERIES(QueryParams, qcl)) {
		//解析查询参数
		API_HANDLER_QUERY_PARAM(query, PageQuery, qcl);
		//响应结果
		API_HANDLER_RESP_VO(executeQueryAll(query));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addLDCor) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("ldcompany.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/ContracManagement/LaborDispatch/Add-Information", addLDCor, BODY_DTO(LaborDispatchDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddLaborDispatch(dto));
	}

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeCor) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("ldcompany.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//根据公司名称进行删除
		info->queryParams.add<String>("PIMLABOURCAMPANYNAME").description = ZH_WORDS_GETTER("ldcompany.field.PIMLABOURCAMPANYNAME");
		info->queryParams["PIMLABOURCAMPANYNAME"].addExample("default", UInt64(1));
		info->queryParams["PIMLABOURCAMPANYNAME"].required = true;
		
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/ContracManagement/LaborDispatch/Remove-Information", removeCor, BODY_DTO(LaborDispatchDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveLaborDispatch(dto));
	}

	// 3.1 定义导出接口描述
	ENDPOINT_INFO(exportCor) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("ldcompany.export.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 定义导出接口处理
	ENDPOINT(API_M_PUT, "/ContracManagement/LaborDispatch/Export-Information",exportCor, BODY_DTO(LaborDispatchDTO::Wrapper, dto)) {
		//响应结果
		API_HANDLER_RESP_VO(execExportLaborDispatch(dto));
	} 
private: //  定义接口执行函数
	// 3.3 分页查询数据
	StringJsonVO::Wrapper executeQueryAll(const PageQuery::Wrapper& query);
	// 3.3 新增数据
	Uint64JsonVO::Wrapper execAddLaborDispatch(const LaborDispatchDTO::Wrapper& dto);
	//3.3 删除数据
	Uint64JsonVO::Wrapper execRemoveLaborDispatch(const LaborDispatchDTO::Wrapper& dto);
	//3.3 导出数据
	StringJsonVO::Wrapper execExportLaborDispatch(const LaborDispatchDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_MHCONSTROLLER_H_