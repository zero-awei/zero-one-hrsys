#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/15 20:13:26

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
#ifndef _MILITARYDTO_H_
#define _MILITARYDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class MilitaryDTO : public oatpp::DTO
{
	DTO_INIT(MilitaryDTO, DTO);
	
	// 更新时间
	DTO_FIELD(String, UPDATEDATE);
	DTO_FIELD_INFO(UPDATEDATE) {
		info->description = ZH_WORDS_GETTER("military.UPDATEDATE");
	}
	// 军转干部名称
	DTO_FIELD(String, PIMARMYCADRESNAME);
	DTO_FIELD_INFO(PIMARMYCADRESNAME) {
		info->description = ZH_WORDS_GETTER("military.PIMARMYCADRESNAME");
	}
	// 附件
	DTO_FIELD(String, FJ);
	DTO_FIELD_INFO(FJ) {
		info->description = ZH_WORDS_GETTER("military.FJ");
	}
	// 建立时间
	DTO_FIELD(String, CREATEDATE);
	DTO_FIELD_INFO(CREATEDATE) {
		info->description = ZH_WORDS_GETTER("military.CREATEDATE");
	}
	// 更新人
	DTO_FIELD(String, UPDATEMAN);
	DTO_FIELD_INFO(UPDATEMAN) {
		info->description = ZH_WORDS_GETTER("military.UPDATEMAN");
	}
	// ENABLE
	DTO_FIELD(String, ENABLE);
	DTO_FIELD_INFO(ENABLE) {
		info->description = ZH_WORDS_GETTER("military.ENABLE");
	}
	// 军转干部标识
	DTO_FIELD(String, PIMARMYCADRESID);
	DTO_FIELD_INFO(PIMARMYCADRESID) {
		info->description = ZH_WORDS_GETTER("military.PIMARMYCADRESID");
	}
	// 建立人
	DTO_FIELD(String, CREATEMAN);
	DTO_FIELD_INFO(CREATEMAN) {
		info->description = ZH_WORDS_GETTER("military.CREATEMAN");
	}
	// 人员信息标识
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("military.PIMPERSONID");
	}
	// 发生时间
	DTO_FIELD(String, FSSJ);
	DTO_FIELD_INFO(FSSJ) {
		info->description = ZH_WORDS_GETTER("military.FSSJ");
	}
	// 记录所属
	DTO_FIELD(String, JLSS);
	DTO_FIELD_INFO(JLSS) {
		info->description = ZH_WORDS_GETTER("military.JLSS");
	}
	// 审批状态
	DTO_FIELD(String, JLSPZT);
	DTO_FIELD_INFO(JLSPZT) {
		info->description = ZH_WORDS_GETTER("military.JLSPZT");
	}
	// 记录管理编号
	DTO_FIELD(String, JLGLBH);
	DTO_FIELD_INFO(JLGLBH) {
		info->description = ZH_WORDS_GETTER("military.JLGLBH");
	}
	// 记录操作者
	DTO_FIELD(String, JLCZZ);
	DTO_FIELD_INFO(JLCZZ) {
		info->description = ZH_WORDS_GETTER("military.JLCZZ");
	}
	// 类型
	DTO_FIELD(String, TROOPTYPE);
	DTO_FIELD_INFO(TROOPTYPE) {
		info->description = ZH_WORDS_GETTER("military.TROOPTYPE");
	}
	// 级别
	DTO_FIELD(String, LEVELTYPE);
	DTO_FIELD_INFO(LEVELTYPE) {
		info->description = ZH_WORDS_GETTER("military.LEVELTYPE");
	}
	// 拒绝原因
	DTO_FIELD(String, REASON);
	DTO_FIELD_INFO(REASON) {
		info->description = ZH_WORDS_GETTER("military.REASON");
	}
};

class MilitaryPageDTO : public PageDTO<MilitaryDTO::Wrapper>
{
	DTO_INIT(MilitaryPageDTO, PageDTO<MilitaryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MILITARYDTO_H_