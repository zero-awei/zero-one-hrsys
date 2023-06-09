#pragma once
#ifndef _ARCHIVECONTROLLLER_
#define _ARCHIVECONTROLLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/archive/ArchiveQuery.h"
#include "domain/dto/archive/ArchiveDTO.h"
#include "domain/vo/archive/ArchiveVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class ArchiveController : public oatpp::web::server::api::ApiController // 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ArchiveController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryArchive) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("archive.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivePageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	ENDPOINT(API_M_GET, "/archive/query-archive", queryArchive, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(archiveQuery, ArchiveQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryArchive(archiveQuery, authObject->getPayload()));
	}
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addArchive) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("archive.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/archive/add-archive", addArchive, BODY_DTO(ArchiveDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddArchive(dto));
	}
	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyArchive) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("archive.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/archive/modify-archive", modifyArchive, BODY_DTO(ArchiveDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyArchive(dto));
	}
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeArchive) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("archive.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/archive/remote-archive", removeArchive, BODY_DTO(ArchiveDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveArchive(dto));
	}
private:
	// 3.3 演示分页查询数据
	ArchivePageJsonVO::Wrapper execQueryArchive(const ArchiveQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddArchive(const ArchiveDTO::Wrapper& dto);
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyArchive(const ArchiveDTO::Wrapper& dto);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveArchive(const ArchiveDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 