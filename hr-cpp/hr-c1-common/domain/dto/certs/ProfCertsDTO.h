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
	// 执业资格
	DTO_FIELD(String, pimQualMajorName);
	// 建立人
	DTO_FIELD(String, createMan);
	// 建立时间
	DTO_FIELD(String, createDate);
	// ENABLE
	DTO_FIELD(UInt64, enable);
	// 更新人
	DTO_FIELD(String, upDateMan);
	// 更新时间
	DTO_FIELD(String, upDateDate);
	// 执业资格类别标识
	DTO_FIELD(String, pimQualTypeId);
	// 组织标识
	DTO_FIELD(String, ormOrgId);
	// 执业资格类别
	DTO_FIELD(String, professionalType);
	// 专业技术职务
	DTO_FIELD(String, zyjszw);
	// 级别
	DTO_FIELD(String, quaLevel);
	// 专业
	DTO_FIELD(String, quaMajor);
	// 岗位类型
	DTO_FIELD(String, gwlx);
	// 岗位类型
	DTO_FIELD(String, gwType);
	// 岗位类型
	DTO_FIELD(String, gwzs);

};

/**
 * 执(职)业资格证书下拉列表分页查询DTO
 */
class ProfCertsPageDTO : public PageDTO<ProfCertsDTO::Wrapper>
{
	DTO_INIT(ProfCertsPageDTO, PageDTO<ProfCertsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_