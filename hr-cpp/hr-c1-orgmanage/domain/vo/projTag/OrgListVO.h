#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/24 19:35:39

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
#ifndef _ORGLISTVO_H_
#define _ORGLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/projTag/OrgListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 组织列表VO领域模型
 * 负责人：Andrew
 */
class OrgListVO : public JsonVO<OrgListPageDTO::Wrapper>
{
	DTO_INIT(OrgListVO, JsonVO<OrgListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORGLISTVO_H_