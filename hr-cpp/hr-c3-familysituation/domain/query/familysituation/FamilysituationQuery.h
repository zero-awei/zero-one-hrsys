#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Marvin
 @Date: 2023/05/17 19:18:52

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
#ifndef _FAMILYSITUATIONQUERY_H_
#define _FAMILYSITUATIONQUERY_H_


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 员工家庭情况查询对象
 */
class FamilysituationQuery : public PageQuery
{
	DTO_INIT(FamilysituationQuery, PageQuery);
	API_DTO_FIELD_DEFAULT(UInt64, id, "ID");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_FAMILYSITUATIONQUERY_H_