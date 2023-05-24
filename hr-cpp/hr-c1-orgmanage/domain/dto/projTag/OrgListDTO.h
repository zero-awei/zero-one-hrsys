#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/24 19:36:34

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
#ifndef _ORGLISTDTO_H_
#define _ORGLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 组织列表DTO领域模型
 * 负责人：Andrew
 */
class OrgListDTO : public oatpp::DTO
{
	DTO_INIT(OrgListDTO, DTO);
	// 组织ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.id");
	}
	// 组织名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.name");
	}
	// 建立时间
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.createTime");
	}
	// 建立人
	DTO_FIELD(String, creator);
	DTO_FIELD_INFO(creator) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.creator");
	}
	// 更新时间
	DTO_FIELD(String, updateTime);
	DTO_FIELD_INFO(updateTime) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.updateTime");
	}
	// 更新人
	DTO_FIELD(String, updater);
	DTO_FIELD_INFO(updater) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.updater");
	}
	// 组织编码
	DTO_FIELD(String, orgCode);
	DTO_FIELD_INFO(orgCode) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgCode");
	}
	// 组织简称
	DTO_FIELD(String, shortName);
	DTO_FIELD_INFO(shortName) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.shortName");
	}
	// 组织排序编号
	DTO_FIELD(String, orderId);
	DTO_FIELD_INFO(orderId) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.sortId");
	}
	// 组织类型
	DTO_FIELD(String, orgType);
	DTO_FIELD_INFO(orgType) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgType");
	}
	// 组织类型释义
	DTO_FIELD(String, typeName);
	DTO_FIELD_INFO(typeName) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.typeName");
	}
	// 组织所属OU的组织ID
	DTO_FIELD(String, ouid);
	DTO_FIELD_INFO(ouid) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.ouid");
	}
	// 所属区域
	DTO_FIELD(String, region);
	DTO_FIELD_INFO(region) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.region");
	}
	// 补贴标准
	DTO_FIELD(String, standard);
	DTO_FIELD_INFO(standard) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.standard");
	}
	// 上级组织ID
	DTO_FIELD(String, upOrgId);
	DTO_FIELD_INFO(upOrgId) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.upOrgId");
	}
	// 岗位
	DTO_FIELD(String, job);
	DTO_FIELD_INFO(job) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.job");
	}
	// 上级部门ID
	DTO_FIELD(String, upDepartId);
	DTO_FIELD_INFO(upDepartId) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.upDepartId");
	}

public:
	OrgListDTO()
	{
		id = "123";
		name = "test";
		creator = "admin";
		updater = "admin";
		createTime = "2000-01-01 00:00:00";
		updateTime = "2000-01-01 00:00:00";
		orgCode = "org123";
		orderId = "10";
		orgType = "";
		typeName = "";
		ouid = "";
		region = "";
		standard = "";
		upOrgId = "";
		upDepartId = "";
		job = "";
	}
};

/**
 * 分页组织列表DTO
 * 负责人：Andrew
 */
class OrgListPageDTO : public PageDTO<OrgListDTO::Wrapper>
{
	DTO_INIT(OrgListPageDTO, PageDTO<OrgListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORGLISTDTO_H_