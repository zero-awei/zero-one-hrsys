#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/20 15:29:33

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
#ifndef _UPDATEPROJTAGCONTROLLER_H_
#define _UPDATEPROJTAGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ModifyProjTagController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ModifyProjTagController);
public: // 定义接口
	ENDPOINT_INFO(modifyProjTag) {

	}

	ENDPOINT(API_M_PUT, PATH_TO_PROJTAG("update-project-tag"), modifuProjTag, BODY_DTO()) {

	}
private: // 定义接口执行函数
	
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_UPDATEPROJTAGCONTROLLER_H_