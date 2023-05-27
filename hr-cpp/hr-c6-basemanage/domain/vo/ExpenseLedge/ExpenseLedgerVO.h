/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/27 19:57:51

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
#pragma once
#ifndef _EXPENSELEDGER_VO_
#define _EXPENSELEDGER_VO_
#include "../../GlobalInclude.h"
#include "domain/vo/JsonVO.h"
#include "domain/dto/ExpenseLedger/ExpenseLedgerDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
class ExpenseLedgerJsonVO : public JsonVO<ExpenseLedgerDTO::Wrapper>
{
	DTO_INIT(ExpenseLedgerJsonVO, JsonVO < ExpenseLedgerDTO::Wrapper>);
};

class ExpenseLedgerPageJsonVO : public JsonVO<ExpenseLedgerPageDTO::Wrapper>
{
	DTO_INIT(ExpenseLedgerPageJsonVO, JsonVO < ExpenseLedgerPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif