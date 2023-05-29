#pragma once
 /*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/29 21:39:17

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
#ifndef _ADDPROJTAGDTO_H_
#define _ADDPROJTAGDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddProjTagDTO : public oatpp::DTO
{
	DTO_INIT(AddProjTagDTO, DTO);
	
	// 项目标签
	DTO_FIELD(String, ormxmbqname);
	DTO_FIELD_INFO(ormxmbqname) {
		info->description = ZH_WORDS_GETTER("projTag.filed.ormxmbqname");
	}
	// 组织id
	DTO_FIELD(String, ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("projTag.filed.ormorgid");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDPROJTAGDTO_H_