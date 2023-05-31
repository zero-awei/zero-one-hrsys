#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/30 23:32:39

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
#ifndef _LEGALENTITYSETVO_H_
#define _LEGALENTITYSETVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/LegalEntitySet/LegalEntitySetQueryDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* 法人主体设置VO对象定义--（组织管理-数据设置-法人主体设置）--TripleGold */
/* 定义一个用户信息显示JsonVO对象，用于响应给客户端 */
class LegalEntitySetQueryJsonVO : public JsonVO<LegalEntitySetQueryDTO::Wrapper>
{
	DTO_INIT(LegalEntitySetQueryJsonVO, JsonVO<LegalEntitySetQueryDTO::Wrapper>);
};

/* 定义一个用户信息分页显示JsonVO对象，用于响应给客户端 */
class LegalEntitySetQueryPageJsonVO : public JsonVO<LegalEntitySetPageDTO::Wrapper>
{
	DTO_INIT(LegalEntitySetQueryPageJsonVO, JsonVO<LegalEntitySetPageDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYSETVO_H_