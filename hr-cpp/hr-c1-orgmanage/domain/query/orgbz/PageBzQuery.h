#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/24 0:53:06

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
#ifndef _PAGEBZQUERY_H_
#define _PAGEBZQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PageQueryBzQuery : public PageQuery
{
	DTO_INIT(PageQueryBzQuery, PageQuery);

	DTO_FIELD_INFO(orgid) {
		info->description = ZH_WORDS_GETTER("orgbz.pagequery.orgid");
	}
	DTO_FIELD(String, orgid);
	//查询组织机构名称
	DTO_FIELD_INFO(orgname) {
		info->description = ZH_WORDS_GETTER("orgbz.pagequery.orgname");
	}
	DTO_FIELD(String, orgname);
	//查询部门名称
	DTO_FIELD_INFO(orgsectorname) {
		info->description = ZH_WORDS_GETTER("orgbz.pagequery.orgsectorname");
	}
	DTO_FIELD(String, orgsectorname);

	DTO_FIELD_INFO(size) {
		info->description = ZH_WORDS_GETTER("orgbz.pagequery.size");
	}
	DTO_FIELD(String, size);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("orgbz.pagequery.page");
	}
	DTO_FIELD(String, page);

	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("orgbz.pagequery.sort");
	}
	DTO_FIELD(String, sort);



};
#include OATPP_CODEGEN_END(DTO)
#endif // !_PAGEBZQUERY_H_