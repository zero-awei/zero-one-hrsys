#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 15:50:22

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
#ifndef _CERTTYPE_VO_
#define _CERTTYPE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/certs/CertTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 证书类型下拉列表查询JsonVO，用于响应给客户端的Json对象
 */
class CertTypeVO : public JsonVO<CertTypeDTO::Wrapper> {
	DTO_INIT(CertTypeVO, JsonVO<CertTypeDTO::Wrapper>);
};

/**
 *  证书类型下拉列表查询分页显示JsonVO，用于响应给客户端的Json对象
 */
class CertTypePageJsonVO : public JsonVO<CertTypePageDTO::Wrapper> {
	DTO_INIT(CertTypePageJsonVO, JsonVO<CertTypePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_