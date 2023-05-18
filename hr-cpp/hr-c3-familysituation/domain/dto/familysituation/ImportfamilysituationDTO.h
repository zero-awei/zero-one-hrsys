#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Marvin
 @Date: 2023/05/17 21:55:45

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
#ifndef _IMPORTFAMILYSITUATIONDTO_H_
#define _IMPORTFAMILYSITUATIONDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 员工家庭情况导入传输对象
 */
class ImportfamilysituationDTO : public oatpp::DTO
{
	DTO_INIT(ImportfamilysituationDTO, DTO);
	// 导入
	DTO_FIELD(String, url);
	DTO_FIELD_INFO(url) {
		info->description = "URL";
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORTFAMILYSITUATIONDTO_H_