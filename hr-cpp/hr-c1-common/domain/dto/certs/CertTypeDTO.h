#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/23 17:58:22

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
#ifndef _CERTTYPE_DTO_
#define _CERTTYPE_DTO_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 证书类型下拉列表查询DTO
 */
class CertTypeDTO : public oatpp::DTO
{
	DTO_INIT(CertTypeDTO, DTO);

	// 证书类型ID
	DTO_FIELD(String, certTypeId);
	DTO_FIELD_INFO(certTypeId) {
		info->description = ZH_WORDS_GETTER("common.dto.certTypeId");
	}
	// 证书类型名称
	DTO_FIELD(String, certTypeName);
	DTO_FIELD_INFO(certTypeName) {
		info->description = ZH_WORDS_GETTER("common.dto.certTypeName");
	}
	// 证书类型代号
	DTO_FIELD(String, certTypeCode);
	DTO_FIELD_INFO(certTypeCode) {
		info->description = ZH_WORDS_GETTER("common.dto.certTypeCode");
	}
	// 证书类型是否有效 (0无效, 1有效)
	DTO_FIELD(Boolean, certTypeValidity);
	DTO_FIELD_INFO(certTypeValidity) {
		info->description = ZH_WORDS_GETTER("common.dto.certTypeValidity");
	}
	CertTypeDTO()
	{
		certTypeId = "1";
		certTypeName = u8"执（职）业资格证书";
		certTypeCode = "10";
		certTypeValidity = 1;
	}
};

/**
 * 证书类型下拉列表分页查询DTO
 */
class CertTypeListDTO : public PageDTO<CertTypeDTO::Wrapper>
{
	DTO_INIT(CertTypeListDTO, PageDTO<CertTypeDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_CERTTYPE_DTO_