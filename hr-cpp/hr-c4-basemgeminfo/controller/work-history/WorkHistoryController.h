#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/15 11:14:40

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
#ifndef _WORKHISTORYCONTROLLER_H_
#define _WORKHISTORYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/query/work-history/WorkHistoryPageQuery.h"
#include "domain/vo/work-history/WorkHistoryFindVO.h"
#include "domain/dto/work-history/AddWorkHistoryDTO.h"
#include "domain/dto/work-history/DelWorkHistoryDTO.h"
#include "domain/vo/work-history/WorkHistoryExportVO.h"
#include "domain/query/work-history/WorkHistoryExportQuery.h"
#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Types.hpp"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

class WorkHistoryController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(WorkHistoryController);
public: // 定义接口
	//  定义查询接口描述
	ENDPOINT_INFO(queryWorkHistory) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("workhistory.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(WorkHistoryFindVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("workhistory.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("6611212223"));
		info->queryParams["pimpersonid"].required = false;
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/workhistory/select", queryWorkHistory, QUERIES(QueryParams, qps)) {
		//解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, WorkHistoryPageQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryWorkHistory(query));
	}

	// 定义新增接口描述
	ENDPOINT_INFO(addWorkHistory) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("workhistory.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义新增接口处理
	ENDPOINT(API_M_POST, "/workhistory/add", addWorkHistory, BODY_DTO(AddWorkHistoryDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddWorkHistory(dto));
	}

	// 定义批量删除接口描述
	ENDPOINT_INFO(delWorkHistory) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("workhistory.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义批量删除接口处理
	ENDPOINT(API_M_POST, "/workhistory/delete", delWorkHistory, BODY_DTO(DelWorkHistoryDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execDelWorkHistory(dto));
	}

	// 定义一个单文件导入接口
	ENDPOINT_INFO(postFile) {
		info->summary = ZH_WORDS_GETTER("workhistory.file.summary");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("workhistory.file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
	}
	// 定义文件上传端点处理
	ENDPOINT(API_M_POST, "/workhistory/file", postFile, BODY_STRING(String, body), QUERY(String, suffix)) {
		// 执行文件保存逻辑
		API_HANDLER_RESP_VO(execIntoWorkHistory(body, suffix));
	}

	//文件导出接口
	ENDPOINT_INFO(exportWorkHistory) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("workhistory.export.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("workhistory.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("6611212223"));
		info->queryParams["pimpersonid"].required = false;
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/workhistory/export", exportWorkHistory, QUERIES(QueryParams, qps)) {
		//解析导出参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, WorkHistoryExportQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execExportWorkHistory(query));
	}


private: 
	
	// 定义分页查询执行函数
	WorkHistoryFindVO::Wrapper execQueryWorkHistory(const WorkHistoryPageQuery::Wrapper& query);

	//定义增加执行函数
	Uint64JsonVO::Wrapper execAddWorkHistory(const AddWorkHistoryDTO::Wrapper& dto);

	//定义删除执行函数
	Uint64JsonVO::Wrapper execDelWorkHistory(const DelWorkHistoryDTO::Wrapper& dto);

	//定义导入执行函数
	StringJsonVO::Wrapper execIntoWorkHistory(const String body, const String suffix);

	//定义导出执行函数
	StringJsonVO::Wrapper execExportWorkHistory(const WorkHistoryExportQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_WORKHISTORYCONTROLLER_H_