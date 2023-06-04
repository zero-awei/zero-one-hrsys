#pragma once
#ifndef _TRAININGRECORDQUERY_H_
#define _TRAININGRECORDQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class TrainingRecordPageQuery : public PageQuery
{
	DTO_INIT(TrainingRecordPageQuery, PageQuery);

	// 培训人员主键标识
	DTO_FIELD(String, trmtrianpersonid);
	DTO_FIELD_INFO(trmtrianpersonid) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trmtrianpersonid");
	}

	// 培训班级
	DTO_FIELD(String, pxbj);
	DTO_FIELD_INFO(pxbj) {
		info->description = ZH_WORDS_GETTER("trainingrecord.pxbj");
	}

	// 培训开始时间
	DTO_FIELD(String, trainbegin);
	DTO_FIELD_INFO(trainbegin) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trainbegin");
	}

	// 培训结束时间
	DTO_FIELD(String, trainend);
	DTO_FIELD_INFO(trainend) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trainend");
	}

	// 培训课程
	DTO_FIELD(String, pxkc);
	DTO_FIELD_INFO(pxkc) {
		info->description = ZH_WORDS_GETTER("trainingrecord.pxkc");
	}

	// 培训机构
	DTO_FIELD(String, trmtrainagencyname);
	DTO_FIELD_INFO(trmtrainagencyname) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trmtrainagencyname");
	}

	// 培训结果
	DTO_FIELD(String, trainres);
	DTO_FIELD_INFO(trainres) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trainres");
	}

	// 分数
	DTO_FIELD(String, fs);
	DTO_FIELD_INFO(fs) {
		info->description = ZH_WORDS_GETTER("trainingrecord.fs");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif