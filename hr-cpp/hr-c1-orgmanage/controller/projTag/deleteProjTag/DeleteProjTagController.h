#pragma once
#ifndef _DELETEPROJTAGCONTROLLER_H_
#define _DELETEPROJTAGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/dto/projTag/DeleteProjTagDTO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class DeleteProjTagController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DeleteProjTagController);
	// 3 定义接口
public:
	// 删除单条数据
	ENDPOINT_INFO(deleteByTagId) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("projTag.deleteProjTag");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);

	}
	ENDPOINT(API_M_DEL, "/delete-one-by-tagId/{tagId}", deleteByTagId, API_HANDLER_AUTH_PARAME, PATH(String, tagId)) {
		// 解析查询参数
		auto deleteProjTagDTO = DeleteProjTagDTO::createShared();
		deleteProjTagDTO->tagId = tagId;
		// 响应结果
		API_HANDLER_RESP_VO(execDeleteByTagId(deleteProjTagDTO, authObject->getPayload()));
	}

	// 删除多条数据
	ENDPOINT_INFO(deleteBatchByTagId) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("projTag.deleteProjTags");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_DEL, "/deleteBatch-one-by-tagId", deleteBatchByTagId, API_HANDLER_AUTH_PARAME, BODY_STRING(String, jsonPayload)) {
		const std::shared_ptr<ObjectMapper>& objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
		// 解析查询参数
		auto deleteProjTagBatchDTO = DeleteProjTagBatchDTO::createShared();
		deleteProjTagBatchDTO->tagIds = objectMapper->readFromString<oatpp::List<String>>(jsonPayload);
		// 响应结果
		API_HANDLER_RESP_VO(execDeleteBatchByTagId(deleteProjTagBatchDTO, authObject->getPayload()));
	}
private:
	// 查询指定岗位详情
	Uint64JsonVO::Wrapper execDeleteByTagId(const DeleteProjTagDTO::Wrapper& query, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execDeleteBatchByTagId(const DeleteProjTagBatchDTO::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DELETEPROJTAGCONTROLLER_H_