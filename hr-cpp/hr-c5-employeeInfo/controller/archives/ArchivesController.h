#pragma once

#ifndef _ARCHIVES_CONTROLLER_H_
#define _ARCHIVES_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/vo/archives/ArchivesVO.h"
#include "service/archives/ArchivesService.h"
//#include "domain/dto/archives/ArchivesDelDto.h"

/*
	档案信息控制器
*/

// 简化表单参数描述
/*
parameter: parm->查询参数 defaultVal->默认值
类型都是string
*/

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

class ArchivesController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ArchivesController);
public:
	// 查询指定档案接口描述+处理
	ENDPOINT_INFO(queryArchivesInfo) {
		info->summary = ZH_WORDS_GETTER("specifiedArchives.get.summary");
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 表单描述
		info->queryParams.add<String>("pimArchivesId").description = ZH_WORDS_GETTER("archives.newField.pimArchivesId");
		info->queryParams["pimArchivesId"].addExample("default", String("12"));
		info->queryParams["pimArchivesId"].required = true;
	}
	ENDPOINT(API_M_GET, "/archives/query-archivesinfo", queryArchivesInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(query, ArchivesQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryArchivesInfo(query, authObject->getPayload()));
	}

	// 分页查询接口描述+处理
	ENDPOINT_INFO(queryPageArchivesinfo) {
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("archives.get.summary");
		//定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesPageJsonVO);
		//定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 表单描述
		info->queryParams.add<String>("pimPersonName").description = ZH_WORDS_GETTER("archives.newField.pimPersonName");
		info->queryParams["pimPersonName"].addExample("default", String("LiHua"));
		info->queryParams["pimPersonName"].required = false;
		info->queryParams.add<String>("ygbh").description = ZH_WORDS_GETTER("archives.newField.ygbh");
		info->queryParams["ygbh"].addExample("default", String("1234"));
		info->queryParams["ygbh"].required = false;
		info->queryParams.add<String>("dabh").description = ZH_WORDS_GETTER("archives.newField.dabh");
		info->queryParams["dabh"].addExample("default", String("1234"));
		info->queryParams["dabh"].required = false;
		info->queryParams.add<String>("ygzt").description = ZH_WORDS_GETTER("archives.newField.ygzt");
		info->queryParams["ygzt"].addExample("default", String(ZH_WORDS_GETTER("archives.sample.ygzt")));
		info->queryParams["ygzt"].required = false;
		info->queryParams.add<String>("dazt").description = ZH_WORDS_GETTER("archives.newField.dazt");
		info->queryParams["dazt"].addExample("default", String(ZH_WORDS_GETTER("archives.sample.dazt")));
		info->queryParams["dazt"].required = false;
	}
	ENDPOINT(API_M_GET, "/archives/query-archivesinfo-page", queryPageArchivesinfo, QUERIES(QueryParams, qps)) {
		//解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, ArchivesQuery, qps);
		//响应结果
		API_HANDLER_RESP_VO(execQueryPageArchivesInfo(query));
	}

	// 新建档案接口描述+处理
	ENDPOINT_INFO(addArchivesInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("archives.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/archives/add-archivesinfo", addArchivesInfo, BODY_DTO(ArchivesDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddArchivesInfo(dto));
	}

	// 删除档案接口描述+处理
	ENDPOINT_INFO(removeArchivesInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("archives.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_DEL, "/archives/remove-archivesinfo", removeArchivesInfo, BODY_DTO(ArchivesDelDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveArchivesInfo(dto));
	}

private:
	// 查询指定档案的详细数据
	ArchivesPageJsonVO::Wrapper execQueryArchivesInfo(const ArchivesQuery::Wrapper& query, const PayloadDTO& payload);
	// 分页查询指定档案
	ArchivesPageJsonVO::Wrapper execQueryPageArchivesInfo(const ArchivesQuery::Wrapper& query);
	// 新增档案
	Uint64JsonVO::Wrapper execAddArchivesInfo(const ArchivesDTO::Wrapper& dto);
	// 删除档案
	Uint64JsonVO::Wrapper execRemoveArchivesInfo(const ArchivesDelDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) // 0
#endif 

