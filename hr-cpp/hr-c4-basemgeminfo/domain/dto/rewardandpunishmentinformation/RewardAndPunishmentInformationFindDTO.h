#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: arui
 @Date: 2023/05/24 18:18:05

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
#ifndef _REWARDANDPUNISHMENTINFORMATIONFINDDTO_H_
#define _REWARDANDPUNISHMENTINFORMATIONFINDDTO_H_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class RewardAndPunishmentInformationFindDTO : public oatpp::DTO
{
public:
	RewardAndPunishmentInformationFindDTO() = default;
	RewardAndPunishmentInformationFindDTO(String lx, String pimrewardpunishmentname, String jcjb, Float64 jcje, String jlsj, String jcsj, String bz, String fj) : lx(lx),\
		pimrewardpunishmentname(pimrewardpunishmentname), jcjb(jcjb), jcje(jcje), jlsj(jlsj), jcsj(jcsj), bz(bz),fj(fj){}
	DTO_INIT(RewardAndPunishmentInformationFindDTO, DTO);
	DTO_FIELD(String, lx);
	DTO_FIELD_INFO(lx) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.lx");
	}

	//奖惩名称
	DTO_FIELD(String, pimrewardpunishmentname);
	DTO_FIELD_INFO(pimrewardpunishmentname) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.pimrewardpunishmentname");
	}

	//奖惩级别
	DTO_FIELD(String, jcjb);
	DTO_FIELD_INFO(jcjb) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.jcjb");
	}

	//奖惩金额
	DTO_FIELD(Float64, jcje);
	DTO_FIELD_INFO(jcje) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.jcje");
	}

	//奖惩时间
	DTO_FIELD(String, jlsj);
	DTO_FIELD_INFO(jlsj) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.jlsj");
	}

	//奖惩事件
	DTO_FIELD(String, jcsj);
	DTO_FIELD_INFO(jcsj) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.jcsj");
	}

	//备注
	DTO_FIELD(String, bz);
	DTO_FIELD_INFO(bz) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.bz");
	}

	//附件
	DTO_FIELD(String, fj);
	DTO_FIELD_INFO(fj) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.fj");
	}
	//人员信息id
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.pimpersionid");
	}
	
};
class RewardAndPunishmentInformationFindDTO : public PageDTO<RewardAndPunishmentInformationFindDTO::Wrapper>
{
	DTO_INIT(RewardAndPunishmentInformationFindDTO, PageDTO<RewardAndPunishmentInformationFindDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REWARDANDPUNISHMENTINFORMATIONFINDDTO_H_