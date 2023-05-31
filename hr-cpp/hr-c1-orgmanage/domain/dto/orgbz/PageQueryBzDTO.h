#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/30 23:53:40

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
#ifndef _PAGEQUERYBZDTO_H_
#define _PAGEQUERYBZDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class QueryBzDTO : public oatpp::DTO
{
	DTO_INIT(QueryBzDTO, DTO);
	//组织机构
	DTO_FIELD(String, orgid);
	DTO_FIELD_INFO(orgid) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.orgid");
	}
	DTO_FIELD(String, orgname);
	DTO_FIELD_INFO(orgname) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.orgname");
	}
	//部门/项目名称
	DTO_FIELD(String, orgsectorname);
	DTO_FIELD_INFO(orgsectorname) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.orgsectorname");
	}
	DTO_FIELD(String, orgcode);
	DTO_FIELD_INFO(orgcode) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.orgcode");
	}
	DTO_FIELD(String, jhry);
	DTO_FIELD_INFO(jhry) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.jhry");
	}
	DTO_FIELD(String, sjry);
	DTO_FIELD_INFO(sjry) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.sjry");
	}
public:
	QueryBzDTO()
	{
		orgid = "";
		orgname = "";
		orgsectorname = "";
		orgcode = "";
		jhry = "";
		sjry = "";
	}
};

class PageQueryBzDTO : public PageDTO<QueryBzDTO::Wrapper>
{
	DTO_INIT(PageQueryBzDTO, PageDTO<QueryBzDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAGEQUERYBZDTO_H_