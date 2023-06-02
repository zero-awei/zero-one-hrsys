#pragma once
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/15 21:38:55

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0=

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _LABORDISPATCHQUERY_H_
#define _LABORDISPATCHQUERY_H_

#include OATPP_CODEGEN_BEGIN(DTO)

class LaborDispatchQuery : public PageQuery
{
	DTO_INIT(LaborDispatchQuery, PageQuery);

	//公司名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.PIMLABOURCAMPANYNAME");
	}
	//所属单位
	DTO_FIELD(String, unit);
	DTO_FIELD_INFO(unit) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.ORGNAME");
	}
	//联系地址
	DTO_FIELD(String, lxdz);
	DTO_FIELD_INFO(lxdz) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LXDZ");
	}
	//联系方式
	DTO_FIELD(String, lxfs);
	DTO_FIELD_INFO(lxfs) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LXFS");
	}
	//联系人
	DTO_FIELD(String, lxr);
	DTO_FIELD_INFO(lxr) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LXR");
	}
	//注册本金
	DTO_FIELD(String, regcapital);
	DTO_FIELD_INFO(regcapital) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.REGCAPITAL");
	}
	//法人
	DTO_FIELD(String, legalperson);
	DTO_FIELD_INFO(legalperson) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.LEGALPERSON");
	}
	//更新时间
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("ldconpany.field.UPDATEDATE");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LABORDISPATCHQUERY_H_