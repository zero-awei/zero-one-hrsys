#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/20 22:07:04

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
#ifndef _HTLX_DTO_
#define _HTLX_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个合同类别下拉列表修改的数据传输模型
 */
class TypeContractDTO : public oatpp::DTO
{
	DTO_INIT(TypeContractDTO, DTO);
	// 合同类别名称
	DTO_FIELD(String, htlxname);
	DTO_FIELD_INFO(htlxname) {
		info->description = ZH_WORDS_GETTER("htlx.field.htlxname");
	}
};

class TypeContractListDTO : public oatpp::DTO
{
	DTO_INIT(TypeContractListDTO, DTO);
	// 合同类别名称
	DTO_FIELD(List<TypeContractDTO::Wrapper>, htlxList) = {};
	DTO_FIELD_INFO(htlxList) {
		info->description = ZH_WORDS_GETTER("htlx.field.htlxList");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_HTLX_DTO_