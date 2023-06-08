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


#include "domain/query/work-history/WorkHistoryQuery.h"
#include "domain/dto/work-history/ModWorkHistoryDTO.h"
#include "domain/vo/work-history/ModWorkHistoryVO.h"
#include "domain/vo/work-history/WorkHistoryVO.h"
#include "domain/dto/work-history/WorkHistoryIntoDTO.h"
#include "uselib/rocketmq/TestRocket.h"


using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)



class WorkHistoryController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(WorkHistoryController);
	//void init(){   }
public: // 定义接口
	//  定义查询接口描述
	ENDPOINT_INFO(queryPageWorkHistory) {
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
		info->queryParams["pimpersonid"].addExample("default", String("1002"));
		info->queryParams["pimpersonid"].required = false;
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/workhistory/select", queryPageWorkHistory, QUERIES(QueryParams, qps)) {
		//解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, WorkHistoryPageQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryPageWorkHistory(query));
	}

	// 定义新增接口描述
	ENDPOINT_INFO(addWorkHistory) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("workhistory.post.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义新增接口处理
	ENDPOINT(API_M_POST, "/workhistory/add", addWorkHistory, API_HANDLER_AUTH_PARAME, BODY_DTO(AddWorkHistoryDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddWorkHistory(dto, authObject->getPayload()));
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
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		info->summary = ZH_WORDS_GETTER("workhistory.file.summary");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		/*info->queryParams["suffix"].description = ZH_WORDS_GETTER("workhistory.file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
		info->queryParams["suffix"].required = false;*/
		// 定义其他表单参数描述
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("workhistory.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("1002"));
		//info->queryParams["pimpersonid"].required = true;
		
	}
	// 定义文件上传端点处理
	ENDPOINT(API_M_POST, "/workhistory/file", postFile, API_HANDLER_AUTH_PARAME, BODY_STRING(String, body), QUERY(String, pimpersonid)) {

		// 执行文件保存逻辑
		API_HANDLER_RESP_VO(execIntoWorkHistory(body,pimpersonid, authObject->getPayload()));
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
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("workhistory.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("1002"));
		info->queryParams["pimpersonid"].required = false;
	}
	// 定义导出接口处理
	ENDPOINT(API_M_GET, "/workhistory/export", exportWorkHistory, QUERIES(QueryParams, qps)) {
		//解析导出参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, WorkHistoryExportQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execExportWorkHistory(query));
	}








	/************************************************************************/
	/* 陈靓仔                                                                     */
	/************************************************************************/
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryWorkHistory) {
		// 定义接口标题,用到中英文字典函数，用过zh-dict.yaml确定参数
		info->summary = ZH_WORDS_GETTER("workhistory.select.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(WorkHistoryJsonVO);
		
		// 定义其他表单参数描述
		info->queryParams.add<String>("pimworkhistoryid").description = ZH_WORDS_GETTER("workhistory.field.pimworkhistoryid");
		info->queryParams["pimworkhistoryid"].addExample("default", String("01AE11A5-8997-46F1-A56D-3F17DFEF5149"));
		info->queryParams["pimworkhistoryid"].required = false;


	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/workhistory/specify-details", queryWorkHistory, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, WorkHistoryQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryWorkHistory(userQuery));
	}
	// 定义修改指定员工工作履历(单条修改)接口
	ENDPOINT_INFO(modifyWorkHistory) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("workhistory.put.summary");
		//定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	
	ENDPOINT(API_M_PUT, "/workhistory/update", modifyWorkHistory, API_HANDLER_AUTH_PARAME, BODY_DTO(ModWorkHistoryDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyWorkHistory(dto,authObject->getPayload()));
	}

private: 
	
	// 定义分页查询执行函数
	WorkHistoryFindVO::Wrapper execQueryPageWorkHistory(const WorkHistoryPageQuery::Wrapper& query);

	//定义增加执行函数
	Uint64JsonVO::Wrapper execAddWorkHistory(const AddWorkHistoryDTO::Wrapper& dto, const PayloadDTO& payload);

	//定义删除执行函数
	Uint64JsonVO::Wrapper execDelWorkHistory(const DelWorkHistoryDTO::Wrapper& dto);

	//定义导入执行函数
	StringJsonVO::Wrapper execIntoWorkHistory(const String&, const String&, const PayloadDTO& payload);

	//定义导出执行函数
	StringJsonVO::Wrapper execExportWorkHistory(const WorkHistoryExportQuery::Wrapper& query);






	/**
	 * 陈靓仔
	 */
	//定义查询详情函数
	WorkHistoryJsonVO::Wrapper execQueryWorkHistory(const WorkHistoryQuery::Wrapper& query);
	//定义修改执行函数
	StringJsonVO::Wrapper execModifyWorkHistory(const ModWorkHistoryDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_WORKHISTORYCONTROLLER_H_
