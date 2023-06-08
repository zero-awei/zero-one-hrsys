#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2023/05/24 17:58:45

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
#ifndef _DELETEPROJTAGBATCHVO_H_
#define _DELETEPROJTAGBATCHVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/projTag/DeleteProjTagDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 批量删除项目标签信息
 * 负责人：咫尺之书
 */
class DeleteProjTagBatchVO : public JsonVO<DeleteProjTagBatchDTO::Wrapper> {
	DTO_INIT(DeleteProjTagBatchVO, JsonVO<DeleteProjTagBatchDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETEPROJTAGBATCHVO_H_