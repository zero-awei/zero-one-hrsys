#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 10:22:22

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
	// 证书类型名称
	DTO_FIELD(String, certType);
	DTO_FIELD_INFO(certType) {
		info->description = ZH_WORDS_GETTER("证书类型名称");
	}

};

/**
 * 证书类型下拉列表分页查询DTO
 */
class CertTypePageDTO : public PageDTO<CertTypeDTO::Wrapper>
{
	DTO_INIT(CertTypePageDTO, PageDTO<CertTypeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CERTTYPE_DTO_