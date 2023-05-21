#pragma once
#include "../../GlobalInclude.h"
#include "../../dto/LaborDispatch/LaborDispatchDTO.h"

/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/15 15:56:56

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
#ifndef _LABORDISPATCHVO_H_
#define _LABORDISPATCHVO_H_


#include OATPP_CODEGEN_BEGIN(DTO)

class LaborDispatchJsonVO : public JsonVO<LaborDispatchDTO::Wrapper>
{
	DTO_INIT(LaborDispatchJsonVO, JsonVO< LaborDispatchDTO::Wrapper>);
};

// 分页显示JsonVO，用于响应给客户端的Json对象
class LaborDispatchPageJsonVO : public JsonVO<LaborDispatchPageDTO::Wrapper>
{
	DTO_INIT(LaborDispatchPageJsonVO, JsonVO< LaborDispatchPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LABORDISPATCHVO_H_