#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 8:27:04

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
#ifndef _CERTTYPELIST_CONTROLLER_
#define _CERTTYPELIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/pullList/PullListDTO.h"
#include "domain/vo/pullList/PullListVO.h"
#include "domain/dto/certs/CertTypeDTO.h"
#include "domain/vo/certs/CertTypeVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 证书类型下拉列表控制器
 * 返回值 : PullListVO
 * 负责人 : rice
 */
class CertTypeListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CertTypeListController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryCertTypeList) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("common.controller.certTypeList");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CertTypeListJsonVO);
		API_DEF_ADD_AUTH();
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/cert-type"), queryCertTypeList, API_HANDLER_AUTH_PARAME) {
		// 响应结果
		API_HANDLER_RESP_VO(execQueryCertTypeList());
	}
private:
	CertTypeListJsonVO::Wrapper execQueryCertTypeList();
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CERTTYPELIST_CONTROLLER_