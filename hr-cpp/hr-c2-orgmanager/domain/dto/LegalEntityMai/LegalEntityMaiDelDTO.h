#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/29 23:23:25

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
#ifndef _LEGALENTITYMAIDELETEDTO_H_
#define _LEGALENTITYMAIDELETEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* 构建法人主体维护批量删除DTO--（组织管理-数据设置-法人主体维护）--TripleGold */
class LegalEntityMaiDelDTO : public oatpp::DTO
{
	DTO_INIT(LegalEntityMaiDelDTO, DTO);
	// 删除数据ID数组
	DTO_FIELD(List<String>, Ids) = {};
	DTO_FIELD_INFO(Ids) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.delete.cnt");
	}

	//// 法人主体标识
	//DTO_FIELD(String, ORMSIGNORGID);
	//DTO_FIELD_INFO(ORMSIGNORGID) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
	//}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAIDELETEDTO_H_