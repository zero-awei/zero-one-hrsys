#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 唐茂伦
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
#ifndef _PIMPAPER_DTO_
#define _PIMPAPER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class PimpaperDTO : public oatpp::DTO
{
public:
	PimpaperDTO() {}
	PimpaperDTO(String ygbh, String pimpersonname) : ygbh(ygbh), pimpersonname(pimpersonname) {}

	DTO_INIT(PimpaperDTO, DTO);
	
	//员工姓名
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("pimpaper.field.pimpersonname");
	}

	//员工编号
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("pimpaper.field.ygbh");
	}

	//证件号码
	DTO_FIELD(String, zjhm);
	DTO_FIELD_INFO(zjhm) {
		info->description = ZH_WORDS_GETTER("pimpaper.field.zjhm");
	}

	//组织
	DTO_FIELD(String, zzdzs);
	DTO_FIELD_INFO(zzdzs) {
		info->description = ZH_WORDS_GETTER("pimpaper.field.zzdzs");
	}

	//部门
	DTO_FIELD(String, ormorgsectorname);
	DTO_FIELD_INFO(ormorgsectorname) {
		info->description = ZH_WORDS_GETTER("pimpaper.field.ormorgsectorname");
	}

	//员工状态
	DTO_FIELD(String, ygzt);
	DTO_FIELD_INFO(ygzt) {
		info->description = ZH_WORDS_GETTER("pimpaper.field.ygzt");
	}

	//在岗状态
	DTO_FIELD(String, zgzt);
	DTO_FIELD_INFO(zgzt) {
		info->description = ZH_WORDS_GETTER("pimpaper.field.zgzt");
	}
};

/**
 * 分页传输对象
 */
class PimpaperPageDTO : public PageDTO<PimpaperDTO::Wrapper>
{
	DTO_INIT(PimpaperPageDTO, PageDTO<PimpaperDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PIMPAPER_DTO_