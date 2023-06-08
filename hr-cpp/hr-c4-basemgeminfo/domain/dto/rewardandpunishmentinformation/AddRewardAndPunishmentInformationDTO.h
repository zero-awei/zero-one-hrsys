#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: arui
 @Date: 2023/05/25 15:07:05

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
#ifndef _ADDREWARDANDPUNISHMENTINFORMATIONDTO_H_
#define _ADDREWARDANDPUNISHMENTINFORMATIONDTO_H_

#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddRewardAndPunishmentInformationDTO : public oatpp::DTO
{
	DTO_INIT(AddRewardAndPunishmentInformationDTO, DTO);
	//奖惩分类
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

	//员工pimpersonid
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.pimpersionid");
	}

	//pimrewardpunishmentid
	DTO_FIELD(String, pimrewardpunishmentid);
	DTO_FIELD_INFO(pimrewardpunishmentid) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.pimrewardpunishmentid");
	}

	//updateman
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.updateman");
	}

	//createman
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.createman");
	}

	//createdate
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.createdate");
	}

	//updatedate
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.updatedate");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDREWARDANDPUNISHMENTINFORMATIONDTO_H_