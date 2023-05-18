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
#include "../pullList/PullListDTO.h"
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
		info->description = ZH_WORDS_GETTER("执业资格专业编码");
	}
	// 执业资格
	DTO_FIELD(String, pimQualMajorName);
	DTO_FIELD_INFO(pimQualMajorName) {
		info->description = ZH_WORDS_GETTER("执业资格");
	}
	// 建立人
	DTO_FIELD(String, createMan);
	DTO_FIELD_INFO(createMan) {
		info->description = ZH_WORDS_GETTER("建立人");
	}
	// 建立时间
	DTO_FIELD(String, createDate);
	DTO_FIELD_INFO(createDate) {
		info->description = ZH_WORDS_GETTER("建立时间");
	}
	// ENABLE
	DTO_FIELD(UInt64, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("证书类型名称");
	}
	// 更新人
	DTO_FIELD(String, upDateMan);
	DTO_FIELD_INFO(upDateMan) {
		info->description = ZH_WORDS_GETTER("更新人");
	}
	// 更新时间
	DTO_FIELD(String, upDateDate);
	DTO_FIELD_INFO(upDateDate) {
		info->description = ZH_WORDS_GETTER("更新时间");
	}
	// 执业资格类别标识
	DTO_FIELD(String, pimQualTypeId);
	DTO_FIELD_INFO(pimQualTypeId) {
		info->description = ZH_WORDS_GETTER("执业资格类别标识");
	}
	// 组织标识
	DTO_FIELD(String, ormOrgId);
	DTO_FIELD_INFO(ormOrgId) {
		info->description = ZH_WORDS_GETTER("组织标识");
	}
	// 执业资格类别
	DTO_FIELD(String, professionalType);
	DTO_FIELD_INFO(professionalType) {
		info->description = ZH_WORDS_GETTER("执业资格类别");
	}
	// 专业技术职务
	DTO_FIELD(String, zyjszw);
	DTO_FIELD_INFO(zyjszw) {
		info->description = ZH_WORDS_GETTER("专业技术职务");
	}
	// 级别
	DTO_FIELD(String, quaLevel);
	DTO_FIELD_INFO(quaLevel) {
		info->description = ZH_WORDS_GETTER("级别");
	}
	// 专业
	DTO_FIELD(String, quaMajor);
	DTO_FIELD_INFO(quaMajor) {
		info->description = ZH_WORDS_GETTER("专业");
	}
	// 岗位类型
	DTO_FIELD(String, gwlx);
	DTO_FIELD_INFO(gwlx) {
		info->description = ZH_WORDS_GETTER("岗位类型");
	}
	// 岗位类型
	DTO_FIELD(String, gwType);
	DTO_FIELD_INFO(gwType) {
		info->description = ZH_WORDS_GETTER("岗位类型");
	}
	// 岗位类型
	DTO_FIELD(String, gwzs);
	DTO_FIELD_INFO(gwzs) {
		info->description = ZH_WORDS_GETTER("岗位类型");
	}

};

/**
 * 执(职)业资格证书下拉列表分页查询DTO
 */
class ProfCertsPageDTO : public ListDTO<ProfCertsDTO::Wrapper>
{
	DTO_INIT(ProfCertsPageDTO, ListDTO<ProfCertsDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_PROFCERTS_DTO_