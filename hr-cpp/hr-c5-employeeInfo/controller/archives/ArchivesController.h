#pragma once

#ifndef _ARCHIVES_CONTROLLER_H_
#define _ARCHIVES_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/vo/archives/ArchivesVO.h"

/*
	档案信息控制器
*/


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) // 0

class ArchivesController
	: public oatpp::web::server::api::ApiController // 1
{
	// 2.定义控制器访问入口
	API_ACCESS_DECLARE(ArchivesController);
public:	// 定义接口
	// 3.定义接口描述
	// 定义新建档案接口描述
	ENDPOINT_INFO(addArchivesInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("archives.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 4.定义接口处理
	ENDPOINT(API_M_POST, "/archives/addArchivesInfo", addArchivesInfo, BODY_DTO(ArchivesDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddArchivesInfo(dto));
	}

	// 定义删除档案接口描述
	ENDPOINT_INFO(removeArchivesInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("archives.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义删除档案接口处理
	ENDPOINT(API_M_DEL, "/archives/removeArchivesInfo", removeArchivesInfo, BODY_DTO(ArchivesDTO::Wrapper, dto)) {
		API_HANDLER_RESP_VO(execRemoveArchivesInfo(dto));
	}

	// 定义查询指定档案接口描述
	ENDPOINT_INFO(querySpecifiedArchivesInfo) {
		info->summary = ZH_WORDS_GETTER("specifiedArchives.get.summary");
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	ENDPOINT(API_M_GET, "/archives/querySpecifiedArchivesInfo", querySpecifiedArchivesInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(archiveQuery, ArchivesQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQuerySpecifiedArchivesInfo(archiveQuery, authObject->getPayload()));
	}

	ENDPOINT_INFO(queryArchivesinfo) {
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("archives.get.summary");
		//定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesPageJsonVO);
		//定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	//4 定义接口端点
	ENDPOINT(API_M_GET, "/employee-info/query-archives", queryArchivesinfo, QUERIES(QueryParams, qps)) {
		//解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, PageQuery, qps);
		//响应结果
		API_HANDLER_RESP_VO(execQueryArchivesinfo(query));
	}
private:
	// 查询指定档案
	ArchivesJsonVO::Wrapper execQuerySpecifiedArchivesInfo(const ArchivesQuery::Wrapper& dto, const PayloadDTO& payload);
	// 新增档案
	Uint64JsonVO::Wrapper execAddArchivesInfo(const ArchivesDTO::Wrapper& dto);
	// 删除档案
	Uint64JsonVO::Wrapper execRemoveArchivesInfo(const ArchivesDTO::Wrapper& dto);

	ArchivesPageJsonVO::Wrapper execQueryArchivesinfo(const PageQuery::Wrapper& query);
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) // 0
#endif 

