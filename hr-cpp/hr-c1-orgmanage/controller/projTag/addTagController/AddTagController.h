#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/19 14:56:48

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
#ifndef _ADDTAGCONTROLLER_H_
#define _ADDTAGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/projTag/ProjTagDTO.h"
#include "domain/vo/projTag/ProjTagVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
/**
 * 新增项目标签Controller接口：
 * 接收内容为 ormxmbqname(项目标签)，ormorgid(组织id)，其他字段自动生成
 * 返回值：xh,数据库自增字段
 * 负责人：远翔
 */
class AddTagController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(AddTagController);
public: // 定义接口
	ENDPOINT_INFO(addTag) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("projTag.add.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);

		// 定义参数描述

	}
	ENDPOINT(API_M_POST, "/add-proj-tag", addTag, API_HANDLER_AUTH_PARAME, BODY_DTO(ProjTagDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddProjTag(dto, authObject->getPayload()));
	}

private: // 定义接口执行函数
	Uint64JsonVO::Wrapper execAddProjTag(const ProjTagDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execAddProjTag(const ProjTagDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController)

#endif // !_ADDTAGCONTROLLER_H_