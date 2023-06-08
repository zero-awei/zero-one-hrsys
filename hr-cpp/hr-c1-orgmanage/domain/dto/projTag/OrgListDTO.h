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
	// 区域补贴
	DTO_FIELD(String, regionSubsidy);
	DTO_FIELD_INFO(regionSubsidy) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.regionSubsidy");
	}
	// 公司根组织ID
	DTO_FIELD(String, flag);
	DTO_FIELD_INFO(flag) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.flag");
	}
	// 建立时间
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.createTime");
	}
	// 建立人
	DTO_FIELD(String, createby);
	DTO_FIELD_INFO(createby) {
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
	// ERP组织ID
	DTO_FIELD(String, erpOrgId);
	DTO_FIELD_INFO(erpOrgId) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.erpOrgId");
	}
	// 所属区域
	DTO_FIELD(String, belongRegion);
	DTO_FIELD_INFO(belongRegion) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.belongRegion");
	}
	// 组织性质
	DTO_FIELD(String, legalEntity);
	DTO_FIELD_INFO(legalEntity) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.legalEntity");
	}
	// 级别编码
	DTO_FIELD(String, levelCode);
	DTO_FIELD_INFO(levelCode) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.levelCode");
	}
	// 组织编号
	DTO_FIELD(String, orgCode);
	DTO_FIELD_INFO(orgCode) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgCode");
	}
	// 组织机构标识
	DTO_FIELD(String, orgId);
	DTO_FIELD_INFO(orgId) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgId");
	}
	// 组织机构名称
	DTO_FIELD(String, orgName);
	DTO_FIELD_INFO(orgName) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgName");
	}
	// 上级组织机构
	DTO_FIELD(String, porgId);
	DTO_FIELD_INFO(porgId) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.porgId");
	}
	// 上级组织机构名称
	DTO_FIELD(String, porgName);
	DTO_FIELD_INFO(porgName) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.porgName");
	}
	// 简称
	DTO_FIELD(String, shortname);
	DTO_FIELD_INFO(shortname) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.shortname");
	}
	// 所属OU
	DTO_FIELD(String, belongou);
	DTO_FIELD_INFO(belongou) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.belongou");
	}
	// 启停标识
	DTO_FIELD(String, sign);
	DTO_FIELD_INFO(sign) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.sign");
	}
	// 组织地址编码
	DTO_FIELD(String, orgAddrCode);
	DTO_FIELD_INFO(orgAddrCode) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgAddrCode");
	}
	// 组织地址1
	DTO_FIELD(String, orgAddrOne);
	DTO_FIELD_INFO(orgAddrOne) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgAddr1");
	}
	// 组织地址2
	DTO_FIELD(String, orgAddrTwo);
	DTO_FIELD_INFO(orgAddrTwo) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgAddr2");
	}
	// 组织创建时间
	DTO_FIELD(String, orgCreateTime);
	DTO_FIELD_INFO(orgCreateTime) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgCreateTime");
	}
	// 组织显示名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.name");
	}
	// 组织类型
	DTO_FIELD(String, orgType);
	DTO_FIELD_INFO(orgType) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgType");
	}
	// 对应OU
	DTO_FIELD(String, correspondou);
	DTO_FIELD_INFO(correspondou) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.correspondou");
	}

public:
	OrgListDTO()
	{
		regionSubsidy = "";
		flag = "";
		correspondou = "";
		createby = "admin";
		updater = "admin";
		createTime = "2000-01-01 00:00:00";
		updateTime = "2000-01-01 00:00:00";
		erpOrgId = "";
		belongRegion = "";
		legalEntity = "";
		levelCode = "";
		orgCode = "";
		orgId = "";
		orgName = "";
		porgId = "";
		shortname = "";
		belongou = "";
		sign = "";
		orgAddrCode = "";
		orgAddrOne = "";
		orgAddrTwo = "";
		orgCreateTime = "";
		name = "";
		orgType = "";
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