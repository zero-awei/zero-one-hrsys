#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _CERTIFIDELETE_CONTROLLER_
#define _CERTIFIDELETE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/dto/CertificateManage/RemoveCertifDTO.h"

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
class CertifDeleteController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CertifDeleteController);
	// 3 定义接口
public:

	// 定义删除接口描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("certif.delete.summary"), removeCertif, Uint64JsonVO);
	// 定义删除接口处理
	ENDPOINT(API_M_DEL, "/remove-certif", removeCertif, BODY_DTO(RemoveCertifDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveCertif(dto));
	}
private:
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveCertif(const RemoveCertifDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CERTIFIDELETE_CONTROLLER_