#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/24 19:36:34

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
#ifndef _ORGLISTDTO_H_
#define _ORGLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 组织列表DTO领域模型
 * 负责人：Andrew
 */
class OrgListDTO : public oatpp::DTO
{
	DTO_INIT(OrgListDTO, DTO);
	// 组织ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 组织名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {

	}
	// 建立时间
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 建立人
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 更新时间
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 更新人
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 组织编码
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 组织简称
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 组织排序编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 组织类型
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 组织类型释义
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 组织所属OU的组织ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 所属区域
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 补贴标准
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 上级组织ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 岗位
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
	// 上机部门ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {

	}
};

class OrgListPageDTO : public PageDTO<OrgListDTO::Wrapper>
{
	DTO_INIT(OrgListPageDTO, PageDTO<OrgListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORGLISTDTO_H_