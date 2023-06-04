#pragma once
#ifndef _TRAININGRECORDDTO_H_
#define _TRAININGRECORDDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class TrainingRecordDTO : public oatpp::DTO {
	DTO_INIT(TrainingRecordDTO, DTO);

	// 培训人员主键标识
	DTO_FIELD(String, TRMTRIANPERSONID);
	DTO_FIELD_INFO(TRMTRIANPERSONID) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trmtrianpersonid");
	}

	// 培训班级
	DTO_FIELD(String, PXBJ);
	DTO_FIELD_INFO(PXBJ) {
		info->description = ZH_WORDS_GETTER("trainingrecord.pxbj");
	}

	// 培训开始时间
	DTO_FIELD(String, TRAINBEGIN);
	DTO_FIELD_INFO(TRAINBEGIN) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trainbegin");
	}

	// 培训结束时间
	DTO_FIELD(String, TRAINEND);
	DTO_FIELD_INFO(TRAINEND) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trainend");
	}

	// 培训课程
	DTO_FIELD(String, PXKC);
	DTO_FIELD_INFO(PXKC) {
		info->description = ZH_WORDS_GETTER("trainingrecord.pxkc");
	}

	// 培训机构
	DTO_FIELD(String, TRMTRAINAGENCYNAME);
	DTO_FIELD_INFO(TRMTRAINAGENCYNAME) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trmtrainagencyname");
	}

	// 培训结果
	DTO_FIELD(String, TRAINRES);
	DTO_FIELD_INFO(TRAINRES) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trainres");
	}

	// 分数
	DTO_FIELD(String, FS);
	DTO_FIELD_INFO(FS) {
		info->description = ZH_WORDS_GETTER("trainingrecord.fs");
	}

};

/**
 * 示例分页传输对象
 */
class TrainingRecordPageDTO : public PageDTO<TrainingRecordDTO::Wrapper>
{
	DTO_INIT(TrainingRecordPageDTO, PageDTO<TrainingRecordDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif