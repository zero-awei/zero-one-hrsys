#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanchen
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
#ifndef _AWARDLEVELDTO_H_
#define _AWARDLEVELDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 测试功能传输数据类型
 */
class AwardLevelDTO : public oatpp::DTO
{
public:
	AwardLevelDTO() {};
	AwardLevelDTO(String id, String level,String createTime,String name,String pcmAwardName,String updataName,String updataTime,
		String awardName,String awardCription,String awardTime,String prmID,String judGeorp,String bbSj,String flag) :
		id(id), level(level) , createTime(createTime), name(name), pcmAwardName(pcmAwardName), updataName(updataName), updataTime(updataTime),
		awardName(awardName) , awardCription(awardCription), awardTime(awardTime), prmID(prmID), judGeorp(judGeorp), bbSj(bbSj), flag(flag)
	{};

	DTO_INIT(AwardLevelDTO, DTO);

	// 获奖情况标识
	DTO_FIELD(String,id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("common.dto.id");
	}
	// 获奖等级
	DTO_FIELD(String, level);
	DTO_FIELD_INFO(level) {
		info->description = ZH_WORDS_GETTER("common.dto.level");
	}
	//创建时间
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.createtime");
	}
	// 建立人
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.name");
	}
	// 获奖情况名称
	DTO_FIELD(String, pcmAwardName);
	DTO_FIELD_INFO(pcmAwardName) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.pcmAwardName");
	}
	//更新人
	DTO_FIELD(String, updataName);
	DTO_FIELD_INFO(updataName) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.updataName");
	}
	//更新时间
	DTO_FIELD(String, updataTime);
	DTO_FIELD_INFO(updataTime) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.uptime");
	}
	// 获奖名称
	DTO_FIELD(String, awardName);
	DTO_FIELD_INFO(awardName) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.awardName");
	}
	// 获奖情况
	DTO_FIELD(String, awardCription);
	DTO_FIELD_INFO(awardCription) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.awardCription");
	}
	// 获奖时间
	DTO_FIELD(String, awardTime);
	DTO_FIELD_INFO(awardTime) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.awardTime");
	}
	//应聘者ID
	DTO_FIELD(String, prmID);
	DTO_FIELD_INFO(prmID) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.prmID");
	}
	//评定机构
	DTO_FIELD(String, judGeorp);
	DTO_FIELD_INFO(judGeorp) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.judGeorp");
	}
	//版本时间
	DTO_FIELD(String, bbSj);
	DTO_FIELD_INFO(bbSj) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.bbSj");
	}
	//是否有效
	DTO_FIELD(String, flag);
	DTO_FIELD_INFO(flag) {
		info->description = ZH_WORDS_GETTER("ormanage.dto.flag");
	}
};

/**
 * 测试功能分页传输数据类型
 */
class AwardLevelPageDTO : public PageDTO<AwardLevelDTO::Wrapper>
{
	DTO_INIT(AwardLevelPageDTO, PageDTO<AwardLevelDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTDTO_H_