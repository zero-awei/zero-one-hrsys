#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/5/22 14:58:43

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
#ifndef _Assign_Info_Query_Detail_VO_
#define _Assign_Info_Query_Detail_VO_

#include "../../GlobalInclude.h"
#include "../../query/assignInfo/AssignInfoQueryDetail.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class AssignInfoQueryDetailJsonVO : public JsonVO<AssignInfoQueryDetail::Wrapper> {
	DTO_INIT(AssignInfoQueryDetailJsonVO, JsonVO<AssignInfoQueryDetail::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_Assign_Info_Query_Detail_VO_