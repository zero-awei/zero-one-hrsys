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
 * 接收内容为排序号sortid，组织名称orgname，项目标签projecttag，
 * 返回值：sortid
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
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);

		// 定义分页参数描述
		info->queryParams.add<String>("sortid").description = ZH_WORDS_GETTER("projTag.field.sortid");
		info->queryParams["sortid"].addExample("default", String("1"));
		info->queryParams["sortid"].required = true;
		info->queryParams.add<String>("orgname").description = ZH_WORDS_GETTER("projTag.field.orgname");
		info->queryParams["orgname"].addExample("default", String("xxxx"));
		info->queryParams["orgname"].required = true;
		info->queryParams.add<String>("projecttag").description = ZH_WORDS_GETTER("projTag.field.projecttag");
		info->queryParams["projecttag"].addExample("default", String("123"));
		info->queryParams["projecttag"].required = true;
	}
	ENDPOINT(API_M_POST, "/add-proj-tag", addTag, BODY_DTO(ProjTagDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddProjTag(dto));
	}
private: // 定义接口执行函数
	Uint64JsonVO::Wrapper execAddProjTag(const ProjTagDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController)

#endif // !_ADDTAGCONTROLLER_H_