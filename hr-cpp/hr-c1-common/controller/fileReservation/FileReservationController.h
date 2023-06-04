#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/17 20:24:15

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
#ifndef _FILERESERVATIONCONTROLLER_H_
#define _FILERESERVATIONCONTROLLER_H_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/pullList/PullListDTO.h"
#include "domain/vo/pullList/PullListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 档案保管地下拉列表控制器
 * 负责人：远翔
 */

class FileReservationController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(FileReservationController);
public: // 定义接口
	ENDPOINT_INFO(queryFileReservation) {
		info->summary = ZH_WORDS_GETTER("common.controller.fileReservation");
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListVO);
		API_DEF_ADD_AUTH();
	}

	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/file-reservation"), queryFileReservation, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryFileReservation());
	}
private: // 定义接口执行函数
	PullListVO::Wrapper execQueryFileReservation();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILERESERVATIONCONTROLLER_H_