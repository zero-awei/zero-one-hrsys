#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/24 16:54:22

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
#ifndef _POSTDELETEBATCH_VO_
#define _POSTDELETEBATCH_VO_

#include "../../GlobalInclude.h"
#include "../../dto/postSet/PostDeleteDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * É¾³ý¶à¸ö¸ÚÎ»VO
 */
class PostDeleteBatchJsonVO : public JsonVO<PostDeleteBatchDTO::Wrapper> {
	DTO_INIT(PostDeleteBatchJsonVO, JsonVO<PostDeleteBatchDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_POSTDELETEBATCH_VO_