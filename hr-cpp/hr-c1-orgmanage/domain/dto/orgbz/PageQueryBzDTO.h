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
	DTO_FIELD(String, orgId);
	DTO_FIELD_INFO(orgId) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.orgid");
	}
	DTO_FIELD(String, orgName);
	DTO_FIELD_INFO(orgName) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.orgname");
	}
	//部门/项目名称
	DTO_FIELD(String, orgSectorName);
	DTO_FIELD_INFO(orgSectorName) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.orgsectorname");
	}
	DTO_FIELD(String, orgCode);
	DTO_FIELD_INFO(orgCode) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.orgcode");
	}
	DTO_FIELD(String, orgSectorId);
	DTO_FIELD_INFO(orgSectorId) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.orgsectorid");
	}
	DTO_FIELD(String, orgType);
	DTO_FIELD_INFO(orgType) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.orgtype");
	}
	DTO_FIELD(String, sectorType);
	DTO_FIELD_INFO(sectorType) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.sectortype");
	}
	DTO_FIELD(String, createBy);
	DTO_FIELD_INFO(createBy) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.createtime");
	}
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.createtime");
	}
	DTO_FIELD(String, updateBy);
	DTO_FIELD_INFO(updateBy) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.updateby");
	}
	DTO_FIELD(String, updateTime);
	DTO_FIELD_INFO(updateTime) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.updatetime");
	}
	DTO_FIELD(String, bzrs);
	DTO_FIELD_INFO(bzrs) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.bzrs");
	}
	DTO_FIELD(String, sjbzrs);
	DTO_FIELD_INFO(sjbzrs) {
		info->description = ZH_WORDS_GETTER("orgbz.dto.sectortype");
	}
public:
	QueryBzDTO()
	{
		orgId = "";
		orgName = "";
		orgSectorName = "";
		orgCode = "";
		orgType = "";
		sectorType = "";
		orgSectorId = "";
		bzrs = "";
		sjbzrs = "";
		updateTime = "";
		updateBy = "";
		createTime = "";
		createBy = "";
	}
};

class PageQueryBzDTO : public PageDTO<QueryBzDTO::Wrapper>
{
	DTO_INIT(PageQueryBzDTO, PageDTO<QueryBzDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PAGEQUERYBZDTO_H_