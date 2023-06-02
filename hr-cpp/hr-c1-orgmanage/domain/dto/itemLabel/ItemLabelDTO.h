#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/13 19:52:05

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
#ifndef _ITEMLABELDTO_H_
#define _ITEMLABELDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 测试功能传输数据类型
 */
class ItemLabelDTO : public oatpp::DTO
{
	DTO_INIT(ItemLabelDTO, DTO);

	// 更新人
	DTO_FIELD(String, updataman);
	DTO_FIELD_INFO(updataman) {
		info->description = ZH_WORDS_GETTER("projTag.field.updateman");
	}
	// 创建人
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.name");
	}
	//项目标签标识
	DTO_FIELD(String, ormxbqId);
	DTO_FIELD_INFO(ormxbqId) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.ormxbqid");
	}
	//创建时间
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.createtime");
	}
	//更新时间
	DTO_FIELD(String, updataTime);
	DTO_FIELD_INFO(updataTime) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.uptime");
	}
	// 项目标签
	DTO_FIELD(String, itemLabel);
	DTO_FIELD_INFO(itemLabel) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.label");
	}
	//组织ID
	DTO_FIELD(String, ormorgId);
	DTO_FIELD_INFO(ormorgId) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.ormorgid");
	}
public:
	ItemLabelDTO() {};
	ItemLabelDTO(String updataman, String itemLabel, String name, String  ormxbqId, String createTime, String updataTime, String ormorgId) :
		updataman(updataman), name(name), ormxbqId(ormxbqId), createTime(createTime), updataTime(updataTime), itemLabel(itemLabel), ormorgId(ormorgId) {};


};

/**
 * 测试功能分页传输数据类型
 */
class ItemLabelPageDTO : public PageDTO<ItemLabelDTO::Wrapper>
{
	DTO_INIT(ItemLabelPageDTO, PageDTO<ItemLabelDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTDTO_H_