#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 18:30:22

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
#ifndef _POSTDETAIL_VO_
#define _POSTDETAIL_VO_

#include "../../GlobalInclude.h"
#include "../../dto/postSet/PostDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示指定岗位详情JsonVO，用于响应给客户端的Json对象
 */
class PostDetailJsonVO : public JsonVO<PostDetailDTO::Wrapper> {
	DTO_INIT(PostDetailJsonVO, JsonVO<PostDetailDTO::Wrapper>);
};

/**
 * 分页显示指定岗位详情JsonVO，用于响应给客户端的Json对象
 */
class PostDetailPageJsonVO : public JsonVO<PostDetailPageDTO::Wrapper> {
	DTO_INIT(PostDetailPageJsonVO, JsonVO<PostDetailPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_POSTDETAIL_VO_