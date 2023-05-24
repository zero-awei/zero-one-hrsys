#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 10:17:22

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
#ifndef _PROFCERTS_DTO_
#define _PROFCERTS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 执(职)业资格证书下拉列表查询DTO
 */
class ProfCertsDTO : public oatpp::DTO
{
	DTO_INIT(ProfCertsDTO, DTO);
	// 执业资格专业编码
	DTO_FIELD(String, pimQualMajorId);
	DTO_FIELD_INFO(pimQualMajorId) {
		info->description = ZH_WORDS_GETTER("common.dto.pimQualMajorId");
	}
	// 执业资格
	DTO_FIELD(String, pimQualMajorName);
	DTO_FIELD_INFO(pimQualMajorName) {
		info->description = ZH_WORDS_GETTER("common.dto.pimQualMajorName");
	}
	// 建立人
	DTO_FIELD(String, createMan);
	DTO_FIELD_INFO(createMan) {
		info->description = ZH_WORDS_GETTER("common.dto.createMan");
	}
	// 建立时间
	DTO_FIELD(String, createDate);
	DTO_FIELD_INFO(createDate) {
		info->description = ZH_WORDS_GETTER("common.dto.createDate");
	}
	// ENABLE
	DTO_FIELD(UInt64, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("common.dto.enable");
	}
	// 更新人
	DTO_FIELD(String, upDateMan);
	DTO_FIELD_INFO(upDateMan) {
		info->description = ZH_WORDS_GETTER("common.dto.upDateMan");
	}
	// 更新时间
	DTO_FIELD(String, upDateDate);
	DTO_FIELD_INFO(upDateDate) {
		info->description = ZH_WORDS_GETTER("common.dto.upDateDate");
	}
	// 执业资格类别标识
	DTO_FIELD(String, pimQualTypeId);
	DTO_FIELD_INFO(pimQualTypeId) {
		info->description = ZH_WORDS_GETTER("common.dto.pimQualTypeId");
	}
	// 组织标识
	DTO_FIELD(String, ormOrgId);
	DTO_FIELD_INFO(ormOrgId) {
		info->description = ZH_WORDS_GETTER("common.dto.ormOrgId");
	}
	// 执业资格类别
	DTO_FIELD(String, professionalType);
	DTO_FIELD_INFO(professionalType) {
		info->description = ZH_WORDS_GETTER("common.dto.professionalType");
	}
	// 专业技术职务
	DTO_FIELD(String, zyjszw);
	DTO_FIELD_INFO(zyjszw) {
		info->description = ZH_WORDS_GETTER("common.dto.zyjszw");
	}
	// 级别
	DTO_FIELD(String, quaLevel);
	DTO_FIELD_INFO(quaLevel) {
		info->description = ZH_WORDS_GETTER("common.dto.quaLevel");
	}
	// 专业
	DTO_FIELD(String, quaMajor);
	DTO_FIELD_INFO(quaMajor) {
		info->description = ZH_WORDS_GETTER("common.dto.quaMajor");
	}
	// 岗位类型
	DTO_FIELD(String, gwlx);
	DTO_FIELD_INFO(gwlx) {
		info->description = ZH_WORDS_GETTER("common.dto.gwlx");
	}
	// 岗位类型
	DTO_FIELD(String, gwType);
	DTO_FIELD_INFO(gwType) {
		info->description = ZH_WORDS_GETTER("common.dto.gwType");
	}
	// 岗位类型
	DTO_FIELD(String, gwzs);
	DTO_FIELD_INFO(gwzs) {
		info->description = ZH_WORDS_GETTER("common.dto.gwzs");
	}
	// 岗位（技能）证书
	DTO_FIELD(String, pimQualTypeName);
	DTO_FIELD_INFO(pimQualTypeName) {
		info->description = ZH_WORDS_GETTER("common.dto.pimQualTypeName");
	}

};

/**
 * 执(职)业资格证书下拉列表分页查询DTO
 */
class ProfCertsListDTO : public PageDTO<ProfCertsDTO::Wrapper>
{
	DTO_INIT(ProfCertsListDTO, PageDTO<ProfCertsDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_PROFCERTS_DTO_