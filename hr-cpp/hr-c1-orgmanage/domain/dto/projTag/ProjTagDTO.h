#pragma once
 /*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/19 15:02:24

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
#ifndef _PROJTAGDTO_H_
#define _PROJTAGDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 项目标签信息
 * 负责人：远翔
 */
class ProjTagDTO : public oatpp::DTO
{
	DTO_INIT(ProjTagDTO, DTO);
	
	// 项目标签标识
	DTO_FIELD(String, ormxmbqid);
	DTO_FIELD_INFO(ormxmbqid) {
		info->description = ZH_WORDS_GETTER("projTag.field.ormxmbqid");
	}
	
	// 建立人
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("projTag.filed.createman");
	}

	// 项目标签
	DTO_FIELD(String, ormxmbqname);
	DTO_FIELD_INFO(ormxmbqname) {
		info->description = ZH_WORDS_GETTER("projTag.filed.ormxmbqname");
	}

	// 更新人
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("projTag.filed.updateman");
	}

	// 建立时间
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("projTag.filed.createtime");
	}

	// 更新时间
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("projTag.filed.updatetime");
	}

	// 组织id
	DTO_FIELD(String, ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("projTag.filed.ormorgid");
	}
public:
	ProjTagDTO() {
		ormxmbqid = "";
	}
	ProjTagDTO(string id) {
		ormxmbqid = id;
	}

};
class ProjTagPageDTO : public PageDTO<ProjTagDTO::Wrapper>
{
	DTO_INIT(ProjTagPageDTO, PageDTO<ProjTagDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_PROJTAGDTO_H_