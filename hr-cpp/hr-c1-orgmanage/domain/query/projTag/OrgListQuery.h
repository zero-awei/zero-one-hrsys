#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/24 18:22:04

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
#ifndef _ORGLISTQUERY_H_
#define _ORGLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OrgListQuery : public PageQuery
{
	DTO_INIT(OrgListQuery, PageQuery);
	// 查询排序
	DTO_FIELD(String, order);
	DTO_FIELD_INFO(order) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.order");
	}
	// 组织编号
	DTO_FIELD(String, orgCode);
	DTO_FIELD_INFO(orgCode) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgCode");
	}
	// 组织机构名称
	DTO_FIELD(String, orgName);
	DTO_FIELD_INFO(orgName) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgName");
	}
	// 简称
	DTO_FIELD(String, shortname);
	DTO_FIELD_INFO(shortname) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.shortname");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORGLISTQUERY_H_