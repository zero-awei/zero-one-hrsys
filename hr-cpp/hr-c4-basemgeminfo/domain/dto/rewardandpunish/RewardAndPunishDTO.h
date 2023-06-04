#pragma once
#ifndef _REWARDANDPUNISHDTO_H_
#define _REWARDANDPUNISHDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class RewardAndPunishDTO : public oatpp::DTO {
	DTO_INIT(RewardAndPunishDTO, DTO);

	//建立时间
	DTO_FIELD(String, CREATEDATE);
	DTO_FIELD_INFO(CREATEDATE) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.createdate");
	}

	//更新时间
	DTO_FIELD(String, UPDATEDATE);
	DTO_FIELD_INFO(UPDATEDATE) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.updatedate");
	}

	//奖惩名称
	DTO_FIELD(String, PIMREWARDPUNISHMENTNAME);
	DTO_FIELD_INFO(PIMREWARDPUNISHMENTNAME) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.pimrewardpunishmentname");
	}

	//更新人
	DTO_FIELD(String, UPDATEMAN);
	DTO_FIELD_INFO(UPDATEMAN) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.updateman");
	}

	//建立人
	DTO_FIELD(String, CREATEMAN);
	DTO_FIELD_INFO(CREATEMAN) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.createman");
	}

	//可行
	DTO_FIELD(String, ENABLE);
	DTO_FIELD_INFO(ENABLE) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.enable");
	}

	//附件
	DTO_FIELD(String, FJ);
	DTO_FIELD_INFO(FJ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.fj");
	}

	//奖惩分类
	DTO_FIELD(String, LX);
	DTO_FIELD_INFO(LX) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.lx");
	}

	//产生日期
	DTO_FIELD(String, CSRQ);
	DTO_FIELD_INFO(CSRQ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.csrq");
	}

	// 奖惩惩罚标识（主键）
	DTO_FIELD(String, PIMREWARDPUNISHMENTID);
	DTO_FIELD_INFO(PIMREWARDPUNISHMENTID) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.pimrewardpunishmentid");
	}

	// 人员信息标识
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.pimpersonid");
	}

	//奖惩级别
	DTO_FIELD(String, JCJB);
	DTO_FIELD_INFO(JCJB) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jcjb");
	}

	//奖惩级别
	DTO_FIELD(String, JCLX);
	DTO_FIELD_INFO(JCLX) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jclx");
	}

	//奖励时间
	DTO_FIELD(String, JLSJ);
	DTO_FIELD_INFO(JLSJ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jlsj");
	}

	//惩罚时间
	DTO_FIELD(String, CFSJ);
	DTO_FIELD_INFO(CFSJ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.cfsj");
	}

	//奖惩金额
	DTO_FIELD(String, JCJE);
	DTO_FIELD_INFO(JCJE) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jcje");
	}

	//奖惩事件
	DTO_FIELD(String, JCSJ);
	DTO_FIELD_INFO(JCSJ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jcsj");
	}

	//备注
	DTO_FIELD(String, BZ);
	DTO_FIELD_INFO(BZ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.bz");
	}

	//惩罚类型
	DTO_FIELD(String, CFLX);
	DTO_FIELD_INFO(CFLX) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.cflx");
	}

	//记录所属
	DTO_FIELD(String, JLSS);
	DTO_FIELD_INFO(JLSS) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jlss");
	}

	//记录管理编号
	DTO_FIELD(String, JLGLBH);
	DTO_FIELD_INFO(JLGLBH) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jlglbh");
	}

	//记录审批状态
	DTO_FIELD(String, JLSPZT);
	DTO_FIELD_INFO(JLSPZT) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jlspzt");
	}

	//记录操作者
	DTO_FIELD(String, JLCZZ);
	DTO_FIELD_INFO(JLCZZ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jlczz");
	}

	//影响期结束日期
	DTO_FIELD(String, YXQJSRQ);
	DTO_FIELD_INFO(YXQJSRQ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.yxqjsrq");
	}

	//授予单位
	DTO_FIELD(String, DEPARTMENT);
	DTO_FIELD_INFO(DEPARTMENT) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.department");
	}

	//拒绝原因
	DTO_FIELD(String, REASON);
	DTO_FIELD_INFO(REASON) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.reason");
	}

};

/**
 * 示例分页传输对象
 */
class RewardAndPunishPageDTO : public PageDTO<RewardAndPunishDTO::Wrapper>
{
	DTO_INIT(RewardAndPunishPageDTO, PageDTO<RewardAndPunishDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif