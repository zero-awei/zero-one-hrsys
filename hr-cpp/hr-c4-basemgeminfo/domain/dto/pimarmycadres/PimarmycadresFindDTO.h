#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _PIMARMYCADRES_DTO_
#define _PIMARMYCADRES_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 军转干部信息传输对象
 */
class PimarmycadresFindDTO : public oatpp::DTO
{
	DTO_INIT(PimarmycadresFindDTO, DTO);

	//员工编号
	DTO_FIELD(String, pimid);
	DTO_FIELD_INFO(pimid) {
		info->description = ZH_WORDS_GETTER("pimarmycadres.field.pimid");
	}
	// 类型
	DTO_FIELD(String, form);
	DTO_FIELD_INFO(form) {
		info->description = ZH_WORDS_GETTER("pimarmycadres.field.type");
	}
	// 级别
	DTO_FIELD(String, level);
	DTO_FIELD_INFO(level) {
		info->description = ZH_WORDS_GETTER("pimarmycadres.field.level");
	}
	// 发生时间
	DTO_FIELD(String, occurtime);
	DTO_FIELD_INFO(occurtime) {
		info->description = ZH_WORDS_GETTER("pimarmycadres.field.occurtime");
	}

	// 附件路径
	DTO_FIELD(String, annexPath);
	DTO_FIELD_INFO(annexPath) {
		info->description = ZH_WORDS_GETTER("pimarmycadres.field.annexPath");
	}
};

/**
 * 军转干部分页传输对象
 */
class PimarmycadresFindPageDTO : public PageDTO<PimarmycadresFindDTO::Wrapper>
{
	DTO_INIT(PimarmycadresFindPageDTO, PageDTO<PimarmycadresFindDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_