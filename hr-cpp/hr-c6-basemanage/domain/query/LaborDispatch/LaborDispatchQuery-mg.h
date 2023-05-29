/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/19 23:24:57

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
#ifndef _LB_M_QUERY_
#define _LB_M_QUERY
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class LaborDispatchMQuery : public PageQuery
{
	DTO_INIT(LaborDispatchMQuery, PageQuery);
	/**
	 * ¹«Ë¾ID
	 */
	DTO_FIELD(String, corporateID);
	DTO_FIELD_INFO(corporateID) {
		info->description = ZH_WORDS_GETTER("labordispatch_mug.field.PIMLABOURCAMPANYID");
	}

};


#include OATPP_CODEGEN_END(DTO)
#endif // !_LB_M_QUERY_
