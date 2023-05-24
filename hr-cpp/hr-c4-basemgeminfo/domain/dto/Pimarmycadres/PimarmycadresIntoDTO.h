#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/16 10:12:44

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
#ifndef _PIMAMARCADRESINTODTO_H_
#define _PIMAMARCADRESINTODTO_H_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}


#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PimarmycadresDTO : public oatpp::DTO
{
	DTO_INIT(PimarmycadresDTO, DTO);

	//员工编号
	DTO_FIELD(String, pimid);
	DTO_FIELD_INFO(pimid) {
		info->description = ZH_WORDS_GETTER("pimarmycadres.field.pimid");
	}

	// 类型
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
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


class PimarmycadresIntoDTO : public oatpp::DTO
{
	DTO_INIT(PimarmycadresIntoDTO, DTO);

	//批量增加list
	DTO_FIELD(List<PimarmycadresDTO>, listpimamrycadres) = {};
	DTO_FIELD_INFO(listpimamrycadres) {
		info->description = ZH_WORDS_GETTER("pimarmycadres.field.listpimarmycadres");
	}

	//8人员信息id
	DTO_INIT_(String, pimid, "pimarmycadres.field.pimid")

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKHISTORYINTODTO_H_