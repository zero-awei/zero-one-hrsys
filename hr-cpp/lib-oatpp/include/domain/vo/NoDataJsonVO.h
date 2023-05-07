#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/28 21:05:58

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
#ifndef _NO_DATA_JSON_VO_H_
#define _NO_DATA_JSON_VO_H_
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "ResultStatus.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 无数据JsonVO
 */
class NoDataJsonVO : public oatpp::DTO
{
	// 初始化定义
	DTO_INIT(NoDataJsonVO, DTO);

	// 状态码
	DTO_FIELD_INFO(code) {
#ifndef LINUX
		info->description = u8"状态码";
#else
		info->description = "status code";
#endif
		info->required = true;
	}
	DTO_FIELD(Int32, code, "code") = 10000;
	// 提示消息
	DTO_FIELD_INFO(message) {
#ifndef LINUX
		info->description = u8"提示信息";
#else
		info->description = "info message";
#endif
		info->required = true;
	}
	DTO_FIELD(String, message, "message") = "success";
public:
	// 初始化
	void init(ResultStatus resultStatus) {
		this->code = resultStatus.getCode();
		this->message = resultStatus.getMessage();
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_NO_DATA_JSON_VO_H_
