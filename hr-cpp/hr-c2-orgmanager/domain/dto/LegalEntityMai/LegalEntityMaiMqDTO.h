#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/29 22:23:33

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
#ifndef _LEGALENTITYMAIMQDTO_H_
#define _LEGALENTITYMAIMQDTO_H_

#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* RocketMq数据传输对象定义--（组织管理-数据设置-法人主体维护）--TripleGold */
class LegalEntityMaiMqDTO : public oatpp::DTO
{
public:
	LegalEntityMaiMqDTO() {};
	LegalEntityMaiMqDTO(String body, String creatName) : body(body), creatName(creatName) {};
	DTO_INIT(LegalEntityMaiMqDTO, DTO);
	// 文件名称
	DTO_FIELD(String, body);
	DTO_FIELD_INFO(body) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.body");
	}
	// 创建名称
	DTO_FIELD(String, creatName);
	DTO_FIELD_INFO(creatName) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.creatName");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAIMQDTO_H_