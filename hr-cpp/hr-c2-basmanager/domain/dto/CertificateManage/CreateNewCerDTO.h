#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _CREATE_NEW_CER_DTO_
#define _CREATE_NEW_CER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class CreateNewCerDTO : public oatpp::DTO
{
public:
	//无参构造
	CreateNewCerDTO() {};
	//有参构造
	//CreateNewCerDTO(UInt64 id, String name, Int32 age, String sex) {};
	//CreateNewCerDTO(UInt64 id, String name) :id(id), name(name) {};
	DTO_INIT(CreateNewCerDTO, DTO);
	// 员工编号
	DTO_FIELD(UInt64, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("cermanage.field.ygbh");
	}
	// 证书编号(证书唯一标识)
	DTO_FIELD(String, pimvocationalid);
	DTO_FIELD_INFO(pimvocationalid) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimvocationalid");
	}
	// 一建配套B证编号
	DTO_FIELD(String, bcardNumber);
	DTO_FIELD_INFO(bcardNumber) {
		info->description = ZH_WORDS_GETTER("cermanage.field.bcardNumber");
	}
	// 证书名称
	DTO_FIELD(String, pimVocationalName);
	DTO_FIELD_INFO(pimVocationalName) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimVocationalName");
	}
	// 证书类型
	DTO_FIELD(String, zslx);
	DTO_FIELD_INFO(zslx) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zslx");
	}
	// 签发日期
	DTO_FIELD(String, zghqrq);
	DTO_FIELD_INFO(zghqrq) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zghqrq");
	}
	// 签发机构
	DTO_FIELD(String, zgsydw);
	DTO_FIELD_INFO(zgsydw) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zgsydw");
	}
	// 注册单位
	DTO_FIELD(String, zcdw);
	DTO_FIELD_INFO(zcdw) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zcdw");
	}
	// 发证有效期
	DTO_FIELD(String, fzyxq);
	DTO_FIELD_INFO(fzyxq) {
		info->description = ZH_WORDS_GETTER("cermanage.field.fzyxq");
	}
	// 失效日期
	DTO_FIELD(String, sxrq);
	DTO_FIELD_INFO(sxrq) {
		info->description = ZH_WORDS_GETTER("cermanage.field.sxrq");
	}
	// 年审情况
	DTO_FIELD(String, nsqk);
	DTO_FIELD_INFO(nsqk) {
		info->description = ZH_WORDS_GETTER("cermanage.field.nsqk");
	}
	// 使用情况
	DTO_FIELD(String, syqk);
	DTO_FIELD_INFO(syqk) {
		info->description = ZH_WORDS_GETTER("cermanage.field.syqk");
	}
	// 变更情况
	DTO_FIELD(String, alteration);
	DTO_FIELD_INFO(alteration) {
		info->description = ZH_WORDS_GETTER("cermanage.field.alteration");
	}
};

/**
 * 示例分页传输对象
 */
class CreateNewCerPageDTO : public PageDTO<CreateNewCerDTO::Wrapper>
{
	DTO_INIT(CreateNewCerPageDTO, PageDTO<CreateNewCerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 