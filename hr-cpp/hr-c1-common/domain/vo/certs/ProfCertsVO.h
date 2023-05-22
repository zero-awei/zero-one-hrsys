#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 15:27:04

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
#ifndef _PROFCERTS_VO_
#define _PROFCERTS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/certs/ProfCertsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 执(职)业资格证书下拉列表查询JsonVO，用于响应给客户端的Json对象
 */
class ProfCertsJsonVO : public JsonVO<ProfCertsDTO::Wrapper> {
	DTO_INIT(ProfCertsJsonVO, JsonVO<ProfCertsDTO::Wrapper>);
};

/**
 *  执(职)业资格证书下拉列表查询分页显示JsonVO，用于响应给客户端的Json对象
 */
class ProfCertsListJsonVO : public JsonVO<ProfCertsListDTO::Wrapper> {
	DTO_INIT(ProfCertsListJsonVO, JsonVO<ProfCertsListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROFCERTS_VO_