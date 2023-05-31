#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/30 23:15:33

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
#ifndef _LEGALENTITYSETQUERYDTO_H_
#define _LEGALENTITYSETQUERYDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* 法人主体设置数据传输对象定义--（组织管理-数据设置-法人主体设置）--TripleGold */
class LegalEntitySetQueryDTO : public oatpp::DTO
{
public:
	LegalEntitySetQueryDTO() {};
	LegalEntitySetQueryDTO(String name, String LEMName, String Defa) : ORGNAME(name), ORMSIGNORGNAME(LEMName), ISDEFAULTSIGNORG(Defa) {};
	DTO_INIT(LegalEntitySetQueryDTO, DTO);
	// 签约主体单位标识
	DTO_FIELD(String, CONTRACTSIGNORGID);
	DTO_FIELD_INFO(CONTRACTSIGNORGID) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.id");
	}
	// 法人主体名称t_srforg（管理单位名称）
	DTO_FIELD(String, ORGNAME);
	DTO_FIELD_INFO(ORGNAME) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.name");
	}
	// 法人主体名称t_ormsignorg
	DTO_FIELD(String, ORMSIGNORGNAME);
	DTO_FIELD_INFO(ORMSIGNORGNAME) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
	}
	// 默认签约名称
	DTO_FIELD(String, ISDEFAULTSIGNORG);
	DTO_FIELD_INFO(ISDEFAULTSIGNORG) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.default");
	}
};

class LegalEntitySetPageDTO : public PageDTO<LegalEntitySetQueryDTO::Wrapper>
{
	DTO_INIT(LegalEntitySetPageDTO, PageDTO<LegalEntitySetQueryDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYSETQUERYDTO_H_