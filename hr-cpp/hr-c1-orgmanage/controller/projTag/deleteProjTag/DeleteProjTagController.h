#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/05/24 17:58:45

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
#ifndef _DELETEPROJTAGCONTROLLER_H_
#define _DELETEPROJTAGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/dto/projTag/DeleteProjTagDTO.h"
#include "domain/vo/projTag/DeleteProjTagBatchVO.h"
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
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_DEL, PATH_TO_PROJTAG("/delete-one-tag-by-tag-id"), deleteByTagId, API_HANDLER_AUTH_PARAME, BODY_DTO(DeleteProjTagDTO::Wrapper, dto)) {
		// 解析查询参数
		/*auto deleteProjTagDTO = DeleteProjTagDTO::createShared();
		deleteProjTagDTO->tagId = tagId;*/
		// 响应结果
		//API_HANDLER_RESP_VO(execDeleteByTagId(deleteProjTagDTO, authObject->getPayload()));
		API_HANDLER_RESP_VO(execDeleteByTagId(dto, authObject->getPayload()));
	}

	// 删除多条数据
	ENDPOINT_INFO(deleteBatchByTagId) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("projTag.deleteProjTags");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DeleteProjTagBatchVO);
	}
	ENDPOINT(API_M_DEL, PATH_TO_PROJTAG("/delete-batch-tag-by-tag-id"), deleteBatchByTagId, API_HANDLER_AUTH_PARAME, BODY_DTO(DeleteProjTagBatchDTO::Wrapper, dto)) {
		//const std::shared_ptr<ObjectMapper>& objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
		// 解析查询参数
		/*auto deleteProjTagBatchDTO = DeleteProjTagBatchDTO::createShared();
		deleteProjTagBatchDTO->tagIds = objectMapper->readFromString<oatpp::List<String>>(jsonPayload);*/
		//测试
		/*for (const auto& item : *deleteProjTagBatchDTO->tagIds) {
			cout << item->c_str() << endl;
		}*/
		// 响应结果
		//API_HANDLER_RESP_VO(execDeleteBatchByTagId(deleteProjTagBatchDTO, authObject->getPayload()));
		API_HANDLER_RESP_VO(execDeleteBatchByTagId(dto, authObject->getPayload()));
	}
private:
	// 查询指定岗位详情
	StringJsonVO::Wrapper execDeleteByTagId(const DeleteProjTagDTO::Wrapper& query, const PayloadDTO& payload);
	DeleteProjTagBatchVO::Wrapper execDeleteBatchByTagId(const DeleteProjTagBatchDTO::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DELETEPROJTAGCONTROLLER_H_