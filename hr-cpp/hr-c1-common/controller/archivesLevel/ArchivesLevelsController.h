#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 狗皮电耗子
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
#ifndef _ARCHIVESLEVELS_CONTROLLER_
#define _ARCHIVESLEVELS_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/archivesLevels/ArchivesLevelsDTO.h"
#include "domain/vo/archivesList/ArchivesListVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ArchivesLevelsController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(ArchivesLevelsController);
public:
	ENDPOINT_INFO(queryArchivesLevels) {
		info->summary = ZH_WORDS_GETTER("common.controller.archivesLevel");
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesListVO);
		API_DEF_ADD_AUTH();
	}
	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/archives-level"), queryArchivesLevels, API_HANDLER_AUTH_PARAME) {
		// 响应结果
		API_HANDLER_RESP_VO(execQueryArchivesLevels());
	}
	
private:
	ArchivesListVO::Wrapper execQueryArchivesLevels();
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_ARCHIVESLEVELS_CONTROLLER_