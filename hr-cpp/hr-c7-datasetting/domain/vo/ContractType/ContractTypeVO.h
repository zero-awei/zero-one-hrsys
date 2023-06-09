#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/20 20:45:30

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
#ifndef _CONTRACTTYPEVO_H_
#define _CONTRACTTYPEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/ContractType/ContractTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 合同类型显示JsonVO
 */
class ContractTypeJsonVO : public JsonVO<ContractTypeDTO::Wrapper>
{
	DTO_INIT(ContractTypeJsonVO, JsonVO<ContractTypeDTO::Wrapper>);
};

/**
 * 合同类型分页显示JsonVO
 */
class ContractTypePageJsonVO : public JsonVO<ContractTypePageDTO::Wrapper>
{
	DTO_INIT(ContractTypePageJsonVO, JsonVO<ContractTypePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTTYPEVO_H_