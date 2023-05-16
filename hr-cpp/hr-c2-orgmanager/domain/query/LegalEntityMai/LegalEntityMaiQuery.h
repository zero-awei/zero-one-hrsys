#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/16 12:18:47

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
#ifndef _LEGALENTITYMAI_H_
#define _LEGALENTITYMAI_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* 定义法人主体分页查询对象*/
class LegalEntityMaiQuery : public PageQuery
{
	DTO_INIT(LegalEntityMaiQuery, PageQuery);
	// 法人主体标识
	DTO_FIELD(String, ORMSIGNORGID);
	DTO_FIELD_INFO(ORMSIGNORGID) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
	}
	// 更新人
	DTO_FIELD(String, UPDATEMAN);
	DTO_FIELD_INFO(UPDATEMAN) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.updateman");
	}
	//// 建立人
	//DTO_FIELD(String, CREATEMAN);
	//DTO_FIELD_INFO(CREATEMAN) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.createman");
	//}
	//// 建立时间
	//DTO_FIELD(String, CREATEDATE);
	//DTO_FIELD_INFO(CREATEDATE) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.createdate");
	//}
	//// 法人主体名称
	//DTO_FIELD(String, ORMSIGNORGNAME);
	//DTO_FIELD_INFO(ORMSIGNORGNAME) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
	//}
	//// 更新时间
	//DTO_FIELD(String, UPDATEDATE);
	//DTO_FIELD_INFO(UPDATEDATE) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.updatedate");
	//}
	//// 组织编号
	//DTO_FIELD(String, ORGCODE);
	//DTO_FIELD_INFO(ORGCODE) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
	//}
	//// 简称
	//DTO_FIELD(String, ZZJC);
	//DTO_FIELD_INFO(ZZJC) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.short");
	//}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAI_H_