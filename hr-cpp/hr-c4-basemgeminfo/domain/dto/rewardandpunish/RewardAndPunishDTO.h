#pragma once
#ifndef _REWARDANDPUNISHDTO_H_
#define _REWARDANDPUNISHDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class RewardAndPunishDTO : public oatpp::DTO {
	DTO_INIT(RewardAndPunishDTO, DTO);

	//建立时间
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.createdate");
	}

	//更新时间
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.updatedate");
	}

	//奖惩名称
	DTO_FIELD(String, pimrewardpunishmentname);
	DTO_FIELD_INFO(pimrewardpunishmentname) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.pimrewardpunishmentname");
	}

	//更新人
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.updateman");
	}

	//建立人
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.createman");
	}

	//奖惩级别
	DTO_FIELD(String, jcjb);
	DTO_FIELD_INFO(jcjb) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jcjb");
	}

	//奖惩时间
	DTO_FIELD(String, jclx);
	DTO_FIELD_INFO(jclx) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jclx");
	}

	//备注
	DTO_FIELD(String, bz);
	DTO_FIELD_INFO(bz) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.bz");
	}

	//授予单位
	DTO_FIELD(String, department);
	DTO_FIELD_INFO(department) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.department");
	}

};


#include OATPP_CODEGEN_END(DTO)
#endif