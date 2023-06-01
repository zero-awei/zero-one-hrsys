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
class ContractTypeDTO : public oatpp::DTO
{
	DTO_INIT(ContractTypeDTO, DTO);
	// 合同类别名称
	DTO_FIELD(String, htlxname);
	DTO_FIELD_INFO(htlxname) {
		info->description = ZH_WORDS_GETTER("common.dto.htlxname");
	}
	// 合同类别编号
	DTO_FIELD(String, htlxid);
	DTO_FIELD_INFO(htlxid) {
		info->description = ZH_WORDS_GETTER("common.dto.htlxid");
	}

public:
	ContractTypeDTO()
	{
		htlxid = "";
		htlxname = "";
	}

	ContractTypeDTO(String code, String name)
	{
		htlxid = code;
		htlxname = name;
	}
};

class ContractTypeListDTO : public oatpp::DTO
{
	DTO_INIT(ContractTypeListDTO, DTO);
	DTO_FIELD_INFO(pullList) {
		info->description = ZH_WORDS_GETTER("common.dto.htlxList");
	}
	DTO_FIELD(List<ContractTypeDTO::Wrapper>, pullList) = {};
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_HTLX_DTO_