#pragma once
#ifndef _TITLECONTROLLLER_
#define _TITLECONTROLLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Title/TitleQuery.h"
#include "domain/dto/Title/TitleDTO.h"
#include "domain/vo/Title/TitleVO.h"
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
class TitleController : public oatpp::web::server::api::ApiController // 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(TitleController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryTitle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("Title.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(TitlePageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("Title.field.name");
		info->queryParams["name"].addExample("default", String(ZH_WORDS_GETTER("Title.field.name")));
		info->queryParams["name"].required = false;
	}
	ENDPOINT(API_M_GET, "/Title/query-Title", queryTitle, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(TitleQuery, TitleQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryTitle(TitleQuery, authObject->getPayload()));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addTitle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("Title.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/Title/add-Title", addTitle, BODY_DTO(TitleDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddTitle(dto));
	}

	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifyTitle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("Title.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/Title/modify-Title", modifyTitle, BODY_DTO(TitleDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyTitle(dto));
	}

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeTitle) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("Title.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/Title/delete-Title", removeTitle, BODY_DTO(TitleDTO_delete::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveTitle(dto));
	}
private:
	// 3.3 演示分页查询数据
	TitlePageJsonVO::Wrapper execQueryTitle(const TitleQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddTitle(const TitleDTO::Wrapper& dto);
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyTitle(const TitleDTO::Wrapper& dto);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveTitle(const TitleDTO_delete::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 